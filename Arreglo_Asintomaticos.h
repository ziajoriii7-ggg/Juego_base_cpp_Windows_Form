#pragma once
#include "Asintomatico.h"
#include <fstream>

class Arreglo_Asintomaticos {
private:
	Asintomatico** ene;
	int cant_asintomatico;
public:
	Arreglo_Asintomaticos() {
		cant_asintomatico = 0;
		ene = new Asintomatico * [cant_asintomatico];
	}

};