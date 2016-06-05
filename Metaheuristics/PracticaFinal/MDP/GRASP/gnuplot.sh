#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "GRASP50.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'prueba.txt' using 1:2 t "graspito" w l, 'prueba.txt' using 1:3 t "siguiente" w l
_end_