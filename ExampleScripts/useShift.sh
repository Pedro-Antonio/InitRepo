#!/bin/bash

echo "Comando completo: $*"
echo "Comando o script que ejecutó: $0"
echo "Número de argumentos: $#"

while [ $1 ]
do
echo "Argumento: $1"
shift
done

