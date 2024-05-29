// ESTUDIATES.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "estudiante.h"
using namespace std;

int main()
{
    string codigo, nombres, apellidos, direccion, fecha_nacimiento, id_tipo_sangre;
    int telefono = 0, id=0;

    estudiante c = estudiante();
    c.leer();
    cout << "Ingrese el ID:";
    cin >> id;
    cin.ignore();

    
    cout << "Ingrese Codigo: ";
    getline(cin,  codigo);
    cout << "Ingrese Nombres: ";
    getline(cin, nombres);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Dirreccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: ";
    cin >> fecha_nacimiento;
    cout << "Ingrese el Tipo de Sangre: ";
    getline(cin, id_tipo_sangre);

        
    
    c = estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre, codigo,id);

    c.actualizar();
    c.leer();
    cout << "Ingrese ID:";
    cin >> id;
    c.setId(id);
    c.leer();
   


    system("pause");
    return 0;
}

