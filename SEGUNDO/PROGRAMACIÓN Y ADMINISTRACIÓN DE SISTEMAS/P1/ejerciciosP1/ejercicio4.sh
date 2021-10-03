#   Crea un script que te permita abrir una terminal con un prompt personalizado modificando
# la variable PS1. La personalizacion del prompt se hará de forma interactiva mediante un menú
# de opciones. Se recomienda el uso de funciones para organizar el código. El menú permitirá ir
# añadiendo las diferentes variables que existen para el prompt, tales como:
# - Nombre de usuario.
# - Nombre de host.
# - Ruta completa.
# - Última parte de la ruta.
# - Hora.
# - Fecha.
#   Además, también deberá existir la opción de añadir una cadena literal. Cada vez que se añada
# un elemento, se mostrará por pantalla el estado actual del prompt que estamos creando. El menú
# debe tener una opción para confirmar y abrir bash con el prompt personalizado y otra para salir
# sin hacer nada. Cuando cerremos la sesi ón personalizada de bash, se terminará el script también
# y el prompt permanecerá como estaba antes de ejecutar el script. Para abrir una instancia de bash
# modificando temporalmente la variable PS1, puedes utilizar:
# 
# PROMPT_COMMAND="PS1='MiPromptPersonalizado';unset PROMPT_COMMAND" bash
# 
#   Se trata de una variable de entorno que proporciona bash y que se ejecuta justo antes de mostrar
# el prompt. Si intentamos modificar directamente la variable PS1 sin utilizar la variable PROMPT
# COMMAND, es posible que el prompt no se modifique debido a que al iniciar una sesi ón de bash, el
# archivo .bashrc se carga y se anula la modificación que hayamos hecho.


#!/bin/bash


#Vamos a crear tantas funciones como posibilidades de modificar el prompt hay
function username()
{
    actualPrompt=$actualPrompt"\u"
}

function hostname()
{
    actualPrompt=$actualPrompt"\h"
}


function rutacompleta()
{
    actualPrompt=$actualPrompt"\w"
}

function ruta()
{
    actualPrompt=$actualPrompt"\W"
}

function hora()
{
    actualPrompt=$actualPrompt"\t"
}

function fecha()
{
    actualPrompt=$actualPrompt"\d"
}

function cadena()
{
    read x 
    actualPrompt=$actualPrompt$x
}

# Función sobre el color y estilo, la cual introduce 3 case
function colorystyle()
{
    echo "=== Configurar colores y estilos ==="
    echo "- Tipo de fuente -"
    echo "1. Normal"
    echo "2. Negrita"
    echo "3. Subrayado"
    read x

    case $x in
        1) actualPrompt=$actualPrompt"\e[0;";;
        2) actualPrompt=$actualPrompt"\e[1;";;
        3) actualPrompt=$actualPrompt"\e[4;";;
        *) echo "No se encuentra ese valor."
            actualPrompt=$actualPrompt$x; ;;
    esac


    echo "- Color de fuente -"
    echo "1. Negro"
    echo "2. Rojo"
    echo "3. Verde"
    echo "4. Amarillo"
    echo "5. Azul"
    echo "6. Blanco"
    read x

    case $x in
        1) actualPrompt=$actualPrompt"30;";;
        2) actualPrompt=$actualPrompt"31;";;
        3) actualPrompt=$actualPrompt"32;";;
        4) actualPrompt=$actualPrompt"33;";;
        5) actualPrompt=$actualPrompt"34;";;
        6) actualPrompt=$actualPrompt"37;";;
        *) echo "No se encuentra ese valor.";;
    esac


    echo "- Color de fondo -"
    echo "1. Negro"
    echo "2. Rojo"
    echo "3. Verde"
    echo "4. Amarillo"
    echo "5. Azul"
    echo "6. Blanco"
    read x

    case $x in
        1) actualPrompt=$actualPrompt"40m";;
        2) actualPrompt=$actualPrompt"41m";;
        3) actualPrompt=$actualPrompt"42m";;
        4) actualPrompt=$actualPrompt"43m";;
        5) actualPrompt=$actualPrompt"44m";;
        6) actualPrompt=$actualPrompt"47m";;
        *) echo "No se encuentra ese valor.";;
    esac

}

# Para poner la parte izquierda del prompt en color, deberiamos de encerrarlo entre \e[ .... \e[m


opcion=1

# While en el que estaremos hasta pulsar un número incorrecto o Cancelar o COnfirmar
while [ $opcion -le 9 ];
do

echo "=== Personalización del Prompt ==="
echo "Selecciona una opción para añadirle al prompt:"
echo "1. Nombre de usuario"
echo "2. Nombre de host"
echo "3. Ruta completa"
echo "4. Última parte de la ruta"
echo "5. Hora"
echo "6. Fecha"
echo "7. Cadena literal"
echo "8. Añadir color y estilo"
echo "9. Cancelar"
echo "0. Confirmar"

read opcion

    case $opcion in
        0) echo "Cambios Confirmandos: "
        break;;
        1) username;;
        2) hostname;;
        3) rutacompleta;;
        4) ruta;;
        5) hora;;
        6) fecha;;
        7) cadena;;
        8) colorystyle;;
        9) echo "Cancelando y saliendo."
            exit -1;;
        *) echo "Valor no reconocido, saliendo."
            exit -1;;
    esac

    echo "PROMPT ACTUAL: $actualPrompt"

done

#Aquí mostramos el prompt final
echo -e "\n"
PROMPT_COMMAND="PS1='$actualPrompt';unset PROMPT_COMMAND" bash