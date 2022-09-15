#include <iostream>
#include <list>
#include "Libro.h"
using namespace std;

int main(){
    list<Libro> coleccion;
    //
    int continuar;
    do{
        // Almacenes temporales
        string tmp_string, eleccion;
        int tmp_int;
        double tmp_double;
        Libro nuevo;
        // Captura de datos
        cout << "Titulo: ";
        getline( cin, tmp_string);
        nuevo.setNombre(tmp_string);
        cout << "Autor: ";
        getline( cin, tmp_string);
        nuevo.setAutor(tmp_string);
        cout << "Fecha publicacion: ";
        cin >> tmp_int;
        cin.ignore();
        nuevo.setPublicacion(tmp_int);
        cout << "Precio compra: ";
        cin >> tmp_double;
        cin.ignore();
        nuevo.setPrecio(tmp_double);
        // Se agrega a la lista
        cout << "[i] Agregar al inicio. [f] Agregar la final | Elección: ";
        cin >> eleccion;
        if( eleccion == "i" ){
			coleccion.push_front(nuevo);
        } else {
			coleccion.push_back(nuevo);
        } 
        cout << "... .. . Libro almacenado.\n\n";
        // ------- ------- ------- Control del bucle        
        cout << "[1] Continuar [0] Finalizar.\n";
        cout << "Ingrese su eleccion= ";
        cin >> continuar;
        cin.ignore();
    }while(continuar == 1);
    // Impresión de la lista
    cout << "Extrayendo los elementos de la lista.\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";	
    while(!coleccion.empty()){
        Libro ejemplar;
        string eleccion;
		cout << "[i] Extrae del inicio. [f] Extrae del final. | Eleccion: ";
		cin >> eleccion;
        if( eleccion == "i" ){
			ejemplar= coleccion.front();			
			coleccion.pop_front();
		}else{
			ejemplar= coleccion.back();			
			coleccion.pop_back();
		}
        cout << ejemplar.getAutor() << ". " <<
				ejemplar.getNombre() << " (" <<
				ejemplar.getPublicacion() << ")\n\t$ " <<
				ejemplar.getPrecio() << "\n";     
    }
    return 0;
}