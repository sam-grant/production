pnfsOutDir=/pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_EG_missingSubRuns

echo "Checking output files for $dataset in $pnfsOutDir"

for line in `cat SAMFileListCalo.txt`; do

  # Get run and sub-run  
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}

  if grep -Fxq "${run} ${subrun}" badSubRuns_EG.txt ; then

    ls ${pnfsOutDir}/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root

    # if [ -f ${pnfsOutDir}/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
    #   ls $line
    # fi
    
  fi

done