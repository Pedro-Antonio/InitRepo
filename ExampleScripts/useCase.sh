#!/bin/bash
echo -n "Choose command [1-4] : "
read reply
echo
case $reply in
"1")
date
;;
"2"|"3")
pwd
;;
"4")
ls
;;
*)
echo "Illegal choice!"
;;
esac
