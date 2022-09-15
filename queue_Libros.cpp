#include <iostream>
#include "libro.h"
#include <queue>
using namespace std;

int main(){
    //
    queue<Libro> coleccion;
    int continuar;
    do{
        // Almacenes temporales
        string tmp_string;
        int tmp_int;
        double tmp_double;
        Libro tmp_libro;
        // Captura de datos
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
        // Se agrega a la cola
        coleccion.push(tmp_libro);          // Coloca un valor al final de la cola
        cout << "Libro almacenado.\n\n";
        //
        cout << "[1] Continuar [0] Finalizar.\n";
        cout << "Ingrese su eleccion= ";
        cin >> continuar;
        cin.ignore();
	}while(continuar == 1);
    // Impresión de la cola
    cout << "\nLista de libros capturados:\n";
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    while(!coleccion.empty()){
        Libro tmp_libro= coleccion.front();   // Recupera el valor del frente de la cola
        cout << tmp_libro.getAutor() << ". " <<
             tmp_libro.getNombre() << " (" <<
             tmp_libro.getPublicacion() << ")\n\t$ " << 
			 tmp_libro.getPrecio() << "\n";
        coleccion.pop();                    // Elimina el valor del frente de la cola
    }
    //
    return 0;
}