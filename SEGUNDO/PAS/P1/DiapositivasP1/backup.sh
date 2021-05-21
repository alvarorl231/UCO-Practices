#!/bin/bash

nombre=$1
fecha=`date +%d-%m-%y`
nuevo=$nombre.bak_$fecha

if [ -e $nombre ]
then
    cp $nombre $nuevo
    echo "Fichero copiado y renombrado con éxito."
else
    echo "El fichero no existe"
fi