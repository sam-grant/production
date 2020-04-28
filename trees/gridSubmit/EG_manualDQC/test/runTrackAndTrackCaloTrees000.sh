# Setup stuff to copy files back and forth
source /cvmfs/fermilab.opensciencegrid.org/products/common/etc/setups
source /cvmfs/fermilab.opensciencegrid.org/products/larsoft/setup
setup ifdhc

# Copy xrootdFileList000 here
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/xrootdFileList000.txt`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/xrootdFileList000.txt xrootdFileList000.txt
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/xrootdFileList000.txt does not exist"
fi

#Copy fcl, GoodTrackerFill and .so files
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/RunTrackAndTrackCaloNTup.fcl`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/RunTrackAndTrackCaloNTup.fcl ./RunTrackAndTrackCaloNTup.fcl
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/RunTrackAndTrackCaloNTup.fcl does not exist"
fi
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2tracker_filters_ManualDQCFilter_module.so`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2tracker_filters_ManualDQCFilter_module.so ./libgm2tracker_filters_ManualDQCFilter_module.so
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2tracker_filters_ManualDQCFilter_module.so does not exist"
fi
if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so`" ]; then
  ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so ./libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so
else 
  echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/libgm2analyses_strawtracker_TrackAndTrackCaloNTup_module.so does not exist"
fi

#Setup gm2
source /cvmfs/gm2.opensciencegrid.org/prod/g-2/setup
setup gm2 v9_42_00 -q prof

#Add current directory to LD_LIBRARY_PATH for so file we copied
export LD_LIBRARY_PATH=`pwd`:$LD_LIBRARY_PATH

#Run jobs
for file in `cat xrootdFileList000.txt`; do
  echo "Processing $file"
  subRun=${file##*_}
  subRun=${subRun%.*}
  subRun=${subRun#*.}

  if [ ! -z "`ifdh ls /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/GoodTrackerFills_16113.${subRun}.txt`" ]; then
    ifdh cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/GoodTrackerFills_16113.${subRun}.txt ./GoodTrackerFills_16113.${subRun}.txt
  else 
    echo "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/GoodTrackerFills_16113.${subRun}.txt does not exist"
  fi

  gm2 -c RunTrackAndTrackCaloNTup.fcl -s $file -T trackAndTrackCaloTrees_16113.${subRun}.root

  # Only copy back if job completed successfully (output from last command was 0)
  if [ $? -eq 0 ]; then
    if [ -f trackAndTrackCaloTrees_16113.${subRun}.root ]; then
      ifdh mv trackAndTrackCaloTrees_16113.${subRun}.root /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/trackAndTrackCaloTrees_16113.${subRun}.root
    else 
      echo "trackAndTrackCaloTrees_16113.${subRun}.root does not exist.  ls reads:"
      ls
    fi
  else 
    if [ -f trackAndTrackCaloTrees.log ]; then
      ifdh mv trackAndTrackCaloTrees.log /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_manualDQC/16113/trackAndTrackCaloTrees_16113.${subRun}.log
    fi
  fi

done
