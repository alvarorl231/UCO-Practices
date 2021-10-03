#!/bin/bash

echo "Bienvenido $USER!, tu identidicador es $UID."
echo "Esta es la shell número $SHLVL, que lleva $SECONDS."
echo "La arquitectua de esta máquina es $MACHTYPE y el cliente de terminal es $TERM"

echo -e "\nOtra forma de hacerlo:\n"

cad1="Bienvenido $USER!, tu identificador es $UID."
cad2="Esta es la shell número $SHLVL, que lleva $SECONDS arrancada."
cad3="La arquitectura de esta máquina es $MACHTYPE y el cliente de terminal es $TERM"
echo -e "$cad1\n$cad2\n$cad3" 


echo -e "\npersonaliza el prompt para que adquiera este aspecto: ~( hola , son las 11:16:30) & \n"

PS1=" ~(hola, son las \t) &"
echo $PS1