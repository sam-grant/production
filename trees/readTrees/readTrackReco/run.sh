#!/bin/bash

for file in `ls /gm2/data/g2be/Production/Trees/Run2/NoDQC/trackRecoTrees_*.root`; do
    echo $file
    ./PlotterTrack $file
done

hadd -f plots.root plots*.root
