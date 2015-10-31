/*
* Includes del sistema
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <libintl.h>
#include <locale.h>
#include <signal.h>
#include <unistd.h>

#include "my_lib.h"

///definiciones
#define _(cadena) gettext(cadena)

/*
*Declaracion de variables globales
*/

double x,y;
char str[20];

/**
* Despliega en pantalla el menu de opciones
* @param void
* @return void
*/
void mostrarMenu (){
    printf(_("The following menu displays the available operations\n"));
    printf(_("To select a category\n"));
    printf(_("Enter the corresponding number!\n\n"));
    printf(_("[1] Addition\n"));
    printf(_("[2] Subtraction\n"));
    printf(_("[3] Multiplication\n"));
    printf(_("[4] Division\n"));
    printf(_("[5] Sine\n"));
    printf(_("[6] Cosine\n"));
    printf(_("[7] Tangent\n"));
    printf(_("[8] Arc sine\n"));
    printf(_("[9] Arc cosine\n"));
    printf(_("[10] Arc tangent\n"));
    printf(_("[11] Hyperbolic sine\n"));
    printf(_("[12] Hyperbolic cosine\n"));
    printf(_("[13] Hyperbolic tangent\n"));
    printf(_("[14] Arc tangent y/x (atan2)\n"));
    printf(_("[15] Exponential\n"));
    printf(_("[16] Natural logarithm\n"));
    printf(_("[17] Decimal logarithm\n"));
    printf(_("[18] Square root\n"));
    printf(_("[19] Power\n"));
    printf(_("[20] Absolute value\n"));
    printf(_("[21] floating point remainder (fmod)\n"));
    printf(_("[22] Ceil function\n"));
    printf(_("[23] Floor function\n"));
    printf(_("[24] frexp\n"));
    printf(_("[25] ldexp\n"));
    printf(_("[26] modf\n"));
    printf(_("[27] Exit\n\n"));
}

/**
* Limpia el buffer de teclado
* @param void
* @return void
*/
void limpiarBuffer (){
    char ch = getchar();
    //Mientras el caracter leido sea diferente de nueva linea o Error leemos de teclado
    while((ch != 10) && (ch != -1)){
        ch = getchar();
    }
}

/**
* Lectura de un entero desde teclado
* @param int
* @param int
* @return int
*/
int readInt(int base, int max){
    //Buffer para almacenar los digitos leidos
    static int* BUFFER = NULL;


    //la variable b funciona como base de multiplicacion
    //inicia como 1 porque en las unidades: base elevado a la 0 es igual a 1
    //Al ser de tipo char pueden moverse de 1 hasta maximo 255
    unsigned char b = 1;

    //Las variables i y j son para mover indices
    //la variable f funciona como factor (numero positivo o negativo)
    //son de tipo char porque es la unidad signed mas pequeña en C
    //la variable ch almacenara los caracteres sacados del buffer de teclado
    char i = 0, j = 0, f = 1, ch;

    //Variable para almacenar el resultado inicializada
    int result = 0;

    //Leemos el primer caracter en el buffer de teclado
    ch  = getchar();
    //Reservamos memoria para el numero de digitos a leer
    if(BUFFER == NULL){
        BUFFER = malloc(max * sizeof(int));
    }

    //Si el primer caracter es el signo "-" ponemos el factor negativo y leemos el siguiente caracter en el buffer
    if(ch == 45){
        f = -1;
        ch = getchar();
    }
    //Mientras el numero de caracteres leidos sea menor que el maximo requerido
    //el caracter leido sea diferente de nueva linea o Error
    // y sea un digito, almacenamos el caracter leido
    while( (i < max) && (ch != 10) && (ch != -1) && (ch >= 48 && ch <= 57) ){
        BUFFER[i++] = ch;
        ch = getchar();
    }
    //Si no se leyeron digitos retornamos ERROR,
    // antes limpiamos el buffer de teclado
    if( i == 0 || (ch != 10 && ch != -1)){
        while(ch != 10 && ch != -1){
            /* consumo lo que haya en el buffer para vaciarlo.*/
            ch = getchar();
        }
        //Retornamos el valor maximo negativo como codigo de error
        return myNaN ();
    }

    //Si leimos digitos transformamos el string en un entero según la base.
    // De atrás para adelante, multiplicando por la base y sumando.
    for( j = (i-1); j >= 0 ; j-- ){
        result += ( BUFFER[j] - 48 ) * b;
        b*= base;
    }

    /* aplico el signo*/
    result *= f;
    return result;
}

/**
* Manejo de señales
* @param int
* @return void
*/
void myCatch (int numS){
    if (numS == SIGINT) {
        printf(_("\nSorry, you can not exit with the key combination Ctrl + C"));
        printf(_("\nTry the default setting\n\n"));
    }

    if (numS == SIGSEGV) {
        printf(_("\nError:"));
        printf(_("\nSegmentation fault\n\n"));
    }
}

/**
* Dvuelve el valor que sera tomado como no numerico para los enteros
* @param void
* @return int
*/
int myNaN (){
    return (pow(2,(sizeof(int)*8))+2);
}

