#pragma once
#include "Entidad.h"
using namespace System; // para poder evitar copiar esta línea (la 3) a cada rato en todos los archivos puedes escribir esto en Entidad.h

class Saludable :public Entidad {
private:
	Direccion direccion;
public:
	Saludable(int x, int y) {
		this->x = x;
		this->y = y;

		dx = 12;
		dy = 12;
		fila = columna = 0;

		c_filas = 4;
		c_columnas = 4;
	}

	~Saludable() {
		//delete balas;
	}

	void setDxs() {
		dx = 0;
		dy = 0;
	}

	void setXY() {
		x = 400;
		y = 200;
	}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		alto = img->Height / c_filas;
		ancho = img->Width / c_columnas;

		Rectangle molde = Rectangle(columna * ancho, fila * alto, ancho, alto);
		g->DrawImage(img, x, t, molde, GraphicsUnit::Pixel);
		g->DrawString("COMPRO COMIDA", gcnew Font("Arial", 10), Brushes::DarkBlue, x + 6, y - 3); //para agregar texto en cada personaje saludable, fuente de texto, color, x and y es para la ubicacion del texto encima del personaje(6) hacia la izquierda(3)
		img->MakeTransparent(img->GetPixel(0, 0));

	}

	void setMostrar(Graphics^ g, Bitmap^ img) { // el SetMostrar es para cambiat de color, cuando choca una bala de jugador principal hacia otro personajes para que cambie de colro
		Mostrar(g, img);
	}
	void Mover(int ancho1, int alto1, int index) {
		if (index == 1) { // index en el futuro se va a declarar como Random
			if (y + alto + dy > alto - 100 || y < 0 + 100)dy *= -1; //recuerda que el dy es el movimiento de y

			if (dy > 0) {
				fila = 0; // aquí aparece que el personaje saludable va hacia abajo en el sprite
			}
			else fila = 3; // personaje del sprite hacia arriba
			y += dy;
		}
		else { //si es un valor diferente de 1 se va a ir a izquierda o derecha
			if (x + ancho + dx > ancho1 - 100 /*nota*/ || x < 0) { dx *= -1; setXY(); } // nota: el - 100 es por el control intrínseco del sprite, hay plantas en la imagen
			/*sirve para que vaya a la direccion contraria si es que está cerca del borde (el valor -1)*/
			if (dx > 0) { 
				fila = 2; //personaje se dirige hacia la derecha
			}
			else fila = 1; //personaje se dirige hacia la izquierda
			x += dx;
		}

		columna++;
		if (columna == c_columnas) { //se segura a que no vaya a columnas que no existan
			columna = 0;
		}

	}


};