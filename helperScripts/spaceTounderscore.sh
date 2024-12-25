#!/bin/bash

# Find and replace whitespaces in the 3rd column with underscore

path=`pwd`
filename=$1
#filename='rawinput'
inputfile=$path/$filename.txt
outfile=$path/$filename.log
test -f $outfile || touch $outfile
#if [ ! -f $outfile ]; then
#       echo "Creating the file $outfile"
#       touch $outfile
#fi
#echo OutputFile is $outfile
sed 's/\s\+/_/g' $inputfile >> $outfile
