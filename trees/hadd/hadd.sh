# Check for jobs that haven't been processed already
dataset="EG"
prefix=trackAndTrackCaloTrees
for line in `cat subRunList_${dataset}.txt`; do

    echo $line
    file=${prefix}_${line}.root
    ls -ltrh ../${dataset}/${file}
    lr -ltrh ../manualDQC/${file}

    echo "Hadding $file"

    hadd -f ../${dataset}_final/$file ../${dataset}/${file} ../manualDQC/${file}
    
    wait

    rm ../${dataset}/${file}
    rm ../manualDQC/${file}

done  