#!/bin/bash
#Date: 07/Oct/15.
#Busca una palabra en un archivo.

echo -n "Ingrese la palabra a buscar: "
read nameWord

echo -n "Ingrese el nombre del archivo: "
read nameFile

if grep $nameWord $nameFile >/dev/null
	then
	echo $nameWord "! sí existe!"
	else
	echo $nameWord "! no existe!"
fi
