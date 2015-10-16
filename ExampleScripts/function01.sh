#!/bin/bash
#Date: 16/Oct/15.

funcion1(){
echo "Parametros pasados a la función: $*"
echo "Parametro 01: $1"
echo "Parametro 02: $2"
}

#Programa principal.
funcion1 "Hola" "cómo estas ahora?"
