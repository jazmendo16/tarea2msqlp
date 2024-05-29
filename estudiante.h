#include <mysql.h>
#include <iostream>
#include <string>
#include "conexionDB.h"
#include "Ttipo_Sangre.h"

using namespace std;

class estudiante : public Ttipo_Sangre{
private: string codigo;
	   int id = 0;
	   // constructor
public:
	estudiante() {
	}
	estudiante(string nom, string ape, string dir, int tel, string fn, string ts, string co, int i) : Ttipo_Sangre(nom, ape, dir, tel, fn,ts) {
		codigo = co;
		id = i;
	}
	// METODOS
	//set (modificar)
	void setId(int i) { id = i; }
	void setNit(int co) { codigo = co; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	void setId_tipo_sangre(string ts) { id_tipo_sangre = ts; }
	//get (mostrar)
	int getId() { return id; }
	string getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	string getId_tipo_sangre() { return id_tipo_sangre; }

	// metodo
	void borrar() {
		int q_estado;
		conexionDB cn = conexionDB();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string  borrar =
				"delete from estudiantes  where id_estudiante = " + ii + "";
			const char* i = borrar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar() {
		int q_estado;
		conexionDB cn = conexionDB();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string  actualizar =
				"update clientes set codigo = '" + codigo + "', nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono =" + t + ", fecha_nacimiento='" + fecha_nacimiento + "' where id_estudiantes = " + ii + "";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		conexionDB cn = conexionDB();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar =
				"INSERT INTO estudiantes(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento,id_tipo_sangre) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + "','" + fecha_nacimiento + ",'" + id_tipo_sangre +"')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		conexionDB cn = conexionDB();

		MYSQL_ROW fila;
		MYSQL_RES* resultado; 
		cn.abrir_conexion(); 

		if (cn.getConectar()) {

			cout << "------------ Datos del Estudiante ------------" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}



};
