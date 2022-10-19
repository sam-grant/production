# Check for jobs that haven't been processed already

for line in `cat ../EG.txt`; do

  # Get run
  run=${line}

  if [[ $previousRun == $run ]]; then
      continue
  fi

  previousRun=$run
  
  echo "$run" >> subRunList.txt

done  