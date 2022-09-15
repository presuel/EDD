#include <iostream>
#include "libro.h"
#include <stack>
using namespace std;

int main(){
    //
    stack<Libro> coleccion;
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
        // Se agrega a la pila
        coleccion.push(tmp_libro);          // Coloca un valor en lo más arriba de la pila
        cout << "Libro almacenado.\n\n";
        //
        cout << "[1] Continuar [0] Finalizar.\n";
        cout << "Ingrese su eleccion= ";
        cin >> continuar;
        cin.ignore();
	}while(continuar == 1);
    // Impresión de la pila
    cout << "\nLista de libros capturados:\n";
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    while(!coleccion.empty()){
        Libro tmp_libro= coleccion.top();   // Recupera el valor de más arriba
        cout << tmp_libro.getAutor() << ". " <<
             tmp_libro.getNombre() << " (" <<
             tmp_libro.getPublicacion() << ")\n\t$ " << 
			 tmp_libro.getPrecio() << "\n";
        coleccion.pop();                    // Elimina el valor de más arriba
    }
    //
    return 0;
}