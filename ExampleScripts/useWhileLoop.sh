#!/bin/bash
#Date: 07/Oct/15.

i=1
sum=0
while [ $i -le 100 ]; do
	sum=`expr $sum + $i`
	i=`expr $i + 1`
done
echo "The sum is $sum"
