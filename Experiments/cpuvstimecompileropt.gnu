#!/usr/bin/gnuplot

set term postscript eps enhanced color font 26 dashed

set size 1, 1
set key top left
set style data boxes
set style data histogram

set style fill solid border -1
set xlabel "Chain Length (#Phrases)" offset 0, 0.5
set ylabel "Mean Prediction Time (msecs)" offset 2
set grid ytics
set xtics norotate mirror

set boxwidth 0.20
set output 'compileropt.eps'

plot \
"cpuvstime.dat" using ($0-0.4):2 w boxes fs pattern 4 lt-1 t "With O3", \
	'' 	  using ($0-0.4):2:($3) w errorbars ls 12 lw 3 notitle, \
        ''   	  using ($0-0.2):4:xticlabels(1) w boxes fs pattern 9 t "Without O3", \
	'' 	  using ($0-0.2):4:($5) w errorbars ls 10 lw 3 notitle

