#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "ILS50.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Distancia recorrida"
plot 'ILS500.txt' using 1:2 t "Primera Mejora" w l, 'ILS500.txt' using 1:3 t "Mejor Mejora" w l
_end_