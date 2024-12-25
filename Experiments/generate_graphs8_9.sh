#!/bin/bash

path_to_src="../Code/src" ## Path to Aarohi src directory
path_to_graphsrc=$(pwd)

cd $path_to_src

echo "Generating graphs with and without Benign Phrases with Graph8 and 9 folders"
bash helperScripts/compute_mean_std_dev.sh Graph08 
bash helperScripts/compute_mean_std_dev.sh Graph09

#cat Graph08.txt | sort -n -k1 > Graph08_sorted.txt
#cat Graph09.txt | sort -n -k1 > Graph09_sorted.txt

echo "#ChainLength(multi-FC)#AvgTime(msecs)#Std.Dev   (w/Benign)#AvgTime(msecs)#Std.Dev" > $path_to_graphsrc/PhrasePredictionTimes.dat
paste Graph08.txt Graph09.txt | awk '{print $1, $2, $3, $5, $6}' >> $path_to_graphsrc/PhrasePredictionTimes.dat

cd $path_to_graphsrc
gnuplot MultiFCBenignCheckTime.gnu
gnuplot MultiFCOnlyCheckTime.gnu
