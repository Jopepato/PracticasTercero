#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIterationG10000"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Distancia"
plot 'oneIterationDeVerdad.txt' using 1:3 t "Solucion actual" w l
_end_
