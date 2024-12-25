#!/usr/bin/gnuplot

set term postscript eps enhanced color font 28 dashed 

set size 1, 1
set key top left
set style data boxes
set style data histogram
set style fill solid border -1
set xlabel "Inter-Arrival Times(millisecs) Log Scale" offset 0,0.5
set ylabel "Cumulative Phrase Arrivals" offset 2
#set grid xtics
set xtics norotate mirror
set logscale x
set format x "10^{%L}"
#set xrange [0:12053212] 
set yrange [0:320]
set boxwidth 0.25
set output 'Interarrivalcumulativelogscale.eps'
set offsets 0.1, 0.1, 0, 0

plot \
'NodeA_Times.log' using 3:2 w linespoints lt 3 lw 3 pt 3 t "{/Symbol D}Time Node A",\
'NodeB_Times.log' using 3:2 w linespoints lt 8 lw 3 pt 3 t "{/Symbol D}Time Node B"
