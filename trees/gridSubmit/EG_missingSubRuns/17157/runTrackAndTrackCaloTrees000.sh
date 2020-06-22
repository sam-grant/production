# Setup stuff to copy files back and forth
source /cvmfs/fermilab.opensciencegrid.org/products/common/etc/setups
source /cvmfs/fermilab.opensciencegrid.org/products/larsoft/setup
setup ifdhc

#Setup gm2
source /cvmfs/gm2.opensciencegrid.org/prod/g-2/setup
setup gm2 v9_45_00 -q prof

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

  gm2 -c RunTrackAndTrackCaloNTup.fcl -T trackAndTrackCaloTrees_17157.${subRun}.root

  # Only copy back if job completed successfully (output from last command was 0)
  if [ $? -eq 0 ]; then
    if [ -f trackAndTrackCaloTrees_17157.${subRun}.root ]; then
      ifdh mv trackAndTrackCaloTrees_17157.${subRun}.root /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG_missingSubRuns/17157/trackAndTrackCaloTrees_17157.${subRun}.root
    else 
      echo "trackAndTrackCaloTrees_17157.${subRun}.root does not exist.  ls reads:"
      ls
    fi
  fi
done < xrootdFileList000.txt
