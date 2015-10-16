#!/bin/bash

#Redirection in Bourne Shell.
echo "Name file 01: "
read x
echo "Name file 02:"
read y
cat $x 1> ls.txt
cat $x $y 1>stdout.txt 2>stderr.txt
cat $x $y >xy.txt 2>&1
cat $x $y 2>&1 | grep bin
