dataset="Run1" # "HK" # "9d" # "60h" # "EG"

#for i in {15921..15991}; do # 60h
#for i in {16355..16514}; do # 9d
#for i in {16113..16234}; do # HK
#for i in {17065..17527}; do # EG
for i in {15921..17527}; do # Run 1

    ls plots_*_${i}.root >> ${dataset}.txt

done

    