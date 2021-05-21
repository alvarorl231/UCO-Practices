#   Haz un script que permita encontrar una contraseña a partir de su hash SHA-256. Se sabe que
# la contraseña es un número hexadecimal (0-9, A-F) y que su longitud no es superior a 5 caracteres.
# El script deberá probar todas las combinaciones posibles hasta encontrar la clave.
# Para generar el hash de una cadena puedes utilizar:
#       echo "cadena" | sha256sum
#   Se recomienda utilizar el operador brace expansion para generar las diferentes combinaciones.
# Para expandir una expresi ón que se encuentre en una variable, puedes hacerlo de la siguiente
# forma:
#       eval echo $string
#   El hash proporcionado se encuentra dentro del fichero hash.txt que se proporciona junto
# con la práctica.


#!/bin/bash

# Aquí obtenemos el hash del fichero de texto
#while read -r linea; 
#do
#   lfich=$(echo -e $linea)
#done < hash.txt


# Esta podría ser otra forma
lfich=$(cat "hash.txt")                    #cut sirve para eliminar elementos de un texto. como en el txt es "" blablabla - " 
                                           #queremos eliminar espacios y guion para quedarnos con blablabla
                                           #asique decimos cut, -d que es el delimitador y le decimos que use el espacio,
                                           # y usando -f le decimos que queremos que retorne el elemento 1 (el texto)


# Ahora probamos todos las combinaciones posibles

echo "Probando 16 combinaciones de longitud 1"
for x in $(eval echo {{0..9},{A..F}})
do
    prueba=$(echo $x | sha256sum)
    if [ "$lfich" == "$prueba" ]
    then 
        echo "Se ha encontrado la contraseña, es $x!!"
        exit -1
    fi

done

echo "Probando 256 combinaciones de longitud 2"
for x in $(eval echo {{0..9},{A..F}}{{0..9},{A..F}})
do
    prueba=$(echo $x | sha256sum)
    if [[ $lfich == $prueba ]]
    then 
        echo "Se ha encontrado la contraseña, es $x!!"
        exit -1
    fi

done


echo "Probando 4096 combinaciones de longitud 3"
for x in $(eval echo {{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}})
do
    prueba=$(echo $x | sha256sum)
    if [[ $lfich == $prueba ]]
    then 
        echo "Se ha encontrado la contraseña, es $x!!"
        exit -1
    fi

done


echo "Probando 65536 combinaciones de longitud 4"
for x in $(eval echo {{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}})
do
    prueba=$(echo $x | sha256sum)
    if [[ $lfich == $prueba ]]
    then 
        echo "Se ha encontrado la contraseña, es $x!!"
        exit -1
    fi

done



echo "Probando 1048576 combinaciones de longitud 5"
for x in $(eval echo {{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}}{{0..9},{A..F}})
do
    prueba=$(echo $x | sha256sum)
    if [[ $lfich == $prueba ]]
    then 
        echo "Se ha encontrado la contraseña!!"
        exit -1
    fi

done