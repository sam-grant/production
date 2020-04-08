#gm2 -c /gm2/app/users/sgrant/g2Soft/gm2Dev_v9_39_00/srcs/gm2analyses/fcl/RunTrackAndTrackCaloNTup.fcl -s /pnfs/GM2/daq/run1/offline/gm2_5040A/runs_15000/15921/gm2offline_full_23485958_15921.00369.root

#for file in cat

declare -a inFile=("xaa") #  "xab" "xac" "xad" "xaf" "xae" "xag" "xah" "xai" "xak" "xaj" "xal" "xam" "xao" "xan")

for i in "${inFile[@]}"; do

        echo $i

	mkdir $i
	cd $i

        # Get the list of root files 
        filesToRun=""
        for line in `cat ${i}`; do
            filesToRun=${filesToRun}" "${line}
#	    echo $filesToRun
	done

#	gm2 -c /gm2/app/users/sgrant/g2Soft/gm2Dev_v9_39_00/srcs/gm2analyses/fcl/RunTrackAndTrackCaloNTup.fcl -s $filesToRun
	
	wait

	cd ../
	
	break
done