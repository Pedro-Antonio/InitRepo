#!/bin/bash
#Date: 05/Oct/15.
#Determina si un archivo o directorio lo localiza en este directorio.

echo -n "Dame el nombre del archivo a buscar: "
read nombre
if ls $nombre >/dev/null 2>/dev/null
	then
	echo "El archivo o directorio sí existe!"
	else
	echo "El archivo o directorio no existe!"
fi
