#!/bin/bash

sum=0; countfail=0; count=0;
while read studentnum grade name; do
sum=`expr $sum + $grade`
count=`expr $count + 1`
if [ $grade -lt 50 ]; then
countfail=`expr $countfail + 1`
fi
done
echo "The average is `expr $sum / $count`."
echo $countfail "students failed."
