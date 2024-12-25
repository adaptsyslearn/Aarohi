#!/bin/bash

# This script takes in the directories containing files of specific chain lengths, repeats Aarohi testing #num_repeat times and calculates the 
# mean and standard deviation as per the standard formula  
# This script and the directories of test sequences should be in the same filepath/location, update the test directory names if needed

# Usage: /bin/bash compute_mean_std_dev.sh directory_names or ./compute_mean_std_dev.sh directory_names  

cpu_info="$(lscpu)"
num_repeat=12 ## Increasing the iterations may cause high fluctuations in standard deviation

declare -a testdata_directory=$1

for (( j=1; j<${#testdata_directory[@]}+1; j++ ));do
	output_file="${testdata_directory[$j-1]}.txt"
	[ -e $output_file ] && rm $output_file
	for file in $(pwd)/${testdata_directory[$j-1]}/*;do
		total_time=0
		declare -a individual_time
		for (( i=0; i<num_repeat; i++ ));do
			output="$($(pwd)/aarohi $file | grep "Prediction time is")"
			timetaken=$(echo ${output} | sed 's/[^0-9]*//g')
			total_time="$(($total_time+$timetaken))"
			individual_time[$i]=$(echo $timetaken)
			#echo ${individual_time[$i]}
			#sleep 1
		done
		stddev=0
		mean=$(echo $total_time / $num_repeat | bc -l)
		
		for (( k=0; k<num_repeat; k++ ));do
			tmp=$(echo $mean - ${individual_time[$k]} | bc -l)
			tmp1=$(echo $tmp ^ 2 | bc -l)
			stddev=$(echo $stddev + $tmp1| bc -l)
		done
		filename=""
		stddev1=$(echo $stddev / $num_repeat | bc -l)
		stddev2=$(echo "sqrt($stddev1)" | bc -l)
		stddev3=$(echo $stddev2 / 1000000 | bc -l)
		mean1=$(echo $mean / 1000000 | bc -l) # Time in milliseconds
		filename=$(echo $file | grep -o -E '[0-9]+')
		size=$(echo $filename | grep -oE '[^ ]+$')
		result=$(echo "$size $mean1 $stddev3")
		echo $result >> $output_file
	done
	#echo $result
done
