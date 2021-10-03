#     Desarolla un script que reciba como argumento el nombre de un fichero de texto que contendrá
# diferentes nombres de dominio, uno por línea. El script deberá resolver los diferentes
# nombres de dominio y mostrar por pantalla la IP obtenida seguida del nombre de dominio que
# se proporcionaba.
#     Los resultados deberán estar formateados en dos columnas y ordenados seg ún la direcci ón
# IP, de manera que se respete el orden de las mismas (primero se ordena por la primera cifra de
# la ip, después por la segunda, por la tercera...). Por ejemplo, la IP 31.22.56.233 debe preceder a la
# 127.0.0.1.
#     Puedes usar el comando resolveip para resolver un dominio. Echa un vistazo a sus opciones.



#!/bin/bash

# Control de argumentos
if [ $# != 1 ]
then
    echo "./<ejecutable> <fichero>"
    exit 1
fi

# Leemos el fichero y mostramos la IP
while read line
do
    echo -e "$(resolveip -s $line)\t\t\t$line"
done < $1