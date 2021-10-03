#!/bin/bash

echo "Usando comillas dobles:"
var="CADENA DE PRUEBA"
nuevaVar="Valor de var es $var"

echo $nuevaVar


#De otra manera... y usando las comillas simples:

echo "Usando ahora comillas simples:"
var="CADENA DE PRUEBA"
nuevaVar='Valor de var es $var'

echo $nuevaVar
