.section .data

output : .ascii "Fabricante del ejemplo: M.C. Mauricio E."
letrero1: .asciz "Cadena a leer: "
formato9: .asciz "Linea leida: \"%s\" \n"

#.section .longitud int0

.section .bss
.lcomm buffer, 10000
.section .text
.globl main

main: nop
      pushl $letrero1
      call printf
      addl $4, %esp
      call exit

      #call printf Lee la linea
      #movl $buffer %eax

leelinea: movl %eax, %ebx
          pushl %ebx
          dec %ebx
alfa_lee: call getchar
          cmpb $10, %al
          je beta_lee
          inc %ebx
          movb %al, (%ebx)
          jmp alfa_lee
beta_lee: inc %ebx
          movb $0, (%ebx)
          popl %edx
          subl %edx, %ebx
          movl %ebx, %eax
          ret
