#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIteration10000G"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Distancia"
plot 'kk3.txt' using 1:3 t "Solucion actual" w l
_end_
