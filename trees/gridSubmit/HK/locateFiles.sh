# get piped input file
inFile=missingFiles.txt
echo $inFile
# Get the list of sub runs

for line in `cat ${inFile}`; do
  echo $line
  samweb locate-file $line
done