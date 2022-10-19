path=/gm2/data/g2be/Production/TrackQualityTrees/run2C

for tree in `ls ${path}/gm2tracker_*.root`; do

    echo $tree

    # Strip subrun number, although in this case it's not really subrun number
    # change this to id=${tree##*quality_} to remove the "8..." number, not sure what that is
    id=${tree##*quality_} # change quality to qualityOnly

    id=${id%%.root*}

    # echo ${path}/${tree}
    echo $id
    # echo $tree

    echo ""
    echo "Modifying ${tree}" 

    # Run
    ./ModifyQualityNTuple.exe $id
    
    wait
    
    # Check that the output is there, and overwrite the old tree
    if [[ -f ${path}/trackRecoTrees_quality_${id}_corrected.root ]]; then
        echo "Corrected tree found, overwriting..."
	   # cp -f ${tree} ${path}/trackRecoTrees_${id}.root
	   # rm -f ${path}/trackRecoTrees_${run}_corrected.root
    else
	   echo "!!!! No corrected tree found for run ${id} !!!!"
	   # break
    fi

    echo "Done"

    break

done
