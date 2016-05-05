#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "52hormiPrueba0.3"
set key right bottom
set xlabel "Num. Evaluaciones"
set ylabel "Distancia"
plot 'pruebaSoluciones52.txt' using 1:2 t "Hormiga 1" w l, 'pruebaSoluciones52.txt' using 1:3 t "Hormiga 2" w l, 'pruebaSoluciones52.txt' using 1:4 t "Hormiga 3" w l, 'pruebaSoluciones52.txt' using 1:5 t "Hormiga 4" w l, 'pruebaSoluciones52.txt' using 1:6 t "Hormiga 5" w l
_end_
