# Check that samweb and root are installed
command -v samweb >/dev/null 2>&1 || { echo >&2 "samweb not found. You want:"; echo "source /grid/fermiapp/products/common/etc/setups.sh"; echo "setup fife_utils"; return; }

# Get sam dataset number
if [ "$#" -ne 1 ]; then
  echo "SAM dataset (only) required as argument"
  return
fi
dataset=$1
echo "Processing dataset $dataset..."

# Get list of sub-runs in this dataset
samweb -e gm2 list-definition-files $dataset > tmp.txt
sort -t_ -k4 tmp.txt > SAMFileList.txt
rm -f tmp.txt

# Check for jobs that haven't been processed already
currJobRun=-1
currRunPath=""
rm -f FileList.txt && touch FileList.txt
for line in `cat SAMFileList.txt`; do

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
      # if testing, add return statement
      # return
    fi
    fullFilePath=`samweb -e gm2 locate-file $line`
    currRunPath=/pnfs${fullFilePath##*/pnfs}
    currRunPath=${currRunPath%%(*}
    currJobRun=$run
  fi

  # Set path and currJobRun if first time through
  if [ $currJobRun -lt 0 ]; then 
    fullFilePath=`samweb -e gm2 locate-file $line`
    currRunPath=/pnfs${fullFilePath##*/pnfs}
    currRunPath=${currRunPath%%(*}
    currJobRun=$run
  fi

  # Check output doesn't exist before adding
  if ! grep -Fxq "${run} ${subrun}" OutOfSyncSubRuns_5040A_goldList.txt ; then
    if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
      if ! grep -Fxq "${run} ${subrun}" DifferentDQCSubRuns_5040A_5042A_goldList.txt ; then
        if [ ! -f /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_9d/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
          if [ -f /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_9d/${run}/trackAndTrackCaloTrees_${run}.${subrun}.log ]; then
            echo "!!! /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_9d/${run}/trackAndTrackCaloTrees_${run}.${subrun}.log exists.  Delete all log files first!"
	    return
	  fi
          echo $currRunPath/$line >> FileList.txt
        fi
      fi
    fi
  fi

done

# Catch final submission (as we've left loop)
if [ -s FileList.txt ]; then
 bash -c ". submitFiles.sh"
 rm -f FileList.txt
fi

echo "done"
