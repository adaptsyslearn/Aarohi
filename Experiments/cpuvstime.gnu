#!/usr/bin/gnuplot

set term postscript eps enhanced color font 26 dashed

#set key graph 0.85,0.95
set size 1, 1
set key horizontal top left
set style data boxes
set style data histogram
#set style histogram cluster gap 2
set style fill solid border -1
set xlabel "Chain Length (#Phrases)" offset 0, 0.5
set ylabel "Mean Prediction Time (msecs)" offset 2
set grid ytics
set xtics norotate mirror
#set xrange [0:55] 
set yrange [0:15]
set boxwidth 0.20
set output 'cpuvstime.eps'

plot \
"CPUTime.dat" using ($0-0.4):2 w boxes fs pattern 4 lt-1 t "Intel-QuadCore-Q9550 2.83GHz", \
	'' 	  using ($0-0.4):2:($3) w errorbars ls 12 lw 3 notitle, \
        ''   	  using ($0-0.2):4 w boxes fs pattern 9 t "Intel-XeonSilver-4110 2.10GHz", \
	'' 	  using ($0-0.2):4:($5) w errorbars ls 10 lw 3 notitle, \
        ''   	  using ($0):6:xticlabels(1) w boxes fs pattern 10 t "Intel-XeonR-E5-2640 2.6GHz", \
	'' 	  using ($0):6:($7) w errorbars ls 10 lw 3 notitle, \
        ''   	  using ($0+0.2):8 w boxes fs pattern 6 t "AMD Opteron 6128", \
	'' 	  using ($0+0.2):8:($9) w errorbars ls 10 lw 3 notitle

  





