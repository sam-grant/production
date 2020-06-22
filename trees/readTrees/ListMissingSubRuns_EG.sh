prevSubRun=""

for line in `cat uniqueToReco_EG.txt`; do

	run=${line:0:5}
	subRun="00"${line:5:3}

	if [[ $prevSubRun == $subRun ]]; then
      continue
  	fi

	prevSubRun=$subRun

	echo ${run}" "${subRun} >> badSubRuns_EG.txt

done