.section .data                                  # Directiva de ensamble para definir datos inicializados
formato: .asciz "Longitud cadena = %d\n"
formatoint: .asciz "%s\n"
longitudlinea: .int 0

.section .bss                                   # Directiva de ensamble para definir datos no inicializados
.lcomm buffer,1024


.section .text                                  # Directiva de ensambe para definir inicio del codigo
.globl main

main:        nop
             nop
             movl $buffer,%eax
             call lee_linea
             movl %eax,longitudlinea

             pushl $buffer                      # Bloque de impresión
             pushl $formatoint
             call printf
             addl $8,%esp                       # Proceso de limpieza

             pushl longitudlinea
             pushl $formato
             call printf
             addl $8,%esp
             call exit

lee_linea:   movl %eax, %ebx
             pushl %ebx
             dec %ebx
             
alfa_lee:    call getchar
             cmpb $10,%al
             je beta_lee
             inc %ebx
             movb %al,(%ebx)
             jmp alfa_lee

beta_lee:    inc %ebx
             movb $0, (%ebx)
             popl %edx
             subl %edx,%ebx
             movl %ebx,%eax
             ret
