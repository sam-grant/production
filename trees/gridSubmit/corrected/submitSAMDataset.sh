# Check that samweb and root are installed
command -v samweb >/dev/null 2>&1 || { echo >&2 "samweb not found. You want:"; echo "source /grid/fermiapp/products/common/etc/setups.sh"; echo "setup fife_utils"; return; }

# Get sam dataset number
if [ "$#" -ne 2 ]; then
  echo "SAM datasets for calo and tracker required as arguments"
  return
fi
datasetCalo=$1
datasetTracker=$2
echo "Processing dataset $dataset..."

# Get list of files in the calo dataset
echo "Getting calo file list."
samweb -e gm2 list-definition-files $datasetCalo > tmp.txt
sort -t_ -k4 tmp.txt > SAMFileListCalo.txt
rm -f tmp.txt

# Get list of files in the tracker dataset
echo "Getting tracker file list."
samweb -e gm2 list-definition-files $datasetTracker > tmp.txt
sort -t_ -k4 tmp.txt > SAMFileListTracker.txt
rm -f tmp.txt

# Make new file list with calo file and tracker file columns (merge on column 4 with _ as delimiter, then use awk to print out two columns with caloFile and trackerFile)
echo "Merging calo and tracker file names into one list."
join -t '_' -j 4 SAMFileListCalo.txt SAMFileListTracker.txt | awk -F_ '{print $2"_"$3"_"$4"_"$1" "$5"_"$6"_"$7"_"$1}' > SAMFileList.txt

echo "Finished merging."
# Check for jobs that haven't been processed already
currJobRun=-1
currRunPathCalo=""
rm -f FileList.txt && touch FileList.txt
echo "Reading lines."
while read line; do

  echo $line
  # Separate out calo and tracker files from input list (first column/second column)
  caloFile=`echo $line | cut -d' '  -f1`
  trackerFile=`echo $line | cut -d' '  -f2`

  # Get run and sub-run (this is to be same in both tracker/calo files)
  run=${caloFile##*_}
  run=${run%%.*}
  subrun=${caloFile##*${run}.}
  subrun=${subrun%%.*}

  # If we're in a new run (or the first run), submit the old lot and clear FileList
  if [ $run -ne $currJobRun ]; then
    if [ -s FileList.txt ]; then
      bash -c ". submitFiles.sh"
      rm -f FileList.txt && touch FileList.txt
      # If testing, add return statment here
      # return
    fi
    fullFilePathCalo=`samweb -e gm2 locate-file $caloFile`
    currRunPathCalo=/pnfs${fullFilePathCalo##*/pnfs}
    currRunPathCalo=${currRunPathCalo%%(*}
    fullFilePathTracker=`samweb -e gm2 locate-file $trackerFile`
    currRunPathTracker=/pnfs${fullFilePathTracker##*/pnfs}
    currRunPathTracker=${currRunPathTracker%%(*}
    currJobRun=$run
  fi

  # Check output doesn't exist before adding
  if ! grep -Fxq "${run} ${subrun}" OutOfSyncSubRuns_5040A_goldList.txt ; then
    if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
      if ! grep -Fxq "${run} ${subrun}" DifferentDQCSubRuns_5040A_5042A_goldList.txt ; then
        if [ ! -f /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
          if [ -f /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees/${run}/trackAndTrackCaloTrees_${run}.${subrun}.log ]; then
            echo "!!! /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees/${run}/trackAndTrackCaloTrees_${run}.${subrun}.log exists.  Delete all log files first!"
	    return
	  fi
          echo $currRunPath/$line >> FileList.txt
        fi
      fi
    fi
  fi

done
echo "Submitting files."
# Catch final submission (as we've left loop)
if [ -s FileList.txt ]; then
 bash -c ". submitFiles.sh"
 rm -f FileList.txt
fi

echo "done"
