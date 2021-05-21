#!/bin/bash

echo -n "Introduce el nombre del fichero a borrar (incluye .XXX): "
read nombre
rm -i $nombre 
echo "¡¡Fichero $nombre borrado con éxtio!!"

echo "Usando READ de otra forma: "

read -s -t5 -n1 -p " si ( S ) o no ( N ) ? "