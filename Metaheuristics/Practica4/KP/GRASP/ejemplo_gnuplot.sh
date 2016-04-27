#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "10000evaluationsG"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Valor"
plot 'prueba3.txt' using 1:2 t "Precio mochila actual" w l
_end_
