#pragma once
#include "Entidad.h"
#include <ctime>
using namespace System;

class Asintomatico :public Entidad {
private:
	Direccion direccion;
public:
	Asintomatico() {
		Random j;
		x = j.Next(200, 1000);
		System::Threading::Thread::Sleep(40);
		y = j.Next(200, 100);
		System::Threading::Thread::Sleep(40);
		dx = 5;
		dy = 5;
		fila = columna = 0;

	}
	~Asintomatico(){
		//delete bullets
	}
	void Mostrar(Graphics^ g, Bitmap^ img) {
		//la calse administrada graphics viene en el Windows Forms
		alto = img->Height / 4; //depende de asintomático
		ancho = img->Width / 3; //depende de asintomático
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == 3) { //valor numérico de columnas depende del sprite (Asíntomatico)
			columna = 0;
		}
	}
	void setMostrar(Graphics^g, Bitmap^ img) {
		Mostrar(g, img);
	}

	void Mover(Direccion direccion, int altoform, int anchoform) {
		switch (direccion) {
		case Direccion::Arriba:
			if (y - dy > 0) // condicionales para que no se salga de la pantalla del Windows Form
				y -= dy;
			this->direccion = Direccion::Arriba;
		case Direccion::Abajo:
			if (y + dy > 0)
				y += dy;
			this->direccion = Direccion::Abajo;
		case Direccion::Derecha:
			if (x + ancho + dx < anchoform)
				x += dx;
			this->direccion = Direccion::Derecha;
		case Direccion::Izquierda:
			if (x - dx > 0)
				x -= dx;
			this->direccion = Direccion::Izquierda;
			fila = 1;
			break;
		}


	}



};