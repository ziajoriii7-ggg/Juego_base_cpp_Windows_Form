
/* Entidad.h:
Esta clase Entidad es bastante importante la vamos a utilizar
en todos nuestros personajes para ahorrar / modularizar las líneas
de código, utilizando el paradigma de herencia*/

/*Instead of '#pragma once' you could just use:
#ifndef _ENTIDAD_H_
#define _ENTIDAD_H_


TODO: https://chat.openai.com/c/0a0ca052-b716-444f-b76b-6598406e483c
- [  ] ask ChatGPT why this commented method is better professionally
than #pragma once

- [  ] ask optimability of code difference
*/

#pragma once
enum Direccion { Arriba, Abajo, Derecha, Izquierda };
using namespace System::Drawing;
using namespace System::Windows::Forms;
/*para utilizar el drawing y el windows form tienes que abrir
primero un Windows Form*/

class Entidad {

protected:
	int x, y; // controlar las coordenadas de los personajes dentro del Windows Form, allí se va a ver el movimiento
	int dx, dy; // para controlar la velocidad de los personajes
	int fila, columna; // se refiere al orden de selección de las filas y columnas de los sprites (N°0,1,2,3)
	int ancho, alto; // capturar ancho y alto del sprite a través de img
	int c_filas, c_columnas; // cantidad de filas y cantidad de columnas del sprite

public:
	/*los GETs y los SETs son utilizados para obtener los valores
	actuales en los que se están ejecutando x and y, al igual que
	todos los valores de protected*/

	/*los void sirven para actualiza esos valores en caso que
	queremos cambiar de valor*/
	int getX() { return x; }
	int getDX() { return dx; }
	int getY() { return y; }
	int getDY() { return dy; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getCantidad_Filas() { return c_filas; }
	int getCantidad_Columnas() { return c_columnas; }
};