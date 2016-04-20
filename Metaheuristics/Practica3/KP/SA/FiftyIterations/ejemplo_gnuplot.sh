#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "fiftyIteration3G"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Valor mochila"
plot 'fiftyiteration3G.txt' using 1:2 t "Solucion terminal" w l, 'fiftyiteration3G.txt' using 1:3 t "Mejor Solucion" w l
_end_
