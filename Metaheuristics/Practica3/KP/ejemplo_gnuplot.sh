#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "prueba2"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Valor actual"
plot 'prueba2.txt' using 1:4 t "..." w l
set output "ajusteInsercionBinaria"
_end_
