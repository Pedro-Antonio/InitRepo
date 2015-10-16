#!/bin/bash
#Date: 16/Oct/15.

funcion2(){
if [ -f /bin/ls -a -f/bin/ln ] ; then
  return 0 #Ejecución exitosa, verdadera.
else
  return 1 #ejecución con error, no existosa, falsa.
fi
}

#Programa principal.
if funcion2 ; then
  echo "Los 2 archivos existen."
else
  echo "Falta al menos un archivo."
  exit 1
fi
