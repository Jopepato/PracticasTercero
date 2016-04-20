#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "fiftyIterationG"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Distancia"
plot 'fiftyIterationsG.txt' using 1:2 t "Solucion final" w l, 'fiftyIterationsG.txt' using 1:3 t "Solucion optima" w l
_end_
