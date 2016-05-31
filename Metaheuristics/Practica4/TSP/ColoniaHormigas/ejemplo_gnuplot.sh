#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "150mejor"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
set logscale x
plot 'mejores150.txt' using 1:2 t "Mejor" w l,

set output "150hormigas"
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
set nologscale x
plot 'hormigas150.txt' using 1:2 t "Mediana" w l

set output "Camino1_150"
set xlabel "Nodo x"
set ylabel "Nodo y"
plot 'caminos150.txt' using 1:2 t "Camino" w l

set output "Camino2_150"
set xlabel "Nodo x"
set ylabel "Nodo y"
plot 'caminos150.txt' using 3:4 t "Camino" w l

_end_
