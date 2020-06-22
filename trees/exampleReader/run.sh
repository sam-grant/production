#!/bin/bash
dataset="60h" # "9d" "HK" "EG"

for file in `ls /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/${dataset}/trackAndTrackCaloTrees_*.root`; do
    echo $file
    ./Plotter $file
done

#hadd -f plots.root plots*.root