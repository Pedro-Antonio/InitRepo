#!/bin/bash
#http://www.csd.uwo.ca/~moreno/cs2101_Fall_2012/notes/shell-programming.pdf
#Oldest --examine the oldest parts of a directory.

HOWMANY=$1
shift
ls -lt $* | tail +2 | tail $HOWMANY

