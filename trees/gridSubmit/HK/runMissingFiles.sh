# get piped input file
# dir=/pnfs/GM2/daq/run1/offline/gm2_5040D/runs_16000/
inFile=missingSubRuns.txt
echo $inFile
# Get the list of sub runs
subRun=""
# Loop through sub runs
for line in `cat ${inFile}`; do
  subRun=$line
  cd $subRun
  # Make file list for that sub run
  # ls ${dir}${subRun} >> files
  # Loop through files
  # for file in `cat files`; do
      # fileToRun=${dir}${subRun}/${file}
      # Check it exists
      # ls $fileToRun
      # Run it
      # gm2 -c ../RunTr
      
  # done
  # copy the script for the failed files over
  #cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${subRun}/runTrackAndTrackCaloTrees000.sh .
  #cp /pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_HK/${subRun}/xrootdFileList000.txt .
  source runTrackAndTrackCaloTrees000.sh
  wait
  cd ../
done