#include <iostream>
#include "Libro.h"
using namespace std;

int main(int argc, char *argv[]){
    //
    int cantidad= 2;
    Libro arreglo[cantidad];

    // CAPTURA
    for(int i=0; i<cantidad; i++){
        string tmp_string;
        int tmp_int;
        double tmp_double;

        cout << "Libro numero " << i+1 << "\n";
        cout << "Titulo: ";
        getline( cin, tmp_string);
        arreglo[i].setNombre(tmp_string);

        cout << "Autor: ";
        getline( cin, tmp_string);
        arreglo[i].setAutor(tmp_string);

        cout << "Fecha publicacion: ";
        cin >> tmp_int;
        cin.ignore();
        arreglo[i].setPublicacion(tmp_int);

        cout << "Precio compra: ";
        cin >> tmp_double;
        cin.ignore();
        arreglo[i].setPrecio(tmp_double);

        cout << "... .. . Libro almacenado!\n\n";
	}

    // PRESENTACION DE LA LISTA
    cout << "Lista de libros capturados:\n";
    for(int i=0; i<cantidad; i++){
        cout << i+1 << ") " <<
             arreglo[i].getNombre() << ". " <<
             arreglo[i].getAutor() << " (" <<
             arreglo[i].getPublicacion() << ")\n\t$ " 
			 << arreglo[i].getPrecio() << "\n";
	}	
    //
    return 0;
}