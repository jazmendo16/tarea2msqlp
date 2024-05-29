#pragma once
#include <iostream>
using namespace std;

class Ttipo_Sangre
{
	// atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento, id_tipo_sangre;
		 int telefono = 0;

		 // costructor
protected:
	Ttipo_Sangre() {
	}
	Ttipo_Sangre(string nom, string ape, string dir, int tel, string fn, string ts) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		id_tipo_sangre = ts;


	}
};

