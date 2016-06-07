#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "ILS150FI.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'ILS150.txt' using 1:2 t "Primera mejora actual" w l, 'ILS150.txt' using 1:4 t "Mejor solucion" w l
_end_