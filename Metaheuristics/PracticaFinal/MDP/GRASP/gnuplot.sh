#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "GRASP50.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
set logscale x
plot 'grasp50_1.txt' using 1:2 t "GRASP" w l
_end_