# Setup stuff to copy files back and forth
source /cvmfs/fermilab.opensciencegrid.org/products/common/etc/setups
source /cvmfs/fermilab.opensciencegrid.org/products/larsoft/setup
setup ifdhc

# Copy xrootdFileList000 here
# if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/xrootdFileList000.txt`" ]; then
#   ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/xrootdFileList000.txt xrootdFileList000.txt
# else 
#   echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/xrootdFileList000.txt does not exist"
# fi

#Copy fcl and so files
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/RunTrackAndTrackCaloNTup.fcl`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/RunTrackAndTrackCaloNTup.fcl ./RunTrackAndTrackCaloNTup.fcl
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/RunTrackAndTrackCaloNTup.fcl does not exist"
fi
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so ./libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so does not exist"
fi

#Setup gm2
source /cvmfs/gm2.opensciencegrid.org/prod/g-2/setup
setup gm2 v9_42_00 -q prof

#Add current directory to LD_LIBRARY_PATH for so file we copied
export LD_LIBRARY_PATH=`pwd`:$LD_LIBRARY_PATH

# Some nodes have newer kernels
case 2.6.32-754.28.1.el6.x86_64 in
  3.*) export UPS_OVERRIDE="-H Linux64bit+2.6-2.12";;
  4.*) export UPS_OVERRIDE="-H Linux64bit+2.6-2.12";;
esac

#Run jobs
while read line; do 

  echo "Processing $line"
  caloFile=`echo $line | cut -d' ' -f 1`
  trackerFile=`echo $line | cut -d' ' -f 2`
  
  subRun=${caloFile##*_}
  subRun=${subRun%.*}
  subRun=${subRun#*.}

  # Update input and secondary file names in fcl file
  echo "" >> RunTrackAndTrackCaloNTup.fcl
  echo "source.fileNames: [ \"$caloFile\" ]" >> RunTrackAndTrackCaloNTup.fcl
  echo "source.secondaryFileNames: [ {" >> RunTrackAndTrackCaloNTup.fcl
  echo "  a: \"$caloFile\"" >> RunTrackAndTrackCaloNTup.fcl
  echo "  b: [\"$trackerFile\"]" >> RunTrackAndTrackCaloNTup.fcl
  echo "} ]" >> RunTrackAndTrackCaloNTup.fcl

  gm2 -c RunTrackAndTrackCaloNTup.fcl -T trackAndTrackCaloTrees_16193.${subRun}.root

  # Only copy back if job completed successfully (output from last command was 0)
  if [ $? -eq 0 ]; then
    if [ -f trackAndTrackCaloTrees_16193.${subRun}.root ]; then
      ifdh mv trackAndTrackCaloTrees_16193.${subRun}.root /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/16193/trackAndTrackCaloTrees_16193.${subRun}.root
    else 
      echo "trackAndTrackCaloTrees_16193.${subRun}.root does not exist.  ls reads:"
      ls
    fi
  fi
done < xrootdFileList000.txt
