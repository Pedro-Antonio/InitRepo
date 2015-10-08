#!/bin/bash
#Date: 07/Oct/15.
x=1
until [ $x -gt 3 ]; do
	echo x = $x
	x=`expr $x + 1`
done
