/*Código de muestra en la que decides si utilizar un sprite o no
en este código se utiliza una elipse o una forma unlike the others
posibles formas con el Graphics*/

#pragma once
#include "Entidad.h"
using namespace System;

class Bala_Saludable :public Entidad {
public:
	/*Constructor con parametros*/
	Bala_Saludable(int x, int y, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		ancho = alto = 18; //elipse de la bala
	}

	/*el destructor siempre empieza con ~ seguido por el mismo nombre de la clase
	el destructor se utiliza para liberar recursos asignados dinámicamente 
	(básicamente limpieza). es una buena práctica
	*/ 
	~Bala_Saludable() {}
	//Métodos:
	void Mostrar(Graphics^g) { //Graphics como parametro
		Brush^ br = gcnew SolidBrush(Color::DarkGreen);
		//gcnew porque es una clase administrada, todo lo que está en verde es una clase administrada, Brush es una clase administrada
		g->FillEllipse(br, x, y, ancho, alto);
	}
	void Mover() {
		//dx amd dy provienen de la bala saludable
		x += dx;
		y += dy;
	}

};