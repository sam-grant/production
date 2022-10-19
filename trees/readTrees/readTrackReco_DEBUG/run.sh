#!/bin/bash

# for file in `/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_{15921..15991}.root`; do
    # echo $file
    # ./PlotterTrack $file
# done

# for i in {15921..15991}; do
#for i in {16355..16514}; do
#for i in {16113..16234}; do
#for i in {17065..17527}; do

declare -a runs=("17148" "17157" "17243" "17398")

for i in "${runs[@]}"; do

	# echo $i   

    echo /gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_${i}.root
    ./PlotterTrack /gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_${i}.root
    # wait
done


#hadd -f plots.root plots*.root
