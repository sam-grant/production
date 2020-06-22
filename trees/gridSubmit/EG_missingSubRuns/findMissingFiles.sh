pnfsOutDir=/pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_EG_missingSubRuns

echo "Checking output files for $dataset in $pnfsOutDir"

for line in `cat SAMFileListCalo.txt`; do

  # Get run and sub-run  
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}

  

  # Check this is a good file (not bad tracker, not out-of-sync, not already processed)
  # if ! grep -Fxq "${run} ${subrun}" OutOfSyncSubRuns.txt ; then
    # if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns.txt ; then
      # if ! grep -Fxq "${run} ${subrun}" DifferentDQCSubRuns.txt ; then
        if grep -Fxq "${run} ${subrun}" badSubRuns_EG.txt ; then
          if [ ! -f ${pnfsOutDir}/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
            echo $line
          fi
        fi
      # fi
    # fi
  # fi
    #       echo $line
    #     fi
    # fi


done

