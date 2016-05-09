#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "52mejor"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
plot 'prueba52.txt' using 1:2 t "Mejor" w l,

set output "52hormigas"
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
plot 'hormigas52.txt' using 1:2 t "Mediana" w l

_end_
