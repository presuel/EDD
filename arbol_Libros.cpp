#include <iostream>
#include "ArbolBinario_Libro.h"
using namespace std;

Libro capturaLibro(){
    cout << "Captura de datos del libro.\n";
    string tmp_string;
	int tmp_int;
	double tmp_double;
	Libro tmp_libro;
    cout << "Titulo: ";
	getline( cin, tmp_string);
	tmp_libro.setNombre(tmp_string);
    cout << "Autor: ";
	getline( cin, tmp_string);
	tmp_libro.setAutor(tmp_string);
    cout << "Fecha publicacion: ";
	cin >> tmp_int;
	cin.ignore();
	tmp_libro.setPublicacion(tmp_int);
    cout << "Precio compra: ";
	cin >> tmp_double;
	cin.ignore();
	tmp_libro.setPrecio(tmp_double);
    return tmp_libro;
}

int main(){
    arbolBinario misLibros;
    cout << "Arbol binario de Libros.";
    int respuesta;
    do{
        cout << "\n\n----------------------------------------------[CAPTURA]\n";
        Libro nuevoLibro;
        nuevoLibro= capturaLibro();
        // Se agrega al árbol
        misLibros.agregar(nuevoLibro);
        //
        cout << "Oprime 1 continuar, 0 para finalizar= ";
        cin >> respuesta;
        cin.ignore();
    }while(respuesta != 0);
    // Impresiones
    cout << "\n\n---------------------------------------[PRE.ORDEN]\n";
    misLibros.preorden();
    cout << "\n\n---------------------------------------[IN.ORDEN]\n";
    misLibros.inorden();
    cout << "\n\n---------------------------------------[POS.ORDEN]\n";
    misLibros.posorden();
    return 0;
}