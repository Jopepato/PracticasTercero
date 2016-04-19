#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIterationGTemp"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Temperatura"
plot 'a.txt' using 1:2 t "Temperatura" w l,  'a.txt' using 1:4 t "Tiempo Estimado Burbuja" w l 
_end_
