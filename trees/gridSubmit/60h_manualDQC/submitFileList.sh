# Input to this script is sorted list of /pnfs file names 
# All the choosing of these is done by other scripts (need to pick the OutOfSync runs and also those where DQC
# has changed between versions 5040A and 5042A)
if [ ! -f ManualDQCSubRunList.txt ]; then
  echo "Input (ManualDQCSubRunList.txt) not found."
  return
fi

# Check for jobs that haven't been processed already
currJobRun=-1
rm -f FileList.txt && touch FileList.txt
for line in `cat ManualDQCSubRunList.txt`; do

  # Get run and sub-run  
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}

  # If we're in a new run, submit the old lot and clear FileList
  if [ $run -ne $currJobRun ] ; then
    if [ -s FileList.txt ]; then
      bash -c ". submitFiles.sh"
      rm -f FileList.txt && touch FileList.txt
    fi
    currJobRun=$run
  fi

  # Set currJobRun if first time through
  if [ $currJobRun -lt 0 ]; then 
    currJobRun=$run
  fi

  # Check output doesn't exist before adding
  if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
    if [ ! -f /pnfs/GM2/scratch/users/jmott/TrackingTreesManualDQC/${run}/trackRecoTrees_${run}.${subrun}.root ]; then
      if [ -f /pnfs/GM2/scratch/users/jmott/TrackingTrees/${run}/trackRecoTrees_${run}.${subrun}.log ]; then
        echo "!!! /pnfs/GM2/scratch/users/jmott/TrackingTrees/${run}/trackRecoTrees_${run}.${subrun}.log exists.  Delete all log files first!"
	return
      fi
      echo $line >> FileList.txt
    fi
  fi

done

# Catch final submission (as we've left loop)
if [ -s FileList.txt ]; then
 bash -c ". submitFiles.sh"
 rm -f FileList.txt
fi

rm -f FileList.txt

echo "done"
