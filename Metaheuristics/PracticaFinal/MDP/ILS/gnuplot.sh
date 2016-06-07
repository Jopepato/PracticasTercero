#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "ILS100BI.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'ILS100.txt' using 1:3 t "Mejor Mejora actual" w l, 'ILS100.txt' using 1:5 t "Mejor solucion" w l
_end_