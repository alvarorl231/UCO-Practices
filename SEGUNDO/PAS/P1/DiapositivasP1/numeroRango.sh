#!/bin/bash

read -p "Introduzca un número (1 <= x < 10): " numero

if [ $numero -ge 1 ];
then
    if [ $numero -le 9 ];
        then
        echo "El número $numero es correcto!!"
        else
        echo "El número no está en el rango"
    fi
else
    echo "El número no está en el rango"
fi


echo -e "\n Otra forma de hacerla: \n"
read -p "Introduzca un número (1 <= x < 10): " numero

if [ $numero -ge 1 ] && [ $numero -lt 10 ]
then
    echo "El número $numero es correcto!"
else
    echo "El número queda fuera de rango"
fi