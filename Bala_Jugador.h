#pragma once
#include "Entidad.h"
#include <iostream>
using namespace System; // Recuerda que <iostream> and using namespace System; can go to Entidad.h

class Bala_Jugador : public Entidad {
	int random_mensajes;
public:
	//constructor
	Bala_Jugador(int x, int y, int dx, int dy) { // x and y son del jugador, el público tiene que ser al nombre de la clase porque es un constructor
		Random j;
		this->x = x;
		this->y = y;
		this->dx = dy;
		random_mensajes = j.Next(1, 5);
		System::Threading::Thread::Sleep(8);
		columna = fila = 0;
	}
	//destructor
	~Bala_Jugador(){}

	void Mostrar(Graphics^g, Bitmap^img) {
		alto = img->Height / 1;//capturamos su altura con img
		ancho = img->Width / 1;
		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, fila);
		switch (random_mensajes) {
		case 1: g->DrawString("Yippe", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 2: g->DrawString("imma be a computer wizard mom", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 3: g->DrawString("What's up! u guys", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		case 4: g->DrawString("XD", gcnew Font("Calibri", 14), Brushes::Black, x, y + 10); break;
		}
		g->DrawImage(img, x, y, molde, GraphicsUnit::Pixel);
		columna++;
		if (columna == 1) {
			columna = 0;
		}
	}

	void mover() {
		x += dx;
		y += dy;
	}

};