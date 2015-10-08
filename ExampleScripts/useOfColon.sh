#!/bin/bash
#Date: 07/Oct/15.

#test -f file does file exist and is not a directory?
#test -d file does file exist and is a directory?
#test -x file does file exist and is a executable?
#test -s file does file exist and is longer than 0 bytes?

count=0
for i in *; do
	id test -x $i; then
		count=`expr $count + 1`
	fi
done
echo "Total of $count files executable"	

