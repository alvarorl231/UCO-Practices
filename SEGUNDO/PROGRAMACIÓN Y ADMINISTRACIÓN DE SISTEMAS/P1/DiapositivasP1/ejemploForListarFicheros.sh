#!/bin/bash

# Listar todos los ficheros del actual
# inclyendo informacióndel número de nodo.

for x in *
do
    ls -i $x
done 

# Listar todos los ficheros del directorio /bin

for x in /bin
do 
    ls -i $x
done