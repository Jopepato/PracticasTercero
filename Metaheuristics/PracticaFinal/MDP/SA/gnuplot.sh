#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "SA50_50.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'SA50_50.txt' using 1:3 t "Mejor solucion" w l
_end_
