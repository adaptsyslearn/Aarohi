#!/usr/bin/gnuplot

set term postscript eps enhanced color font 28 dashed

set size 1, 1
set key horizontal center top
set style data boxes
set style data histogram
set style fill solid border -1
set xlabel "Chain Length (#Phrases)" offset 0, 0.5
set ylabel "Prediction Time (msecs)" offset 2
set grid ytics
set xtics norotate mirror
set xrange [0:55] 
set yrange [0:1.2]
set boxwidth 0.25
set output 'TestdataCheckTime.eps'

plot \
'PhrasePredictionTimes.dat' using 1:4:($5) w errorbars ls 8 lw 5 pt 2 t "Std. Dev.", \
'PhrasePredictionTimes.dat' using 1:4 w linespoint lt 3 lw 4 pt 6 t "Mean Time"
