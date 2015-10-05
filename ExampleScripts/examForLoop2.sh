#!/bin/bash
#Date: 05/Oct/15.
#File-poke - tell us stuff about files.
#Find filenames in files in current directory.
files=`ls`
for i in $files
do
	echo -n "$i"
	grep $i $i
done
