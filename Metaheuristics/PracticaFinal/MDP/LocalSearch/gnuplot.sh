#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "LS50BI.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
set logscale x
plot 'LS50.txt' using 1:3 t "Mejor Mejora (Change)" w l, 'LS50V2.txt' using 1:3 t "Mejor Mejora (Trunk)" w l
_end_