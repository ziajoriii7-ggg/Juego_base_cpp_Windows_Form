#pragma once
#include "Bala_Jugador.h"

class Arreglo_Bala_Jugador {
private:
	Bala_Jugador** balaj;
	int cant;
public:
	Arreglo_Bala_Jugador() {
		cant = 0;
		balaj = new Bala_Jugador * [cant];

	}

	Bala_Jugador* getBala(int pos) {
		return balaj[pos];// la posición es pasada a través de parametro
	}
	int getCantidad_Balas() {
		return cant;
	}
	//bala dirigida al hacer clock a cualquier parte de la pantalla en Windows Form: propiedadees del Windows Form

	void Agregar_Bala(int x, int y, double mousex, double mousey, int alto, int ancho) { //alto y ancho sirve para que la bala salga del medio del personaje
		Bala_Jugador** aux = new Bala_Jugador * [cant + 1];
		for (int i = 0; i < cant; ++i)
			aux[i] = balaj[i];
		x = x + (ancho / 2);//coordenada x intermedio del personaje salir bala
		y = y + (ancho / 2);

		double cateto1 = mousex - x; //este es el trajecto que va a recorrer la bala del jugador
		double cateto2 = mousey - y;
		//el trayecto de la bala es la hipotenusa
		double hipo = Math::Sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
		double V = 40;//movimiento de la bala o del jugador (no claro aún, preguntar a chatGPT)
		double constante = V / hipo;
		double dx = constante * cateto1;
		double dy = constante * cateto2;

		aux[cant] = new Bala_Jugador(x, y, dx, dy); //recibido de "Bala_Jugador.h"
		balaj = aux;
		cant++;
	}
	void Eliminar_Bala(int pos) {
		Bala_Jugador** aux = new Bala_Jugador*(cant + 1);
		delete balaj[pos];
		for (int i = 0; i < pos; ++i) 
			aux[i] = balaj[i];
		for (int i = pos; i < cant - 1; ++i)
			aux[i] = balaj[i + 1];//se salta posiciones en el arreglo sin bugs y sin errores
		
		balaj = aux;
		cant--;
		
	}

	void Mostrar_Bala_Jugador(Graphics^g, Bitmap^img) { //graphics es para dibujar y el bitmap es para que se muestre el sprite
		for (int i = 0; 1 < cant; ++i) {
			balaj[i]->Mostrar(g, img);
		}
	}

	void Mover_Bala_Jugador() {
		for (int i = 0; i < cant;++i) {
			balaj[i]->mover();
		}
	}
};