pnfsOutDir=/pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_manualDQC
echo "Checking output files for $dataset in $pnfsOutDir"

for line in `cat FileListCalo.txt`; do

  # Get run and sub-run  
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}

    if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
        if [ ! -f ${pnfsOutDir}/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
          echo $line
        fi
    fi


done

