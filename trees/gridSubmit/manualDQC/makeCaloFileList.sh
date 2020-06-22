# Check for jobs that haven't been processed already
for line in `cat fileNames.txt`; do

  # Get run and sub-run  
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}

 # echo $line

  if ! grep -Fxq "${run} ${subrun}" OutofSyncFileNames.txt ; then
    if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
      if ! grep -Fxq "${run} ${subrun}" DifferentDQCFileNames.txt ; then
        if [ ! -f ${pnfsOutDir}/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
#          echo $line
          echo `ls /pnfs/GM2/daq/run1/offline/gm2_5042B/runs_1*000/${run}/gm2offline_full_*_${run}.${subrun}.root` >> ManualDQCSubRunList5042B.txt
	  #echo ${run}${subrun}
        fi
      fi
    fi
  fi

done