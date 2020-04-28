# Hadd files in FileList_12345.txt (made by haddSubRunsSAMList.sh)

# Get run from argument
run=$1


# Change to directory for this run
echo "Processing run $run..."
cd $run

# Get all files in FileList_12345.txt
# mv ../FileList_${run}.txt .
files=""
for line in `cat FileList_${run}.txt`; do
  subrun=${line##*${run}.}
  subrun=${subrun%%.*}
  files=$files" "/pnfs/GM2/scratch/users/sgrant/TrackAndTrackCaloTrees_9d/${run}/trackAndTrackCaloTrees_${run}.${subrun}.root
done

# Hadd these files (using Joe's script that does a few at a time)
../../hadd.sh trackAndTrackCaloTrees_${run}.root $files

mv trackAndTrackCaloTrees_${run}.root /gm2/data/g2be/Production/TrackAndTrackCaloTrees/Run1/PermissionChanger/Input/trackAndTrackCaloTrees_${run}.root

cd ../
