#!/bin/bash

for file in `ls /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/EG_final/trackAndTrackCaloTrees_*.root`; do
#for file in `ls /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/HK/trackAndTrackCaloTrees_*.root`; do
    echo $file
    ./PlotterTrackAndTrackCalo $file
done

#hadd -f plots.root plots*.root
