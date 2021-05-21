# Esto es un comentario!!


#!/bin/bash          Esto sirve para el intérprete de comandos
echo "Hola Mundo"


# Estos son los distintos tipos de saltos de linea
echo "Imprimo una línea con salto de línea"

echo -e "Imprimo una línea sin salto de línea"

echo "ho\nla"

echo -e "ho\nla"


# Variables:
cadena="Hola Mundo!"

echo $cadena


# Variables de entorno:
PS1=" ~(hola, son las \t) &"
echo $PS1
echo "Bienvenido $USER!, tu identidicador es $UID."
echo "Esta es la shell número $SHLVL, que lleva $SECONDS."
echo "La arquitectua de esta máquina es $MACHTYPE y el cliente de terminal es $TERM"

#Varíables intrínsecas:
echo "$#, $0; $1; $2; $*; $@"

#Comando READ:
read nombre
read -s -t5 -n1 -p " si ( S ) o no ( N ) ? "

#Sustitución de comandos
LISTA=`ls`
echo $LISTA

LISTA=$(ls)

#Operadores aritméticos
+ suma
- resta
* multiplicación
/ división
** exponenciación
% modulo

let x=10+2*7
echo $x
24


echo "$((123+100))"
echo "$[123+100]"
echo $[123+100]

#Condicionales IF
if [ expresión ];
then
instrucciones
elif [ expresión ];
then
instrucciones
else
instrucciones
fi

#Comparación de CADENAS
s1 == s2        Igual a
s1 != s2        Distinto a
-n s            Longitud mayor que cero
-z s            Longitud igual a cero


#Comparación de NÚMEROS
Operador        Significado
n1 -lt n2       Menor que
n1 -gt n2       Mayor que
n1 -le n2       Menor o igual que
n1 -ge n2       Mayor o igual que
n1 -eq n2       Igual
n1 -ne n2       Distinto

#Chequeo de FICHEROS
Operador        Significado
s1 == s2        Igual a
s1 != s2        Distinto a
-n s            Longitud mayor que cero
-z s            Longitud igual a cero

#Operadores LÓGICOS
Operador    Significado
!           No
&& o -a     Y
|| o -o     O

1 if [ $n1 -ge $n2 ] && [ $s1 = $s2 ];
2 ...
3 if [ $n1 -ge $n2 -a $s1 = $s2 ];
4 ...


#Condicionales CASE
case $var in
    val1)
        instrucciones;;
    val2)
        instrucciones;;
    *)
        instrucciones;;
esac

#Estructuras iterativas FOR
for var in lista
do
instrucciones ;
done

# Para usar los argumentos como in
# no se pone in

    for var 
        do
        .
        .
    done


#Comando FIND
find -name "*.sh"


#ARRAYS
Para crear arrays: miNuevoArray[i]=Valor.
Para crear arrays: miNuevoArray=(Valor1 Valor2 Valor3).
Para acceder a un valor: ${miNuevoArray[i]}.
Para acceder a todos los valores: ${miNuevoArray[*]}.
Para longitud: ${#miNuevoArray[@]}.


#WHILE
while expresion_evalua_a_true
do
instrucciones
done


#UNTIL
until expresion_evalua_a_true
do
instrucciones
done


#FUNCIONES EN BASH

#!/ bin / bash
hola ()
{
    echo " Estás dentro de la función hola () y te saludo ."
}

echo "La próxima línea llama a la función hola ()"
hola
echo " Ahora ya has salido de la funcion "


#TUBERÍAS

