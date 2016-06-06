#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafica.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Distancia recorrida"
plot 'output.txt' using 1:2 t "Primera Mejora" w l, 'output.txt' using 1:3 t "Mejor Mejora" w l
_end_