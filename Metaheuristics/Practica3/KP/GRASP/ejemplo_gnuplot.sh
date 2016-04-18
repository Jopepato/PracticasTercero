#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIterationGTemp"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Temperatura"
plot 'kk3.txt' using 1:2 t "Temperatura" w l
_end_
