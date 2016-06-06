#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "GRASP150.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'grasp150_1.txt' using 1:2 t "GRASP" w l
_end_