# Crear un script que permita automatizar un sistema de copias de seguridad. El sistema deberá
# funcionar de la siguiente forma:
# Recibirá 3 parámetros obligatorios: carpeta de origen, carpeta de destino y un número
# entero N.
# Se guardarán un máximo de N copias, de manera que cuando haya N y se quiera hacer
# una nueva, se deberá borrar la más antigua.
# Las copias se almacenarán en subdirectorios dentro del directorio de destino siguiendo la
# numeración 1; 2; 3; :::;N. La copia más antigua siempre estará en el subdirectorio 1.
# Cuando una copia antigua se borre, se deberán renombrar el resto de directorios para seguir
# manteniendo la copia más antigua en el 1.
# A continuación se muestra un ejemplo en el que se ejecuta el script varias veces, partiendo de
# un directorio de backups vacío.




#!/bin/bash


# Control de argumentos. Si el numero de argumentos es distinto de 4 -> mensaje de error. (comienza en 0)
if [ $# -ne 3 ]
then
    echo -e "\n    Debes de introducir ./<ejecutable> <directorio> <carpeta copia> <numero> \n"
    exit 1
fi

# Si la carpeta $1 no existe, -> mensaje de error
if [ ! -d $1 ]
    then
    echo "El argumento <$1> no es una carpeta valida"
    exit
fi


# Si la carpeta $2 no existe -> se crea.  Si existe -> mensaje de error.
if [ ! -d $2 ]
then 
    $(mkdir $2)
fi

# Creación de carpetas de modo que si i<N para.
for (( i=1; $i<$(($3+1)); i=$i+1 ))
do
    # Si no existe el directorio $2/$i -> se crea
    if [ ! -d $2/$i ];
    then
        for x in $1/*
        do 
            d=$(pwd)/$2/$i
            mkdir -p $d
            cp "$x" $d;
        done
    echo "Nueva copia creada en $2/$i"
    exit
    fi
done 

# Contador necesario para saber cuantas carpetas existen
cont=0
for (( i=1; $i<$(($3+1)); i=$i+1 ))
do
    let "cont=$cont+1"
done
 

# Si cont=$3 --> Borramos primera carpeta, renombramos las demás y creamos una nueva.
if [ $cont -eq $3 ]
then
    
    # ELiminamos la carpeta 1
    d=$(pwd)/$2/1
    $(rm -Rf $d)

    # Renombramos las carpetas
    for (( i=2; $i<=$3; i=$i+1 ))
    do
        $(mv $(pwd)/$2/$i $(pwd)/$2/$(($i-1)))  
    done

    # Copiamos los ficheros en la nueva carpeta
    d=$(pwd)/$2/$3
    for x in $1/*
    do 
        $(mkdir -p $d)
        $(cp "$x" $d)
    done

    echo "Copia 1 eliminada y creada nueva copia en $2/$3"
fi