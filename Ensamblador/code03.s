.section .data                                  # Directiva de ensamble para definir datos inicializados

mensaje : .asciz "Hola Mundo \n"
formato : .asciz "%s"

.section .text                                  # Directiva de ensambe para definir inicio del codigo (texto) del programa.
.globl main                                     # Puesto que empleo gcc para ensamblar y ligar el programa, necesito la etiqueta
                                                # que es el punto donde arranca la ejecución del programa.

main:        movl $mensaje, %eax
             movl $formato, %ebx

             pushl $eax                         # Bloque de impresión
             pushl $ebx

             call printf
             addl $8, %esp                      # Proceso de limpieza

             pushl $0
             call exit
