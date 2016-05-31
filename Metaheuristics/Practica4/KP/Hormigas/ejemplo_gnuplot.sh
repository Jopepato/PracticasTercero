#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "200mejor"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Precio"
set logscale x
plot 'mejores200.txt' using 1:2 t "Mejor" w l,

set output "200Hormigas"
set xlabel "Num. Evaluaciones"
set ylabel "Precio"
set nologscale x
plot 'hormigas200.txt' using 1:2 t "Mediana" w l
_end_
