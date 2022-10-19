#!/bin/bash
dataset="EG_final" 

for file in `ls /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/${dataset}/trackAndTrackCaloTrees_*.root`; do
    echo $file
    ./PlotterTrackAndTrackCalo $file
done

#hadd -f plots.root plots*.root
