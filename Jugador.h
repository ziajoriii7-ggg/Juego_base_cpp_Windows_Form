#pragma once
#include "Entidad.h"
#include <ctime> //control random time
#include <fstream> //se utiliza para poder guardar archivos
using namespace System;

class Jugador :public Entidad {
private: //vidas y control de teclas direccionales
	Direccion direccion;
	int vidas;
public:
	Jugador(int vidas) {
		x = 100;
		y = 290;
		this->vidas = vidas;
		c_columnas = 5;
		c_filas = 4;
		direccion = Direccion::Izquierda;
	}
	~Jugador() {
		//aqui van las balas, pero como aún no hayy arreglo no hay código
	}
	int getVidas() { return vidas; }
	void setVidas(int v) { vidas = v; }
	void restarVidas() { vidas--; }
	void Mostrar(Graphics^ g, Bitmap^ img) { //el Graphics y el bitmap es para dibujar nuestro sprite
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}
	}
	void Mover(Direccion direccion, int ancho_form, int alto_form) {
		switch (direccion) {
		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;
			this->direccion = Direccion::Arriba;
			fila = 2; //sprites custom
			break;
		case Direccion::Abajo:
			if (y + alto + dy < alto_form)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 3; //sprites custom
			break;
		case Direccion::Derecha:
			if (x + ancho + dx < ancho_form)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 1; //sprites custom
			break;
		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 0; //sprites custom
			break;
		}
	}
};