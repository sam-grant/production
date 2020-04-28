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
pnfsOutDir=/pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_EG_manualDQC/${run}
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

  if [ -f ${pnfsOutDir}/trackAndTrackCaloTrees_${run}.${subRun}.root ]; then 
    echo "ERROR: ${pnfsOutDir}/trackAndTrackCaloTrees_${run}.${subRun}.root already exists and would be overwritten."
    return
  fi

done

# Copy fcl & .so file to pnfs so we can get it from grid jobs
if [ -f ${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl ]; then
  rm -f ${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl 
fi
if [ -f ${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so ]; then
  rm -f ${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so 
fi
if [ -f ${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so ]; then
  rm -f ${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so 
fi
sleep 5
ifdh cp RunTrackAndTrackCaloNTup.fcl ${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl
ifdh cp libgm2tracker_filters_ManualDQCFilter_module.so ${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so
ifdh cp libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so ${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so
echo "Copied RunTrackAndTrackCaloNTup.fcl, libgm2tracker_filters_ManualDQCFilter_module.so & libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so to $pnfsOutDir"

# Set dataset name to get GoodTrackerFills
if [ $run -lt 16235 ]; then
  dataset="HighKick"
else
  dataset="EndGame"
fi

# Copy GoodTrackerFill files over to pnfs for grid access
for file in `cat FileList.txt`; do

  # Strip everything before last _, then extract middle of run.subrun.root
  subRun=${file##*_}
  subRun=${subRun%.*}
  subRun=${subRun#*.}

  if [ ! -f /gm2/data/g2be/GoodFillNumbers/gm2pro_daq_full_run1_${dataset}_5042A_goldList/${run}/GoodTrackerFills_${run}.${subRun}.txt ]; then
    echo "ERROR: /gm2/data/g2be/GoodFillNumbers/gm2pro_daq_full_run1_${dataset}_5042A_goldList/${run}/GoodTrackerFills_${run}.${subRun}.txt  not found."
    return
  fi

  if [ ! -f ${pnfsOutDir}/GoodTrackerFills_${run}.${subRun}.txt ]; then 
    ifdh cp /gm2/data/g2be/GoodFillNumbers/gm2pro_daq_full_run1_${dataset}_5042A_goldList/${run}/GoodTrackerFills_${run}.${subRun}.txt ${pnfsOutDir}/GoodTrackerFills_${run}.${subRun}.txt
  fi
done
echo "Copied GoodTrackerFills files from /gm2/data/g2be/GoodFillNumbers/gm2pro_daq_full_run1_${dataset}_5042A_goldList/${run} to $pnfsOutDir"

# Split into lists with 25 each (and submit one of these each time) - lowered this number so submission is slower and hopefully more will get through the database!
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
cat <<EOF > runTrackAndTrackCaloTrees${fileNum}.sh
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

#Copy fcl, GoodTrackerFill and .so files
if [ ! -z "\`ifdh ls ${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl\`" ]; then
  ifdh cp ${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl ./RunTrackAndTrackCaloNTup.fcl
else 
  echo "${pnfsOutDir}/RunTrackAndTrackCaloNTup.fcl does not exist"
fi
if [ ! -z "\`ifdh ls ${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so\`" ]; then
  ifdh cp ${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so ./libgm2tracker_filters_ManualDQCFilter_module.so
else 
  echo "${pnfsOutDir}/libgm2tracker_filters_ManualDQCFilter_module.so does not exist"
fi
if [ ! -z "\`ifdh ls ${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so\`" ]; then
  ifdh cp ${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so ./libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so
else 
  echo "${pnfsOutDir}/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so does not exist"
fi

#Setup gm2
source /cvmfs/gm2.opensciencegrid.org/prod/g-2/setup
setup gm2 v9_42_00 -q prof

#Add current directory to LD_LIBRARY_PATH for so file we copied
export LD_LIBRARY_PATH=\`pwd\`:\$LD_LIBRARY_PATH

#Run jobs
for file in \`cat xrootdFileList${fileNum}.txt\`; do
  echo "Processing \$file"
  subRun=\${file##*_}
  subRun=\${subRun%.*}
  subRun=\${subRun#*.}

  if [ ! -z "\`ifdh ls ${pnfsOutDir}/GoodTrackerFills_${run}.\${subRun}.txt\`" ]; then
    ifdh cp ${pnfsOutDir}/GoodTrackerFills_${run}.\${subRun}.txt ./GoodTrackerFills_${run}.\${subRun}.txt
  else 
    echo "${pnfsOutDir}/GoodTrackerFills_${run}.\${subRun}.txt does not exist"
  fi

  gm2 -c RunTrackAndTrackCaloNTup.fcl -s \$file -T trackAndTrackCaloTrees_${run}.\${subRun}.root

  # Only copy back if job completed successfully (output from last command was 0)
  if [ \$? -eq 0 ]; then
    if [ -f trackAndTrackCaloTrees_${run}.\${subRun}.root ]; then
      ifdh mv trackAndTrackCaloTrees_${run}.\${subRun}.root ${pnfsOutDir}/trackAndTrackCaloTrees_${run}.\${subRun}.root
    else 
      echo "trackAndTrackCaloTrees_${run}.\${subRun}.root does not exist.  ls reads:"
      ls
    fi
  else 
    if [ -f trackAndTrackCaloTrees.log ]; then
      ifdh mv trackAndTrackCaloTrees.log ${pnfsOutDir}/trackAndTrackCaloTrees_${run}.\${subRun}.log
    fi
  fi

done
EOF

if [ -f ${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh ]; then
  rm -f ${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh
fi
  ifdh cp runTrackAndTrackCaloTrees${fileNum}.sh ${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh
while [ ! -f ${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh ]; do
  echo "${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh not found after ifdh cp.  Sleeping 5..."
  sleep 5
done

#Submit grid job
jobsub_submit -N 1 -G gm2 --OS=SL6 --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC --expected-lifetime=4h --role=Analysis file://${pnfsOutDir}/runTrackAndTrackCaloTrees${fileNum}.sh
rm -f runTrackAndTrackCaloTrees${fileNum}.sh
rm -f xrootdFileList${fileNum}.txt
rm -f SplitFileList${fileNum}.txt

done
