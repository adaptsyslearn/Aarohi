#!/bin/bash

##############################################################################
######    This script takes two files (console logs of failed ################
######    nodes). Computes the time differences between ######################
######    adjacent phrases followed by cumulative inter-arrival times ########
######    Takes as input: NodeA.txt, NodeB.txt #####################
######    Produces: NodeA_Times.log, NodeB_Times.log, these files ############
######    are used by the gnuplot script #####################################
######    The final output is a graph ##################################
######    "Interarrivalcumulativelogscale.eps" ###############################


file1=NodeA.txt
file2=NodeB.txt

awk -F " " '{print $1}' $file1 | sort > Sorted_Times_NodeA.txt
awk -F " " '{print $1}' $file2 | sort > Sorted_Times_NodeB.txt

first_time1=$(awk 'NR=1{print $1; exit}' Sorted_Times_NodeA.txt)
past1=$(date -d "$first_time1" "+%s%3N")
#echo "Time(secs)	Time(mins)"  
while read time; do
	#echo "Time is $time"
	#current=$(date -d "$time" "+%s")
	current=$(date -d "$time" "+%s%3N")
	diffmsec=$(expr $current - $past1) #Time in milliseconds
	#diffmin=$(expr $diffsec / 60)
	echo "$diffmsec" >> NodeA_TimeDiff.txt
	past1=$current
done < Sorted_Times_NodeA.txt

first_time2=$(awk 'NR=1{print $1; exit}' Sorted_Times_NodeB.txt)
past2=$(date -d "$first_time2" "+%s%3N")
#echo "Time(secs)       Time(mins)"  
while read time; do
        #echo "Time is $time"
        #current=$(date -d "$time" "+%s")
        current=$(date -d "$time" "+%s%3N")
        diffmsec=$(expr $current - $past2) #Time in milliseconds
        #diffmin=$(expr $diffsec / 60)
        echo "$diffmsec" >> NodeB_TimeDiff.txt
        past2=$current
done < Sorted_Times_NodeB.txt

rm Sorted_Times_NodeA.txt
rm Sorted_Times_NodeB.txt

sort NodeA_TimeDiff.txt | nl > NodeA_sorted.txt
sort NodeB_TimeDiff.txt | nl > NodeB_sorted.txt

rm NodeA_TimeDiff.txt
rm NodeB_TimeDiff.txt

awk '{a[$2]++;} END{for(i in a) print a[i]"  "i}' NodeA_sorted.txt | sort -k2 -n > total_mtbfs_nodeA
awk '{a[$2]++;} END{for(i in a) print a[i]"  "i}' NodeB_sorted.txt | sort -k2 -n > total_mtbfs_nodeB

awk '{total += $0; $0 = total}1' total_mtbfs_nodeA > cumulative_timesA.txt
awk '{total += $0; $0 = total}1' total_mtbfs_nodeB > cumulative_timesB.txt
paste total_mtbfs_nodeA cumulative_timesA.txt > mtbfs_cumulativeA.txt
paste total_mtbfs_nodeB cumulative_timesB.txt > mtbfs_cumulativeB.txt

echo '#CountA#CumulativeCountA#Time-RangeA(msecs,0.5=0 since logscale)' > NodeA_Times.log
awk '{t=$2; $2=$3; $3=t; print;}' mtbfs_cumulativeA.txt >> NodeA_Times.log
echo '#CountB#CumulativeCountB#Time-RangeB(msecs,0.5=0 since logscale)' > NodeB_Times.log
awk '{t=$2; $2=$3; $3=t; print;}' mtbfs_cumulativeB.txt >> NodeB_Times.log

rm NodeA_sorted.txt total_mtbfs_nodeA cumulative_timesA.txt mtbfs_cumulativeA.txt
rm NodeB_sorted.txt total_mtbfs_nodeB cumulative_timesB.txt mtbfs_cumulativeB.txt

gnuplot InterArrivalTimesScatter.gnu

rm NodeA_Times.log
rm NodeB_Times.log
