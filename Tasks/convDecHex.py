#! /usr/bin/python3 

result = hex(int(ord(input("Caracter 01: "))))
result = hex(int(ord(input("Caracter 02: ")))) + ":" + result
print(result)
