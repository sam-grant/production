# Check for jobs that haven't been processed already
previousRun=""
for line in `cat ManualDQCSubRunList.txt`; do

  # Get run
  run=${line##*_}
  run=${run%%.*}

  if [[ $previousRun == $run ]]; then
      continue
  fi

  previousRun=$run
  
  echo "$run" >> subRunList.txt

done  