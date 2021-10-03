#!/bin/bash

function chequea()
{
    if [ -e "$1" ]
    then
        return 0
    else
        return 1
    fi
}


read -p "ntroduzca el nombre del archivo: " nombre

if chequea $nombre
then
    echo "El archivo $nombre existe !"
else
    echo "El archivo $nombre no existe !"
fi