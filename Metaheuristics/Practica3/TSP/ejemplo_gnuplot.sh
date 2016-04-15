#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIterationM"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Distancia"
plot 'kk2.txt' using 1:4 t "Distancia" w l
_end_
