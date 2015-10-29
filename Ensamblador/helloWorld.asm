.section .data
mensaje : .asciz "Hola Mundo.\n"
formaro : .asciz "%s"

.section .txt #Directorio de ensamble para difundir inicio del código (texto) del programa.
.globl main #Si empleo GCC necesito la eitiqueta "main".

main: movl $mensaje, %eax
      mov $formato, %ebx
      pushl %eax
      pushl %ebx
      call printf
      addl $8, %esp

      pushl $0
      call exit
