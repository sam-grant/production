
path=/gm2/data/g2be/Production/Trees/Run1

for tree in `ls ${path}/trackRecoTrees*.root`; do

    echo "Breaking to stop this script being run by mistake! Uncomment break in script if you really want to use it. "
    break



    # Strip subrun number
    run=${tree##*_}
    run=${run%%.*}

    echo ""
    echo "Modifying ${path}/trackRecoTrees_${run}.root"

    # Run
    ./ModifyNTuple.exe $run
    
    wait
    
    # Check that the output is there, and overwrite the old tree
    if [[ -f ${path}/trackRecoTrees_${run}_corrected.root ]]; then
        echo "Corrected tree found, overwriting..."
	   # cp -f ${path}/trackRecoTrees_${run}_corrected.root ${path}/trackRecoTrees_${run}.root
	   # rm -f ${path}/trackRecoTrees_${run}_corrected.root
    else
	   echo "!!!! No corrected tree found for run ${run} !!!!"
	   # break
    fi

    echo "Done"
done