/**
* realiza la operacion de suma
* @param void
* @return void
* [1]
*/
void suma (){
    printf(_("\nAddition \n"));
    printf(_("\n1st Number: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\n2nd Number: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    printf("%f\n\n",x+y);
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de resta
* @param void
* @return void
* [2]
*/
void resta (){
    printf(_("\nSubtraction \n"));
    printf(_("\n1st Number: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\n2nd Number: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    printf("%f\n\n",x-y);
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de multiplicacion
* @param void
* @return void
* [3]
*/
void multiplicacion (){
    printf(_("\nMultiplication \n"));
    printf(_("\n1st Number: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\n2nd Number: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    printf("%f\n\n", x*y);
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de division
* @param void
* @return void
* [4]
*/
void division(){
    printf(_("\n Division \n"));
    printf(_("\nDivided: "));
    printf(_("\n1st Number: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\n2nd Number: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    if ( y != 0) {
        printf("%f\n\n", x/y);
    } else {
        printf(_("\nError: division by zero is not defined\n"));
    }
    limpiarBuffer ();
}

/**
* realiza la operacion de seno
* @param void
* @return void
* [5]
*/
void seno (){
    printf(_("\nSine \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult in radians: "));
    printf("%lf\n\n",sin(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de coseno
* @param void
* @return void
* [6]
*/
void coseno(){
    printf(_("\nCoseno \n"));
    printf(_("\nNúmero: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResultado en Radianes: "));
    printf("%lf\n\n",cos(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de tangente
* @param void
* @return void
* [7]
*/
void tangente(){
    printf(_("\nTangente en Radianes \n"));
    printf(_("\nNúmero: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResultado en Radianes: "));
    printf("%lf\n\n",tan(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de arcoseno
* @param void
* @return void
* [8]
*/
void arcoseno(){
    printf(_("\nArc sine \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n",asin(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de arcocoseno
* @param void
* @return void
* [9]
*/
void arcoCoseno(){
   printf(_("\nArco Coseno \n"));
   printf(_("\nNúmero: "));
   scanf("%s",str);
   x = atof(str);
   printf(_("\nResultado en Radianes: "));
   printf("%lf\n\n",acos(x));
   //limpiamos buffer
   limpiarBuffer ();
}

/**
* realiza la operacion de arcotangente
* @param void
* @return void
* [10]
*/
void arcoTan (){
    printf(_("\n Arc tangent \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult in radians: "));
    printf("%lf\n\n",atan(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de seno hiperbolico
* @param void
* @return void
* [11]
*/
void senoHiper (){
  printf(_("\nHyperbolic sine \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", sinh(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de coseno hiperbolico
* @param void
* @return void
* [12]
*/
void coship(){
    printf(_("\nHyperbolic cosine \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n",cosh(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de tangente hiperbolica
* @param void
* @return void
* [13]
*/
void tangenteHiper (){
  printf(_("\nHyperbolic tangent \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", tanh(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de arcotangente Dos
* @param void
* @return void
* [14]
*/
void atanDos (){
  printf(_("\nArc Tangent Two (atan2) \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\n2nd Number: "));
  scanf("%s",str);
  y = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", atan2(x, y));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion exponencial
* @param void
* @return void
* [15]
*/
void expon (){
    printf(_("\nExponential \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n", exp(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de logaritmo natural
* @param void
* @return void
* [16]
*/
void logaritmoNatural (){
  printf(_("\nNatural logarithm \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", log(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de logaritmo base 10
* @param void
* @return void
* [17]
*/
void decLog (){
    printf(_("\nDecimal logarithm \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nExponential: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n", ldexp(x,y));
    //limpiamos buffer
    limpiarBuffer ();

}

/**
* realiza la operacion de raiz cuadrada
* @param void
* @return void
* [18]
*/
void raizCuadrada (){
  printf(_("\nSquare root \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", sqrt(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de potenciacion
* @param void
* @return void
* [19]
*/
void potencia(){
    printf(_("\nPower \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nPower: "));
    scanf("%s",str);
    y = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n",pow(x,y));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de valor absoluto
* @param void
* @return void
* [20]
*/
void valorAbsoluto (){
  printf(_("\nAbsolute value \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", fabs(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de...
* @param void
* @return void
* [21]
*/
void fmodd(){
    printf("\nModulo de 2 números \n");
    printf("\n1er Número: ");
    scanf("%s",str);
    x = atof(str);
    printf("\n2do Número: ");
    scanf("%s",str);
    y = atof(str);
    printf("\nEl Módulo de %lf entre %lf es:", x, y);
    printf("%lf\n\n",fmod(x,y));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de redondeo a techo
* @param void
* @return void
* [22]
*/
void funcionTecho(){
    printf("\nCeil function\n");
    printf(_("\n1st Number: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nResult: "));
    printf("%lf\n\n", ceil(x));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de redondeo a piso
* @param void
* @return void
* [23]
*/
void funcionPiso (){
  printf(_("\nFloor function \n"));
  printf(_("\n1st Number: "));
  scanf("%s",str);
  x = atof(str);
  printf(_("\nResult: "));
  printf("%lf\n\n", floor(x));
  //limpiamos buffer
  limpiarBuffer ();
}

/**
* realiza la operacion de...
* @param void
* @return void
* [24]
*/
void frexpre(){
    int b;
    printf(_("\nfrexp \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nExponent: "));
    scanf("%s",str);
    b = atoi(str);
    printf(_("\nResult: "));
    printf("%lf\n\n",frexp(x,&b));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de...
* @param void
* @return void
* [25]
*/
void ldexpe(){
    int b;
    printf(_("\nldexp \n"));
    printf(_("\nNumber: "));
    scanf("%s",str);
    x = atof(str);
    printf(_("\nExponent: "));
    scanf("%s",str);
    b = atoi(str);
    printf(_("\nResult: "));
    printf("%lf\n\n",ldexp(x,b));
    //limpiamos buffer
    limpiarBuffer ();
}

/**
* realiza la operacion de...
* @param void
* @return void
* [26]
*/
void moduloF(){
    double a;
    printf("\nmodf\n");
    printf(_("\nNumber: "));
    scanf("%s",str);
    a = atof(str);
    y = modf( a, &x);
    printf(_("\nResult "));
    printf(_("\nInteger part: "));
    printf("%lf",x);
    printf(_("\nDecimal part: "));
    printf("%lf\n\n",y);
    limpiarBuffer ();
}
