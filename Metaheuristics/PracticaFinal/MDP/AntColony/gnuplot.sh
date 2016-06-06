#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "Och150.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'sol150.txt' using 1:2 t "Mejor solucion" w l, 'horm150.txt' using 1:2 t "Mediana soluciones" w l
_end_