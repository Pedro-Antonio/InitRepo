#!/bin/bash
#Date: 05/Oct/2015
#timestable - print out a multiplication table.
for i in 1 2 3
	do
		for j in 1 2 3
			do
				value=`expr $i \* $j`
				echo -n "$value"
			done
		echo
	done
