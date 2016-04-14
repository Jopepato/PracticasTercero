#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "Prueba2103Iteraciones.eps"
set key right bottom
set xlabel "Numero de iteraciones"
set ylabel "Distancia recorrida"
plot 'fichero2103.txt' using 1:3 t "Primera Mejora" w l, 'fichero2103.txt' using 1:6 t "Mejor Mejora" w l
set output "Prueba2103Tiempo2.eps"
set xlabel "Tiempo (microsegundos) "
plot 'fichero2103.txt' using 5:3 t "Primera Mejora" w l
_end_