#!/bin/bash -x

read -p "Introduzca un número: " num

let sum=0

for (( i=0 ; $i<=$num ; i=$i+1 )) ;
do
    let "sum = $sum + $i"
done

echo "La suma de los $x primeros números es: $sum"