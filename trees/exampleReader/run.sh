#!/bin/bash

for file in `ls /gm2/data/g2be/Production/Trees/Run1/${dataset}/trackRecoTrees_*.root`; do
    echo $file
    ./Plotter $file
done

#hadd -f plots.root plots*.root