/*
Este archivo contiene la clase de arreglo de balas asintomático.
*/
#pragma once
#include "Bala_Asintomático.h"
class Arreglo_Balas_Asintomatico {
private:
	Bala_Asintomatico** bala_asi; //doble puntero
	int cant;

public:
	Arreglo_Balas_Asintomatico() { // constructor de esta clase
		cant = 0;
		bala_asi = new Bala_Asintomatico * [cant];
	}

	void Agregar_Bala(Direccion direccion, int x, int y, int ancho, int alto) { // para que coincida con las coordenadas del enum para las direcciones
		Bala_Asintomatico** aux = new Bala_Asintomatico * [cant + 1]; // "El doble puntero auxiliar por cada iteraccion le vamos a asignar los elementos que hemos creado en el doble constructor"
		for (int i = 0; i < cant; ++i)
			aux[i] = bala_asi[i];

		int dx = 0, dy = 0; //inicializa los valores, recuerda que en el caso de y el valor si iba hacia abajo aumnetaba y en el x aumenta si va hacia la derecha

		switch (direccion) // controlar las direcciones del arreglo de Bala asintomático
		{
		case Direccion::Arriba: dy -= 19; break;
		case Direccion::Abajo: dy += 19; break;
		case Direccion::Derecha: dx += 19; break;
		case Direccion::Izquierda: dx -= 19; break;

			aux[cant] = new Bala_Asintomatico(x + ancho / 2, y + alto / 2, x, y); // las balas siempre tienen esta formula para que salga del medio del cuerpo del personaje asintomático

			// x and y son las coordenadas del personaje asintomático
			// el dx and dx tienen que ser más rápidos que x and y (personajes) ya que son balas

			bala_asi = aux;
			cant++;
		}

	}


	void eliminar_bala(int pos){
		Bala_Asintomatico** aux = new Bala_Asintomatico * [cant - 1];
		delete bala_asi[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = bala_asi[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala_asi[i + 1]; //evitar quw haya errores, se actualiza correctamente cada vez que se elimine un elemento dentro del arreglo

		cant--;
		bala_asi = aux; // arreglo `bala_asi` igual al auxiliar

	}

	void mostrar_bala_asinto(Graphics^ g, Bitmap^ img) {
		for (int i = 0; i < cant; ++i) {
			/*
			mostrar todas las balas asintomáticas con un for, recorriendo todo nuestro arreglo y mostrando así todas las clases que se tiene dentro del arreglo
			*/
			bala_asi[i]->mostrar(g, img);
			/*
			en `bala_asi` en la posición `i` se va a seleccionar el método mostrar
			*/
		}
	}

	void mover_bala_asinto() {
		for (int i = 0; i < cant; ++i) {
			bala_asi[i]->mover();
		}
	}

	/*
	recuerda que void no retorna nada, solo indica lo que tiene que hacer una función
	*/

	Bala_Asintomatico* getBalita(int pos) {// este método va a retornar una clase
		return bala_asi[pos]; 
	}

	int getCantBalasAsinto() {
		return cant;
	}


};