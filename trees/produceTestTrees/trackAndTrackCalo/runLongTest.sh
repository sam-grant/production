# Get the list of root files
#inFile=fileList
filesToRun=""
for line in `cat fileList`; do
    filesToRun=${filesToRun}" "/pnfs/GM2/daq/run1/offline/gm2_5040A/runs_15000/15921/${line}
done
echo $filesToRun
gm2 -c ../RunTrackAndTrackCaloNTup.fcl -s $filesToRun
