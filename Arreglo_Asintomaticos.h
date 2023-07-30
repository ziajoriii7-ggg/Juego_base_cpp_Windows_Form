#pragma once
#include "Asintomatico.h"
#include <fstream>

class Arreglo_Asintomaticos {
private:
	Asintomatico** asinto; // en el arreglo del Asintomatico se utiliza doble puntero
	int cant_asintomatico; //podemos saber cuantos asintomaticos se tiene en un determinado momento
public:
	Arreglo_Asintomaticos() { // este es el constructor de Arreglo_Asintomatico
		cant_asintomatico = 0; //inicializaci�n de la cantidad de asintomatico
		asinto = new Asintomatico * [cant_asintomatico];// se controla din�micamente la cantidad de personajes con respecto al tiempo, no es un valor fijo, es un valor variable
	}
	int getcantidad_asintomatico() { //obtener cu�ntos personajes asintom�ticos tenemos hasta un determinado tiempo
		return cant_asintomatico;
	}
	Asintomatico* getAsintomatico(int pos) {//Con este m�todo se puede saber cu�l de todos los personajes asintom�ticos se quiere eliminar
		return asinto[pos];//se captura el valor de posici�n espec�fica del asintom�tico
	}
	void agregar_asintomatico(int n) {//si queremos agregar un nuevo personaje asintomatico primero se tiene que pasar la cantidad de asintomatico que se quiere en el Windows Form. Este valor es puesto en los parametros(int n
		for (int m = 0; m < n; ++m) {//limita los valores que se quiere en cantidad de asintom�ticos
			Asintomatico** tmp = new Asintomatico * [cant_asintomatico + 1];
			for (int i = 0; i < cant_asintomatico; i++)
				tmp[i] = asinto[i];//se asigna al temporal cada valor que se adquiera
			tmp[cant_asintomatico] = new Asintomatico();
			asinto = tmp;//asinto obtiene el valor del temporal, actualizandose
			cant_asintomatico++;//aumenta de 1 en 1 hasta la cantidad que se quiera en Windows Form


		}
	}
	void eliminar_asintomatico(int pos) {
		Asintomatico** aux = new Asintomatico * [cant_asintomatico - 1];
		delete asinto[pos];
		for (int i = 0; i < pos; ++i)
			aux[i] = asinto[i];//se salta al siguiente asintomatico
		for (int i = pos; i < cant_asintomatico - 1; ++i)
			aux[i] = asinto[i + 1];//se evita errores

		cant_asintomatico--;
		asinto = aux;
	}

	void mostrar_asintomatico(Graphics^ g, Bitmap^ img, Bitmap^ b) {
		for (int i = 0; i < cant_asintomatico; ++i) {
			asinto[i]->Mostrar(g, img);//Funci�n mostrar del "Asintomatico.h"
			//faltaba el mostrar
			//asinto[i]->mostrar_balaene(g, b); //falta hacer el arreglo de las balas de los enemigos
		
		}
	}

};