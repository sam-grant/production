#!bin/echo Please source instead

#Setup all the stuff we need here
source /grid/fermiapp/products/common/etc/setups.sh
setup jobsub_client
setup fife_utils

#Make sure file list exists
if [ $# -ne 0 ]; then
  echo "No arguments are allowed. $# was/were supplied."
  return
fi

#Make sure file exists
if [ ! -f FileList.txt ] || [ `cat FileList.txt | wc -l` -eq 0 ]; then
  echo "Input file list \"FileList.txt\" is required.  This was not found or has 0 entries"
  return
fi

# Get run
for file in `head -n 1 FileList.txt`; do
  # Get run number from file
  run=${file##*full_}
  run=${run##*_}
  run=${run%%.*}
done

# Make output directory
pnfsOutDir=/pnfs/GM2/scratch/users/${USER}/TrackingTrees/${run}
if [ ! -d $pnfsOutDir ]; then
  mkdir -p $pnfsOutDir
  chmod -R g+w $pnfsOutDir
fi
echo "Output files will appear in $pnfsOutDir"

# Make sure that there's not already an output file that we'd overwrite
for file in `cat FileList.txt`; do

  # Strip everything before last _, then extract middle of run.subrun.root
  subRun=${file##*_}
  subRun=${subRun%.*}
  subRun=${subRun#*.}

  if [ -f ${pnfsOutDir}/trackRecoTrees_${run}.${subRun}.root ]; then 
    echo "ERROR: ${pnfsOutDir}/trackRecoTrees_${run}.${subRun}.root already exists and would be overwritten."
    return
  fi

done

# Copy fcl & .so file to pnfs so we can get it from grid jobs
if [ -f ${pnfsOutDir}/RunTrackingTrees.fcl ]; then
  rm -f ${pnfsOutDir}/RunTrackingTrees.fcl 
fi
if [ -f ${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so ]; then
  rm -f ${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so 
fi
sleep 5
ifdh cp RunTrackingTrees.fcl ${pnfsOutDir}/RunTrackingTrees.fcl
ifdh cp libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so ${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so
echo "Copied RunTrackingTrees.fcl & libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so to $pnfsOutDir"

# Split into lists with 25 each (and submit one of these each time)
rm -f SplitFileList*
split FileList.txt -l 25 -a 3 -d SplitFileList
for file in `ls SplitFileList*`; do 
  mv $file ${file}.txt
done

# Add xrootd business to the start of file names
for file in `ls SplitFileList*`; do 
  fileNum=${file##SplitFileList}
  fileNum=${fileNum%.txt}
  rm -f xrootdFileList${fileNum}.txt && touch xrootdFileList${fileNum}.txt
  for line in `cat $file`; do
    # Strip /pnfs/ from file name and write into new file
    longFileName=${line#/pnfs/*}
    echo root://fndca1.fnal.gov:1094/pnfs/fnal.gov/usr/${longFileName} >> xrootdFileList${fileNum}.txt
  done
  # Copy filelist, fcl & .so file to pnfs so we can get it from grid jobs
  if [ -f ${pnfsOutDir}/xrootdFileList${fileNum}.txt ]; then
    rm -f ${pnfsOutDir}/xrootdFileList${fileNum}.txt 
  fi
  ifdh cp xrootdFileList${fileNum}.txt ${pnfsOutDir}/xrootdFileList${fileNum}.txt
  echo "Copied xrootdFileList${fileNum} to $pnfsOutDir"

# Make script that we'll want to run on the grid
cat <<EOF > runTrackTreeJob${fileNum}.sh
# Setup stuff to copy files back and forth
source /cvmfs/fermilab.opensciencegrid.org/products/common/etc/setups
source /cvmfs/fermilab.opensciencegrid.org/products/larsoft/setup
setup ifdhc

# Copy xrootdFileList${fileNum} here
if [ ! -z "\`ifdh ls ${pnfsOutDir}/xrootdFileList${fileNum}.txt\`" ]; then
  ifdh cp ${pnfsOutDir}/xrootdFileList${fileNum}.txt xrootdFileList${fileNum}.txt
else 
  echo "${pnfsOutDir}/xrootdFileList${fileNum}.txt does not exist"
fi

#Copy fcl file
if [ ! -z "\`ifdh ls ${pnfsOutDir}/RunTrackingTrees.fcl\`" ]; then
  ifdh cp ${pnfsOutDir}/RunTrackingTrees.fcl ./RunTrackingTrees.fcl
else 
  echo "${pnfsOutDir}/RunTrackingTrees.fcl does not exist"
fi

#Copy .so file
if [ ! -z "\`ifdh ls ${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so\`" ]; then
  ifdh cp ${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so ./libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so
else 
  echo "${pnfsOutDir}/libgm2analyses_strawtracker_TrackNTupBackwardsOnly_module.so does not exist"
fi

#Setup gm2
source /cvmfs/gm2.opensciencegrid.org/prod/g-2/setup
setup gm2 v9_35_00 -q prof

#Add current directory to LD_LIBRARY_PATH for so file we copied
export LD_LIBRARY_PATH=\`pwd\`:\$LD_LIBRARY_PATH

#Run jobs
for file in \`cat xrootdFileList${fileNum}.txt\`; do
  echo "Processing \$file"
  subRun=\${file##*_}
  subRun=\${subRun%.*}
  subRun=\${subRun#*.}

  gm2 -c RunTrackingTrees.fcl -s \$file -T trackRecoTrees_${run}.\${subRun}.root

  # Only copy back if job completed successfully (output from last command was 0)
  if [ \$? -eq 0 ]; then
    if [ -f trackRecoTrees_${run}.\${subRun}.root ]; then
      ifdh mv trackRecoTrees_${run}.\${subRun}.root ${pnfsOutDir}/trackRecoTrees_${run}.\${subRun}.root
    else 
      echo "trackRecoTrees_${run}.\${subRun}.root does not exist.  ls reads:"
      ls
    fi
  else
    if [ -f trackRecoTrees.log ]; then
      ifdh mv trackRecoTrees.log ${pnfsOutDir}/trackRecoTrees_${run}.\${subRun}.log
    fi
  fi

done
EOF

if [ -f ${pnfsOutDir}/runTrackTreeJob${fileNum}.sh ]; then
  rm -f ${pnfsOutDir}/runTrackTreeJob${fileNum}.sh
fi
  ifdh cp runTrackTreeJob${fileNum}.sh ${pnfsOutDir}/runTrackTreeJob${fileNum}.sh
while [ ! -f ${pnfsOutDir}/runTrackTreeJob${fileNum}.sh ]; do
  echo "${pnfsOutDir}/runTrackTreeJob${fileNum}.sh not found after ifdh cp.  Sleeping 5..."
  sleep 5
done

#Submit grid job
jobsub_submit -N 1 -G gm2 --OS=SL6 --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC --expected-lifetime=4h --role=Analysis file://${pnfsOutDir}/runTrackTreeJob${fileNum}.sh
rm -f runTrackTreeJob${fileNum}.sh
rm -f xrootdFileList${fileNum}.txt
rm -f SplitFileList${fileNum}.txt

done
