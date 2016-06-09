#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "SA150_1_sinLog.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Diversidad"
plot 'SA150_1.txt' using 1:2 t "Temperatura" w l
_end_
