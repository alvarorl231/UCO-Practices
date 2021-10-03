# Desarrolla un script que reciba como argumentos obligatorios un directorio y un número entero
# N. El script deberá dividir los ficheros que se encuentren dentro de dicho directorio en N
# partes iguales por orden alfabético. Los subdirectorios no se tomarán en cuenta, ni tampoco los
# ficheros que se encuentren dentro de los subdirectorios. Cada grupo de ficheros se copiará en
# una carpeta diferente cuyo nombre incluirá el número del grupo correspondiente. Si el número
# de ficheros es demasiado peque˜no como para hacer N grupos, el script deberá devolver un error
# y no hacer nada.
# Nota: para dividir una lista de ficheros en grupos de tamaóo N puedes utilizar el comando
# xargs -n $N. Si lo necesitas, busca algo más de información acerca de este comando.
# Un ejemplo de ejecuci ón sería el siguiente:



#!/bin/bash

# Control de argumentos 
if [ $# -gt 2 ] || [ $# -lt 2 ]
then
    echo -e "\n     Debes de intrpducir ./<ejecutable> <directorio> <numero> \n"
    exit 1
fi

# Comprobación de que el segundo argumento es un directorio
if [ ! -d $1 ];
    then
    echo "Error, $1 no es un directorio"
    exit
fi

# Contamos cuantos fucheros existen en la carpeta y hacemos un echo inicial mostrando datos
fich=0
for x in $1/*
do
    let "fich=$fich+1" 
done
grupos=$(($fich/$2))
echo "$fich files, $2 groups -> groups of size $grupos"

# Control del tercer argumento, nos aseguramos de crear grupos equitativos
if [ $(($fich%$2)) -ne 0 ] || [ $fich -lt $2 ]
then
    echo -e "\n    El número debe ser divisible entre $fich ó estás diviendo en más carpetas de lo posible.\n"
    exit 1
fi


#Creamos la carpeta y las subcarpetas con sus copias correspondientes
$(rm -r -f groups)
$(mkdir groups)
cont=0
for x in $1/*
do
    d=$(pwd)/groups/group$(printf %01d $((cont/$grupos+1)) )
    mkdir -p $d
    cp "$x" $d;
    let "cont=$cont+1"
done

echo "Hecho!"
