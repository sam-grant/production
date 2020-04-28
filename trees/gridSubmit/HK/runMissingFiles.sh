# get piped input file
inFile=missingSubRuns.txt
echo $inFile
# Get the list of sub runs
subRun=""
for line in `cat ${inFile}`; do
  subRun=$line
  echo $subRun
  mkdir $subRun
  cd $subRun
  # copy the script for the failed files over
#  cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${subRun}/runTrackAndTrackCaloTrees000.sh .
  source runTrackAndTrackCaloTrees000.sh
  wait
  cd ../
done