#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "oneIterationGTemp"
set key right bottom
set xlabel "Num. Iteracion"
set ylabel "Current Solution"
plot 'unaIteracionGrande.txt' using 1:4 t "Current" w l
_end_
