#!/bin/bash

#for file in `/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_{15921..17527}.root`; do#
   # echo $file
    #./PlotterCountTracks $file
#done
#for i in {15921..15991}; do 
#for i in {16355..16514}; do
#for i in {16113..16234}; do
for i in {15921..17527}; do
    
	# file=/gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_${i}.root
#    echo /gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_${i}.root
    ./PlotterCountTracks /gm2/data/g2be/Production/Trees/Run1/trackRecoTrees_${i}.root
    wait
done


#hadd -f plots.root plots*.root
