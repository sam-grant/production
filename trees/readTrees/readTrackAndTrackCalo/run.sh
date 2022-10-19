#!/bin/bash
dataset={"EG" 

# Number of wrong hits
declare -a datasets=("60h" "9d" "HK" "EG") 

# Define output path

for dataset in "${datasets[@]}"; do

    for file in `ls /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/${dataset}/trackAndTrackCaloTrees_*.root`; do

	echo $file

	./PlotterTrackAndTrackCalo $file

    done

done

#hadd -f plots.root plots*.root
