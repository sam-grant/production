# Hadd files in FileList_12345.txt (made by haddSubRunsSAMList.sh)

# Get run from argument
run=$1

# Check that output dir doesn't exist
if [ -d $run ]; then
 echo "Output directory $run already exists."
 rm -f FileList_${run}.txt
 return
fi

# Change to directory for this run
echo "Processing run $run..."
mkdir $run
cd $run

# Get all files in FileList_12345.txt
mv ../FileList_${run}.txt .
files=""
for line in `cat FileList_${run}.txt`; do
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}
  files=$files" "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_EG/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root
done

# Hadd these files (using Joe's script that does a few at a time)
../../hadd.sh trackAndTrackCaloTrees_${run}.root $files

mv trackAndTrackCaloTrees_${run}.root /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/EG/trackAndTrackCaloTrees_${run}.root

cd ../
