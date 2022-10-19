
declare -a datasets=("60h" "9d" "HK" "EG" "HK_trim" "EG_trim" "Run1" "Run1_trim")

for i in "${datasets[@]}"; do

	files=`cat ${i}.txt`
	echo $files
	hadd -f plots/plots_${i}_lostMuons.root $files

done