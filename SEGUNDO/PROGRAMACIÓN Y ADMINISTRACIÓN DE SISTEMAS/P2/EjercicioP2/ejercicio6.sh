#   Desarolla un script que muestre por pantalla información acerca de los sistemas de archivos
# que hay montados. Para ello, puedes utilizar el comando df. La información que se mostrará
# sera la siguiente:
#       1. Sistema de ficheros.
#       2. Punto de montaje.
#       3. Tamaño.
#       4. Espacio libre.
#       5. Porcentaje de uso.
#   La salida deberá estar en un formato similar al que se muestra en el siguiente ejemplo:


#!/bin/bash

# Tubería entre df y grep para mostrar en color que estamos usando lo correcto.
# df | grep --color -E '(^[a-Z0-9/]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9%]+)[ \t]+([a-Z0-9/]+)$'

# Tuberia entre df y sed para mostrar la salida como deseamos
df | sed -r -n -s -e '2,$s/(^[a-Z0-9/]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9]+)[ \t]+([0-9%]+)[ \t]+([a-Z0-9/]+)$/El sistema de ficheros \1 está montado en \6 y tiene un tamaño de \2, de los cuales se están usando \3, que representan un \5 del total. Quedan libres \4./p' 
