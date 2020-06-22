# get piped input file
#inFile=missingFiles.txt
inFile=missingFilesNew.txt
echo $inFile
# Get the list of sub runs

for line in `cat ${inFile}`; do
#  echo $line
  # Get run and sub-run
  run=${line##*_}
  run=${run%%.*}
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}
#  ls /pnfs/GM2/daq/run1/offline/gm2_5040A/runs_16000/${run}/${line}
  ls -ltr /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root
done