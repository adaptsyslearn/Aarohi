#!/bin/bash

path_to_src="../Code/src" 
path_to_graphsrc=$(pwd)

cd $path_to_src

echo "Generate graph 12"
bash Figure12.sh > Fig12.dat
echo "#System   Token Fraction (Mean)       Std_Dev " > $path_to_graphsrc/Figure12.dat
paste Systems.txt Fig12.dat >> $path_to_graphsrc/Figure12.dat

############# bash process.sh generates the source files for Figure 13 ################

echo "Generate graph 13"
echo "#Failure   LeadTime (mins)       Mean" > $path_to_graphsrc/Figure13.dat
bash Figure13.sh > $path_to_graphsrc/Figure13.dat
Mean_LeadTime=$(awk '{sum+=$2} END {print (sum/NR)}' $path_to_graphsrc/Figure13.dat)
awk '{print $0"	"}' $path_to_graphsrc/Figure13.dat > $path_to_graphsrc/F13.dat
sed -e "s/$/$Mean_LeadTime/" $path_to_graphsrc/F13.dat > $path_to_graphsrc/Fig13.dat

rm $path_to_graphsrc/Figure13.dat $path_to_graphsrc/F13.dat

echo "Generate graph 14"
echo "#Systems   LeadTime (mins)Mean	Std_Dev" > $path_to_graphsrc/Figure14.dat
bash Figure14.sh > $path_to_graphsrc/Figure14.dat

echo "Generate graph 15"
bash Figure15.sh > Fig15.dat
echo "#System   Mean Time       Std_Dev (msecs)" > $path_to_graphsrc/Figure15.dat
paste Systems.txt Fig15.dat >> $path_to_graphsrc/Figure15.dat

cd $path_to_graphsrc
gnuplot LeadTime.gnu
gnuplot System_TestTime.gnu
gnuplot System_LeadTime.gnu
gnuplot System_TokenFraction.gnu
