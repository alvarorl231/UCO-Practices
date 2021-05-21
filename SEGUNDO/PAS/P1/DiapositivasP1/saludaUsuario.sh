#!/bin/bash

read -p "Introduzca su nombe de usuario: " nombre

if [ $nombre == $LOGNAME ]
    then
    echo "Bienvenido $nombre"
else
    echo "ERROR, no es el mismo nombre de usuario."
fi