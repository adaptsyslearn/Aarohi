#!/bin/bash

path_to_src="../Code/src" 
path_to_graphsrc=$(pwd)


cd $path_to_src

echo "Generate graphs for Graph10"
bash helperScripts/compute_mean_std_dev.sh Graph10
bash helperScripts/compute_meanstd_unopt.sh Graph10

#echo "Inference times for the optimized case and Unoptimized Case"
#cat Graph10.txt | sort -n -k1  
#cat Graph10.log | sort -n -k1 
 
cpuinfo=$(lscpu | grep "Model name") 
printf "#$cpuinfo\n" > $path_to_graphsrc/cpuvstime.dat
echo "#ChainLength#AvgTime(msecs)#Std.Dev   Optimized   Unoptimized" >> $path_to_graphsrc/cpuvstime.dat
paste Graph10.txt Graph10.log | awk '{print $1, $2, $3, $5, $6}' | sort -n -k1 >> $path_to_graphsrc/cpuvstime.dat

cd $path_to_graphsrc
gnuplot cpuvstime.gnu
gnuplot cpuvstimecompileropt.gnu
