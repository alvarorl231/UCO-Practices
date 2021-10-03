#   Crea un script que proporcione información acerca de los usuarios que se encuentran conectados.
# Para ello, puedes utilizar la salida del comando w, y grep y sed para obtener los datos
# siguientes:
#       1. Nombre del usuario.
#       2. Hora a la que se ha conectado. Deberá estar formateada como HH:mm (p.ej.: 09:35).
#       3. Tiempo que lleva ausente. Deberá estar formateado como HH:mm:ii (p.ej.: 01:03:15).


#!/bin/bash

# Haciendo uso de SED
who | sed -r -n -s -e 's/([a-z]+)[ \t]+[a-z0-9]+[ \t]+[0-9:-]+[ \t]+([0-9:]+)[ \t]+([:)(0-9]+)/El usuario \1 lleva conectado desde las \2 y lleva ausente \3/p'

# Otra forma de realizarlo
#who | awk '{printf "El usuario " $1 " lleva conectado desde las " $4 " y lleva ausente " $5 "\n" }'
