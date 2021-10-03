#   Desarrolla un script que consulte el fichero /etc/passwd y utilice los comandos grep y sed
# para:
#       1. Mostrar aquellos usuarios que tengan asignado un intérprete de comandos válido.
#       2. Mostrar aquellos usuarios que tengan un directo home asignado.
#       3. Mostrar los usuarios y el nombre de su grupo principal en dos columnas, como se muestra
#   en el ejemplo. Si un usuario no tiene ning ún grupo asignado, deberá mostrar un guion en
#   la posición correspondiente.


#!/bin/bash

echo -e "1) Mostrar los usuarios que tengan un intérprete de comandos válido asignado:\n\n"
cat /etc/passwd | grep -E '.sh$'
cat /etc/passwd | grep -v /bin/false | grep -v /nologin
#cat /etc/passwd | sed -r -n -s -e 's/([a-Z0-9:/,()_-]+.sh$)/\1/p'


echo -e "\n2) Mostrar los usuarios que tengan un home válido asignado:\n\n"
#-v en grep muestra las líneas contrarias al patrón a buscar
cat /etc/passwd | grep -E -v './nonexistent.'



echo -e "\n3) Mostrar los usuarios y el nombre de su grupo en dos columnas:\n\n"

echo -e "Usuario\t\t\t\t\tGrupo"
echo "======================================================================="
cat /etc/group | sed -r -n -s -e 's/([a-z-]+):x:[0-9]+:*/\1\t\t\t\t\1/p'
cat /etc/passwd | sed -r -n -s -e 's/([a-Z0-9:/,()_-]+):[a-Z0-9:/,()_-]+:[a-Z0-9:/,()_-]+:[0-9][0-9][0-9][0-9][0-9]:[a-Z0-9:/,()_-]+/\1\t\t\t\t\-/p'

# Otra manera de hacerlo:
# while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
# do 
#   printf "%20s %20s\n" $f1 $f5
# done < /etc/passwd