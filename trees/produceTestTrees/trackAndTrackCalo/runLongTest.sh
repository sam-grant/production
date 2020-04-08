# Get the list of root files
inFile=$1
filesToRun=""
for line in `cat ${fileList}/${inFile}`; do
    filesToRun=${filesToRun}" "/pnfs/GM2/daq/run1/offline/gm2_5040A/runs_15000/15921/${line}
done
echo $filesToRun
gm2 -c /gm2/app/users/sgrant/g2Soft/gm2Dev_v9_39_00/srcs/gm2analyses/fcl/RunTrackAndTrackCaloNTup.fcl -s $filesToRun
