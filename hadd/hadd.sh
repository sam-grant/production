dataset="EG"
prefix=trackAndTrackCaloTrees

echo "MAKE SURE THAT YOU HAVE THE SAME SETS OF SUB RUNS IN BOTH BEFORE DOING THIS"
#for line in `cat subRunList_${dataset}.txt`; do
for line in `cat subRunList_${dataset}_missingSubRuns.txt`; do

    echo $line

#    file=${prefix}_${line}.root
  
#   echo "\nRegular DQC file"
#    ls ../${dataset}/${line}
#   echo "\nEG_final"
    ls ../${dataset}_final/${line}
#    echo "EG_missingSubRuns"
    ls ../${dataset}_missingSubRuns/${line}

    echo "Hadding ${line}"

    hadd ../${dataset}_missingSubRuns_hadd/${line} ../${dataset}_final/${line} ../${dataset}_missingSubRuns/${line} # ../manualDQC/${line}
    
    wait

#    echo "Finished ${line}\n" # - removing the old one\n"
#    rm ../${dataset}/${line}
#    rm ../manualDQC/${line}
  
done