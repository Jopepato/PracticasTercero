#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "LS50.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'LS50.txt' using 1:2 t "Primera mejora" w l, 'random150.txt' using 1:3 t "Mejor mejora" w l
_end_