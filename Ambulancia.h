#pragma once
#include "Entidad.h"
using namespace System;

class Ambulancia :public Entidad {
	Direccion direccion;

public:
	Ambulancia() {
		Random j;
		x = j.Next(20, 90);
		System::Threading::Thread::Sleep(30);
		y = j.Next(350, 450);
		System::Threading::Thread::Sleep(30);
		dx = dy = 40;
		fila = columna = 0;
		c_filas = 4; //sprites custom
		c_columnas = 5; //sprites custom
	}
	void setXY() { //mitad de la pantalla
		x = 150;
		y = 150;
	}
	void MostrarAmbulancia(Graphics^g, Bitmap^img) { //graphics and bitmap important to show the sprite
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		img->MakeTransparent(img->GetPixel(0, 0));
		columna++;
		if (columna == c_columnas) {
			columna = 0;
		}
	}

	void Mover_Ambulancia(Direccion direccion, int ancho_form, int alto_form) {
		switch (direccion) {
		case Direccion::Arriba:
			if (y - dy > 0)
				y -= dy;
			this->direccion = Direccion::Arriba;
			fila = 3; //si cambias de sprite en la �nica variable que tienes que preocuparte es el de la fila
			break;

		case Direccion::Abajo:
			if (y + alto + dy < alto_form)
				y += dy;
			this->direccion = Direccion::Abajo;
			fila = 0;
			break;

		case Direccion::Derecha:
			if (x + ancho + dx < ancho_form)
				x += dx;
			this->direccion = Direccion::Derecha;
			fila = 2;
			break;

		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 1;
			break;

		}
	 }
};