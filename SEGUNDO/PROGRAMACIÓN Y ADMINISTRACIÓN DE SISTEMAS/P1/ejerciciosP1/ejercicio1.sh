# Desarrollar un script que reciba un único argumento que será un directorio. El script deberá
# imprimir el nombre de los ficheros y directorios que contenga el directorio especificado junto con
# la longitud de su nombre (sin incluir la ruta). Se incluirán también todos los subdirectorios. Se
# deberá mostrar en el formato que se indica en el siguiente ejemplo, teniendo en cuenta escribir
# carácter o caracteres en singular o plural dependiendo de si es uno o más.
# Nota: es posible que, dependiendo de la distribución y la versión de Linux que estés utilizando,
# la ordenación de la lista de ficheros no coincida con la que se muestra en la salida de
# ejemplo. Además, la ordenación por defecto de diferentes comandos como ls o find puede ser
# distinta. La diferencia en el orden no es relevante para el ejercicio, pero si quieres reproducir exactamente
# la salida de ejemplo, deberás utilizar find y ejecutar el script en tu sesión de la UCO
# (ts.uco.es).





#!/bin/bash

if [ $# != 1 ]
then
    echo "./<ejecutable> <directorio>"
    exit -1
fi

for x in $1/*
do

caract=$(echo -n $(basename $x) |wc -m)        # Con esto recogemos los caracteres de los archivos
    
    if [ $caract -eq 1 ]
    then
        echo "$(basename $x) <- $caract carácter"

    else

    #echo "$(basename $x)"                      # Muestra los nombres de los ficheros
    #echo $(echo -n $(basename $x) | wc -m)     # Muestra los carácteres a través de una tubería con wc -m 
    
    echo "$(basename $x) <- $caract caracteres"   #Salida final sin variable
    
    fi

done


echo -e "\n     Ahora vamos a proceder a mostrar una serie de datos: \n"


# Una vez mostrada la lista de todos los ficheros, se deberá mostrar, por otro lado, una serie de
# datos en aquellos ficheros o directorios en los que la longitud de su nombre sea impar:
# 1. Nombre del fichero (sin la ruta).
# 2. Ruta absoluta en la que se encuentra.
# 3. Número de i-nodo.
# 4. Tamaño del fichero en bytes y en kilobytes.
# 5. Permisos en formato octal.
# 6. Usuario y grupo al que pertenece.
# A continuación se muestra un ejemplo de la salida de esta segunda parte del script.


# MOstramos los siguientes datos que se nos ha pedido a través del comando stat y varios
for x in $1/*
do
caract=$(echo -n $(basename $x) |wc -m)

    if [ $(($caract%2)) -ne 0 ]
    then
        bytes=$(stat -c "%s" $x)
        kbytes=$(($bytes/1000))
        echo "$(basename $x), $(pwd)/$1, $(stat -c "i-node %i" $x), $bytes bytes ($kbytes kB), permiso $(stat -c "%a" $x) ($(stat -c "%U" $x) : $(stat -c "%G" $x)))"
    fi

done