reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'
set grid y
set style data histogram
#set style histogram rowstacked
#box_wd = 0.1
#set boxwidth box_wd

plot [:][:0.120]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.002):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using ($0+0.3):($3):3 with labels title ' ', \
'' u 2+3:xtic(1) w histogram title 'total' , \
'' u ($0):($4):4 w labels title ' '
