#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "Prueba_200Iteraciones.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Valor mochila"
plot 'fichero_200.txt' using 1:4 t "Primera Mejora" w l, 'fichero_200.txt' using 1:8 t "Mejor Mejora" w l
set output "Prueba_200Tiempo.eps"
set xlabel "Tiempo (microsegundos) "
plot 'fichero_200.txt' using 7:4 t "Primera Mejora" w l, 'fichero_200.txt' using 11:8 t "Mejor Mejora" w l
_end_