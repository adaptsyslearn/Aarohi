#!/bin/bash

path_to_src="Code/src" ## Path to Aarohi src directory
#path_to_scriptsrc=$(pwd)
cpuinfo=$(lscpu | grep "Model name")
hostname=$(hostname)
cd $pathologist

echo "Generating graphs with Table6 folder"
bash helperScripts/compute_mean_std_dev.sh Table6 

echo "Aarohi Prediction Times on $hostname with $cpuinfo are:"
cat Table6.txt | sort -n -k1 

echo "Chain Length(#1), Mean(#2) and Standard Deviation(#3)"
#cd $path_to_scriptsrc
