#   Crear un script que reciba como único argumento obligatorio un fichero de texto que contendrá 
# una serie de posibles contraseñas, una por cada l´ınea. El programa deberá evaluar todas
# las contraseñas para determinar su seguridad. Esta seguridad se indicará con un número de puntos.
# Los factores a tener en cuenta para su evaluación son los siguientes:
#       1. Si la longitud de la contraseña es menor de 5, la contraseña no es segura y deberá tener
#   siempre 0 puntos.
#       2. A partir de longitud 8, se sumarán 5 puntos.
#       3. A partir de longitud 15, en lugar de 5, se sumarán 20 puntos.
#       4. Si contiene al menos 1 letra minúscula, se suman 10 puntos.
#       5. Si contiene al menos 1 letra mayúscula, se suman 10 puntos.
#       6. Si contiene al menos 1 número, se suman 5 puntos.
#       7. Si contiene alg ún carácter especial, se suman 15 puntos.
#       8. Adicionalmente, se sumará 1 punto por cada número, 2 puntos por cada letra y 3 puntos
#   por cada s´ımbolo que contenga.
#   La salida del programa debe estar en formato tabla y debe contener las columnas:
#       - Contraseña.
#       - Número de letras minúsculas.
#       - Número de letras mayúsculas.
#       - Cantidad de núneros.
#       - Número de caracteres especiales.
#       -  Puntuación total.
#   Además, la salida deberá estar ordenada de forma descendente por el número de puntos. Se
# proporciona el fichero de ejemplo pass.txt para probar el script.

#! /bin/bash

if [ $# != 1 ]
then
	echo "./<ejecutable> <fichero>"
	exit 1
fi

echo -e "\t  Contraseña\t\tMinusculas\tMayusculas\tNúmeros\t\tSímbolos\tPuntos"
echo -e "\t===================================================================================================== "

for x in $(cat $1)
do	
    # Almaceno las contraseñas. Elimino los espacios de las contraseñas
	pass=$(echo "$x" | tr -d "\n")

    # Almaceno el número de minúsculas.
	min=$(echo  "$x" | grep -o -E '[a-z]+' | tr -d "\n" | wc -c ) 

    # Almaceno el número de mayúsculas.
    may=$(echo  "$x" | grep -o -E '[A-Z]+' | tr -d "\n" | wc -c )
    
    # Almaceno el número de números.
    num=$(echo  "$x" | grep -o -E '[0-9]+' | tr -d "\n" | wc -c )
    
    # Almaceno el número de símbolos.
    simb=$(echo  "$x" | grep -o -E '[[:punct:]]+' | tr -d "\n" | wc -c  )


    # Creo la variable suma, la cuál por cada variable suma su puntiación y el total=0
	let "suma = $min + $may + $num + $simb "
	let total=0


    # Si se encuentra en el rango de <5, obtiene 0 puntos
	if [ $suma -lt 5 ]
	then
		total=0
	fi

    # Si se encuentra entre 8 y 15 obtiene 5 puntos
	if [ $suma -gt 8 ] && [ $suma -lt 15 ]
	then
		total=5
	fi


    # Si se encuentra en el rango de >15, obtiene 20 puntos
	if [ $suma -gt 15 ]
	then
		total=20
	fi


    # Si existe al menos una letra minúscula, se le dan 10 puntos, si existen más de una, se suman.
	if [ $min -gt 0 ] # MINUSCULAS
	then
		let "total = $total + 10 "
		let "total = $total + $min*2 "
	fi
	

    # Si existe al menos una letra mayúsculas, se le dan 10 puntos, si existen más de una, se suman.
	if [ $may -gt 0 ] #MAYUSCULAS
	then
		let "total = $total + 10 "
		let "total = $total + $may*2 "
	fi
    
    
    # Si existe al menos un número, se le dan 5 puntos, si existen más de una, se suman.
	if [ $num -gt 0 ] #NUMEROS
	then
		let "total = $total + 5 "
		let "total = $total + $num "
	fi	
    
    
    # Si existe al menos un símbolo, se le dan 15 puntos, si existen más de una, se suman.
	if [ $simb -gt 0 ] ##simbolos
	then
		let "total = $total + 15 "
		let "total = $total + $simb*3 "
	fi


    # Uso de pritnf para imprimir de una manera ordenada
	printf " %23s \t    %3d \t %3d \t\t %3d \t\t %3d \t\t %3d\n" $pass $min $may $num $simb $total

done | sort -k 6 -n -r