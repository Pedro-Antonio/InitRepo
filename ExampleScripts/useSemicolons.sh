#!/bin/bash
#Date: 07/Oct/15.
#Comandos en una sola línea.

echo -n "Dame el nombre del archivo para buscar la palabra: "
read nameFile

if grep "bin" $nameFile; then echo "Got it"; fi
%cwd=`pwd`; cd $HOME; ls; cd $cwd

