#ifndef _MY_LIB_H
#define _MY_LIB_H

/**
* Despliega en pantalla el menu de opciones
* @param void
* @return void
*/
void mostrarMenu ();

/**
* Limpia el buffer de teclado
* @param void
* @return void
*/
void limpiarBuffer ();

/**
* Lectura de un entero desde teclado
* @param int
* @param int
* @return int
*/
int readInt(int base, int max);

/**
* Manejo de señales
* @param int
* @return void
*/
void myCatch (int numS);

/**
* Dvuelve el valor que sera tomado como no numerico para los enteros
* @param void
* @return int
*/
int myNaN ();


/**
* realiza la operacion de suma
* @param void
* @return void
* [1]
*/
void suma ();

/**
* realiza la operacion de resta
* @param void
* @return void
* [2]
*/
void resta ();

/**
* realiza la operacion de multiplicacion
* @param void
* @return void
* [3]
*/
void multiplicacion ();

/**
* realiza la operacion de division
* @param void
* @return void
* [4]
*/
void division();

/**
* realiza la operacion de seno
* @param void
* @return void
* [5]
*/
void seno ();

/**
* realiza la operacion de coseno
* @param void
* @return void
* [6]
*/
void coseno();

/**
* realiza la operacion de tangente
* @param void
* @return void
* [7]
*/
void tangente();

/**
* realiza la operacion de arcoseno
* @param void
* @return void
* [8]
*/
void arcoseno();

/**
* realiza la operacion de arcocoseno
* @param void
* @return void
* [9]
*/
void arcoCoseno();

/**
* realiza la operacion de arcotangente
* @param void
* @return void
* [10]
*/
void arcoTan ();

/**
* realiza la operacion de seno hiperbolico
* @param void
* @return void
* [11]
*/
void senoHiper ();

/**
* realiza la operacion de coseno hiperbolico
* @param void
* @return void
* [12]
*/
void coship();

/**
* realiza la operacion de tangente hiperbolica
* @param void
* @return void
* [13]
*/
void tangenteHiper ();

/**
* realiza la operacion de arcotangente Dos
* @param void
* @return void
* [14]
*/
void atanDos ();

/**
* realiza la operacion exponencial
* @param void
* @return void
* [15]
*/
void expon ();

/**
* realiza la operacion de logaritmo natural
* @param void
* @return void
* [16]
*/
void logaritmoNatural ();

/**
* realiza la operacion de logaritmo base 10
* @param void
* @return void
* [17]
*/
void decLog ();

/**
* realiza la operacion de raiz cuadrada
* @param void
* @return void
* [18]
*/
void raizCuadrada ();

/**
* realiza la operacion de potenciacion
* @param void
* @return void
* [19]
*/
void potencia();

/**
* realiza la operacion de valor absoluto
* @param void
* @return void
* [20]
*/
void valorAbsoluto ();

/**
* realiza la operacion de...
* @param void
* @return void
* [21]
*/
void fmodd();

/**
* realiza la operacion de redondeo a techo
* @param void
* @return void
* [22]
*/
void funcionTecho();

/**
* realiza la operacion de redondeo a piso
* @param void
* @return void
* [23]
*/
void funcionPiso ();

/**
* realiza la operacion de...
* @param void
* @return void
* [24]
*/
void frexpre();

/**
* realiza la operacion de...
* @param void
* @return void
* [25]
*/
void ldexpe();

/**
* realiza la operacion de...
* @param void
* @return void
* [26]
*/
void moduloF();

#endif
