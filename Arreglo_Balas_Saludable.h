#pragma once
#include "Bala_Saludable.h"

class Arreglo_Bala_Saludable { //constructor Arreglo_Bala_Saludable
private:
	Bala_Saludable** bala_salu; //puntero
	int cant;
public:
	Arreglo_Bala_Saludable() {
		cant = 0;
		bala_salu = new Bala_Saludable * [cant];// dinámico: aumentando la cantidad que sea necesario de balas, si fuese continúo tendríamos que agregar un número
	}

	void agregar_Bala_Saludable(int index, int dy, int dx, int x, int y, int ancho, int alto) {
		Bala_Saludable** aux = new Bala_Saludable * [cant + 1];
		for (int i = 0; i < cant; ++i)
			aux[i] = bala_salu[i];

		int dx1 = 0, dy1 = 0;

		if (index == 1) {	
			if (dy > 0) {
				dy1 += 20;
			}
			else {
				dy -= 20;
			}
		}
		else {
			if (dx > 0) {
				dx1 += 20;
			}
			else {
				dx1 -= 20;
			}
		}

		aux[cant] = new Bala_Saludable(x + ancho / 2, y + alto / 2, dx1, dy1);

		bala_salu = aux;
		cant++;

	}


	//función eliminar_bala_salu recibe el parámetro de `pos`
	void eliminar_bala_salu(int pos) {
		Bala_Saludable** aux = new Bala_Saludable * [cant - 1];//donde cant es el tamaño original del arreglo
		delete bala_salu[pos];

		for (int i = 0; i < pos; ++i)
			aux[i] = bala_salu[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = bala_salu[i + 1];

		cant--;
		bala_salu = aux;
	}


};
