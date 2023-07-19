//en este tema ya vamos a tocar el tema de DOBLE PUNTERO
#pragma once
#include "Saludable.h"
#include <iostream>

class Arreglo_Saludables {
private:
	Saludable** salu; //clase saludable
	int cant_saludables;
public:
	Arreglo_Saludables() {
		cant_saludables = 0;
		salu = new Saludable * [cant_saludables];    // inicializar (doble puntero?)
	}

	int getCantidad_Saludable() { return cant_saludables; }

	Saludable* getSaludable(int pos) { //obtén la posición dentro del arreglo
		return salu[pos]; // en clase es po.    decimos al saludable en qué posición se encuentra el personaje en específico
	}

	void Mostrar_Saludable(Graphics^ g, Bitmap^ img) { //mostrar el personaje saludable, pasar el paremetro Graphics para que se siga pintando
		for (int i = 0; i < cant_saludables; ++i) {
			salu[i]->Mostrar(g, img); //proviene de "Saludable.h"
			//TODO_ insertar arreglo de mostrar balas
		}
	}
	void Agregar_Saludable(int n) {//n es cuantos personajes saludables quieres
		Random j;
		for (int m = 0; m < n; ++m) { //n va obtener valor en la clase Juego
			Saludable** aux = new Saludable * [cant_saludables + 1];

			for (int i = 0; i < cant_saludables; ++i) //cuantos saludables hay en cada iteración
				aux[i] = salu[i];
			aux[cant_saludables] = new Saludable(j.Next(800, 1000), j.Next(600, 7000));
			/*el auxiliar creado en la posición cantidad saludables que se va actualizando a la cantidad puesta se ele agrega una nueva clase saludable*/
			System::Threading::Thread::Sleep(30);//dar algo de tiempo para que cambien los valores de x and y
			salu = aux; //todo este puntero doble se le asigna a auxiliar
			cant_saludables++; // 
		}
	}
	void Eliminar_Saludable(int pos) { //cuando la bala de nuestro jugador vaya a chocar con el cuerpo del saludable
		Saludable** aux = new Saludable * [cant_saludables];
		delete salu[pos]; {} // el delete es para eliminar a cualquier personaje en una posición específica
		for (int i = 0; i < pos; ++i) { //
			aux[i] = salu[i];
		}
		for (int i = pos; i < cant_saludables - 1; ++i) { //-1 para recorrer
			aux[i] = salu[i + 1];//aux saltear la posicion del personaje eliminado 

		}
		cant_saludables--;
		salu = aux;
	}

};