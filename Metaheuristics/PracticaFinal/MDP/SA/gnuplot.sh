#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "SA50_1.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
set logscale x
plot 'SA50_1.txt' using 1:3 t "Mejor solucion" w l, 'SA50_1.txt' using 1:4 t "Solucion actual" w l
_end_
