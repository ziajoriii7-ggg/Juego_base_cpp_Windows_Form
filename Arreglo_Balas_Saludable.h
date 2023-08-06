#pragma once
#include "Bala_Saludable.h"

class Arreglo_Bala_Saludable { //constructor Arreglo_Bala_Saludable
private:
	Bala_Saludable** bala_salu; //puntero
	int cant;
public:
	Arreglo_Bala_Saludable() {
		cant = 0;
		bala_salu = new Bala_Saludable * [cant];
		// dinámico: aumentando la cantidad que sea necesario de balas, si fuese continúo tendríamos que agregar un número
	}

	void agregar_Bala_Saludable(int index, int dy, int dx, int x, int y, int ancho, int alto) { // métod agregar_Bala_Saludable
		Bala_Saludable** aux = new Bala_Saludable * [cant + 1];

		for (int i = 0; i < cant; ++i)

			aux[i] = bala_salu[i]; // al auxiliar le pasamos por posición todos los valores que tenga bala_salu[i]

		int dx1 = 0, dy1 = 0; // velocidad de x and y

		if (index == 1) { // si el random es igual a 1 va o bien hacia derecha o izquierda
			if (dy > 0) {
				dy1 += 20;
			}
			else {
				dy -= 20;
			}
		}
		else { // si el random es mayor a 0 va o bien hacia arriba o hacia abajo
			if (dx > 0) {
				dx1 += 20;
			}
			else {
				dx1 -= 20;
			}
		}

		aux[cant] = new Bala_Saludable(x + ancho / 2, y + alto / 2, dx1, dy1);
		//en el arreglo de doble puntero `auxiliar` en la posición cantidad le vamos a crear una nueva clase `Bala_Saludable` y le vamos a pasar por parametro los valores dentro del parentesis.
		//el ancho y el alto del sprite del personaje saludable, entre 2 para que la bala salga de la mitad del personaje saludable

		bala_salu = aux; // se le asigna todos los valores de la cantidad auxiliar
		cant++; // y va a ir aumentando

	}


	//función eliminar_bala_salu recibe el parámetro de `pos`
	void eliminar_bala_salu(int pos) {
		Bala_Saludable** aux = new Bala_Saludable * [cant - 1];//donde cant es el tamaño original del arreglo
		delete bala_salu[pos];

		for (int i = 0; i < pos; ++i)
			aux[i] = bala_salu[i];

//alt	for (int i = pos + 1; i < cant; ++i)  // Bucle ajustado para omitir el elemento en pos
//alt		aux[i - 1] = bala_salu[i];// Copiar a aux[i-1] para mantener el índice correcto en aux

		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala_salu[i + 1];

		cant--;
		bala_salu = aux;
	}
/*
ChatGPT: 
kaeka: https://chat.openai.com/c/75052aac-26ce-4202-b14d-00ccd8f5928b
share: https://chat.openai.com/share/7a4963fb-be6e-458a-8546-4795c8daeefd
*/
void mostrar_bala_salu(Graphics^ g) { 
/*
Se utiliza `^` para denotar puntero en .NET framework como referencias a objetos, son gestionados por el recolector de basura de .NET framework. En este caso `Graphics^` es un puntero o referencia a un obketo de la clase `Graphics`.

Entonces `Graphics^ g` se está proporcionando un puntero al objeto `Graphics` que se utiliza dentro de la función `mostrar_bala_salu`

C++/CLI es una extensión de C++ desarrollada por Microsoft para trabajar con el Common Language Infraestructure (CLI) de .NET.

Documentación de .NET con C++/CLI: https://learn.microsoft.com/es-es/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-170
*/
		for (int i = 0; i < cant; ++i) {
			bala_salu[i]->Mostrar(g);
		}
	}

	void mover_bala_salu() {
		for (int i = 0; i < cant; ++i) {
			bala_salu[i]->Mover();
		}
	}

	Bala_Saludable* getBalitasalu(int i) {
		return bala_salu[i];
	}

	int getCantBalasSalu() {
		return cant;
	}
};
