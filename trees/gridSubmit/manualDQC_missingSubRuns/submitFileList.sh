# Input to this script is sorted list of /pnfs file names 
# All the choosing of these is done by other scripts (need to pick the OutOfSync runs and also those where DQC
# has changed between versions 5040A and 5042A)
# Check that samweb and root are installed
command -v samweb >/dev/null 2>&1 || { echo >&2 "samweb not found. You want:"; echo "source /grid/fermiapp/products/common/etc/setups.sh"; echo "setup fife_utils"; return; }

# Get list of files in the calo dataset
echo "Getting calo file list."
sort -t_ -k4 ManualDQCFileNames5042B.txt > FileListCalo.txt

# Get list of files in the tracker dataset
echo "Getting tracker file list."
sort -t_ -k4 ManualDQCFileNames5040A.txt > FileListTracker.txt
 
# Make new file list with calo file and tracker file columns (merge on column 4 with _ as delimiter, then use awk to print out two columns with caloFile and trackerFile)
echo "Merging calo and tracker file names into one list."
join -t '_' -j 4 FileListCalo.txt FileListTracker.txt | awk -F_ '{print $2"_"$3"_"$4"_"$1" "$5"_"$6"_"$7"_"$1}' > JoinedFileList.txt


# Check for jobs that haven't been processed already
currJobRun=-1
currRunPathCalo=""
rm -f FileList.txt && touch FileList.txt
while read line; do
  # echo $line

  # Separate out calo and tracker files from input list (first column/second column)
  caloFile=`echo $line | cut -d' '  -f1`
  trackerFile=`echo $line | cut -d' '  -f2`

  # Get run and sub-run (this is to be same in both tracker/calo files)
  run=${caloFile##*_}
  run=${run%%.*}
  subrun=${caloFile##*${run}.}
  subrun=${subrun%%.*}

  # If we're in a new run, submit the old lot and clear FileList
  if [ $run -ne $currJobRun ] ; then
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

  # Set currJobRun if first time through
  # if [ $currJobRun -lt 0 ]; then 
    # currJobRun=$run
  # fi

  # Check output doesn't exist before adding
  if ! grep -Fxq "${run} ${subrun}" BadTrackerSubRuns_5040A_goldList.txt ; then
    if grep -Fxq "${run} ${subrun}" badSubRuns_EG.txt ; then
    # if ! grep -Fxq "${run} ${subrun}" OutOfSyncSubRuns.txt ; then # Comment this when running out of synch runs
      if [ ! -f /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_manualDQC_missingSubRuns/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
        if [ ! -f /pnfs/GM2/scratch/users/${USER}/TrackAndTrackCaloTrees_EG_missingSubRuns/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root ]; then
          echo ${currRunPathCalo}/${caloFile} ${currRunPathTracker}/${trackerFile} >> FileList.txt
        fi
      fi
    fi
  fi
  
done < JoinedFileList.txt


# Catch final submission (as we've left loop)
if [ -s FileList.txt ]; then
 echo "done"
 bash -c ". submitFiles.sh"
 rm -f FileList.txt
fi

rm -f FileList.txt

echo "done"


