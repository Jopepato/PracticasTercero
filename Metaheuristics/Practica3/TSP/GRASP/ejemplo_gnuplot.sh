#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "50itGraspG"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
plot '50itGraspG.txt' using 1:2 t "Mejor distancia" w l
_end_
