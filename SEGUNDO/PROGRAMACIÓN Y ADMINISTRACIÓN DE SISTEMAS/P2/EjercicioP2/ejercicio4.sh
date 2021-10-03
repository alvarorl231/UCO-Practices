#   Crea un script que proporcione información acerca del uso de memoria del equipo. Puedes utilizar
# los comandos grep y sed para obtener la información necesaria del fichero /proc/meminfo.
# El script debe mostrar por pantalla la siguiente información:
#       1. Memoria total.
#       2. Memoria libre.
#       3. Memoria disponible.
#       4. Memoria en uso como caché de disco.
#       5. Tama˜no total de la memoria swap.
#       6. Memoria swap libre.
#   Además, el script recibirá un argumento númerico opcional. Este argumento, cuyo valor por
# defecto será 10, se utilizará para mostrar el Top-N procesos que más memoria están utilizando.
# Para ello, puedes utilizar la salida del comando ps aux.


#!/bin/bash

if [ $# -ne 1 ] || [ $1 -lt 5 ]
then
    echo "./<ejecutable> <numero>  ó el numero es <5"
    exit -1
fi

#cat /proc/meminfo | grep --color -E '^MemTotal:+[ \n]+[0-9]+[ \t]+kB'
cat /proc/meminfo | sed -r -n -s -e 's/^MemTotal:+[ \n]+([0-9]+[ \t]+kB)/Memoria total: \1/p'
cat /proc/meminfo | sed -r -n -s -e 's/^MemFree:+[ \n]+([0-9]+[ \t]+kB)/Memoria libre: \1/p'
cat /proc/meminfo | sed -r -n -s -e 's/^MemAvaiable:+[ \n]+([0-9]+[ \t]+kB)/Memoria disponible: \1/p'
cat /proc/meminfo | sed -r -n -s -e 's/^Cached:+[ \n]+([0-9]+[ \t]+kB)/Memoria usada como caché de disco: \1/p'
cat /proc/meminfo | sed -r -n -s -e 's/^SwapTotal:+[ \n]+([0-9]+[ \t]+kB)/Tamaño de la memoria swap: \1/p'
cat /proc/meminfo | sed -r -n -s -e 's/^SwapFree:+[ \n]+([0-9]+[ \t]+kB)/Memoria swap libre: \1/p'


echo -e

aux=$1
if [ $aux -lt 10 ]
then
    aux=10
else
    aux=$1
fi

echo "Top-$aux  procesos en uso de memoria."
echo "=================================================================="
echo "Usuario                 %Uso                      Proceso"
echo "=================================================================="

# He encontrado esto en internet que sirve
ps aux --sort -rss | awk 'NR>1{print $1,"\t \t \t" $4, "\t \t \t   " $11}' | head -n $aux

# Usando esto podríamos llegar a la solución pero se queda lejos
#ps aux | grep --color -E '[a-Z0-9]+[ \t]+[0-9]+[ \t]+[0-9.]+[ \t]+[0-9.]+[ \t]+[0-9]+[ \t]+[0-9]+[ \t]+[?a-z0-9][ \t]+[a-Z<>+]+[ \t]+[0-9:]+[ \t]+[0-9:]+[ \t]+[a-Z0-9/#.) =(-:_]+'
#ps aux | sed -r -n -s -e '2,$s/([a-Z0-9]+)[ \t]+[0-9]+[ \t]+[0-9.]+[ \t]+([0-9.]+)[ \t]+[0-9]+[ \t]+[0-9]+[ \t]+[?a-z0-9][ \t]+[a-Z<>+]+[ \t]+[0-9:]+[ \t]+[0-9:]+[ \t]+([a-Z0-9/#.) =(-:_]+)/\1\t\2\t\3\t/p'

