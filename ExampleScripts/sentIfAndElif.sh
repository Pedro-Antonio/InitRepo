#!/bin/bash
#Date: 07/Oct/15.

echo -n "Dame el nombre del archivo para buscar la palabra UNIX: "
read myfile

if grep "UNIX" $myfile >/dev/null
then
	echo "UNIX occurs in file"
elif grep "DOS" $myfile >/dev/null
then
	echo "UNIX does not occur, but DOS does"
else
	echo "Nodoby is there"
fi 
