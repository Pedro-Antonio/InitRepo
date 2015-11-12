.section .data

output : .ascii "Fabricante del ejemplo: M.C. Mauricio E."
letrero1: .asciz "Cadena a leer: "
formato9: .asciz "Linea leida: \"%s\" \n"
formato8: .asciz "%s"

.section .longitudlinea .int 0

.section .bss
.lcomm buffer, 1024
.section .text
.globl main

main: nop
      nop
      #pushl $letrero1
      #call printf
      #addl $4, %esp
      #call exit

      movl $buffer, %eax
      call leelinea
      movl %eax, longitudlinea

      pushl $buffer
      pushl $formato
      call printf
      addl $8, %esp #Sumo ocho bits para borrar lo anterior. Limpio el Stack de memoria.
      #call exit

      pushl $longitudlinea
      pushl $formato
      call printf
      addl $8, %esp
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
