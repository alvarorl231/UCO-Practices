#!/bin/bash

echo -n "Introduce un primer número: "
read n1

echo -n "Introduce un segundo número: "
read n2

echo "Suma: $[$n1+$n2]"
echo "Resta: $[$n1-$n2]"
echo "Multiplicación: $[$n1*$n2]"
echo "División: $[$n1/$n2]"
echo "Módulo: $[$n1%$n2]"