# get piped input file
dir=/pnfs/GM2/daq/run1/offline/gm2_5040D/runs_16000/
inFile=missingSubRuns.txt
echo $inFile
# Get the list of sub runs
subRun=""
for line in `cat ${inFile}`; do
  subRun=$line
  echo $subRun
  
#  mkdir $subRun
  cd $subRun
  ls ${dir}${subRun} >> files
  more files
  # copy the script for the failed files over
  #cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${subRun}/runTrackAndTrackCaloTrees000.sh .
  #cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${subRun}/xrootdFileList000.txt .
#  source runTrackAndTrackCaloTrees000.sh
#  wait
  cd ../
done