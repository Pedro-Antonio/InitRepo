.section .data
.section .text
.globl main

main: nop
entra:  call getchar #El caracter leído está en %al.
        cmpl $-1, %eax #Checo so es el fin de archivo "EOF, -1".
        je fin #Termina
        pushl %eax
        call putchar
        jmo entra

fin: call exit
