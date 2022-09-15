#include <iostream>
#include "nodoLibro.h"
using namespace std;

void recorrerListaPrincipio(nodoLibro *iterador){
	if( iterador ){
		cout << iterador->getDato().getAutor() << " - " <<
             iterador->getDato().getNombre() << " (" <<
             iterador->getDato().getPublicacion() << ")\n\t$ " << 
             iterador->getDato().getPrecio() << "\n";
        //
        recorrerListaPrincipio(iterador->getEnlace());
	}
}

void recorrerListaInvertida(nodoLibro *iterador){
	if( iterador ){
        recorrerListaInvertida(iterador->getEnlace());
        //
        cout << iterador->getDato().getAutor() << " - " <<
             iterador->getDato().getNombre() << " (" <<
             iterador->getDato().getPublicacion() << ")\n\t$ " << 
             iterador->getDato().getPrecio() << "\n";
	}
}

int main(int argc, char *argv[]){
    //
    nodoLibro *inicio= new nodoLibro();     // Punto de acceso a la lista
    int continuar;
    do{
        string tmp_string;
        int tmp_int;
        double tmp_double;
        Libro nuevo;            // Libro que contendrá los datos del libro a capturar
        // -----------------------------------
        cout << "Titulo: ";
        getline( cin, tmp_string);
        nuevo.setNombre(tmp_string);
        cout << "Autor: ";
        getline( cin, tmp_string);
        nuevo.setAutor(tmp_string);
        cout << "Fecha publicacion: ";
        cin >> tmp_int;cin.ignore();
        nuevo.setPublicacion(tmp_int);
        cout << "Precio compra: ";
        cin >> tmp_double;cin.ignore();
        nuevo.setPrecio(tmp_double);
        // ----------------------------------- Se crea el nuevo nodo de libro.
        nodoLibro *nodoNuevo= new nodoLibro (nuevo);
        // ----------------------------------- Se recorre la lista para colocarlo al final.
        nodoLibro *iterador= inicio;
        while( iterador->getEnlace() != NULL ){ // Si el siguiente no es NULL avanza al siguiente
            iterador= iterador->getEnlace();
        }
        iterador->setEnlace( nodoNuevo );   // Agrega al final de la lista el libro nuevo
        cout << "... .. . Libro almacenado!\n\n";
        // --------------------------- Pregunta para continuar
        cout << "[1] Continuar [0] Finalizar .:. Ingrese su eleccion= ";
        cin >> continuar;
        cin.ignore();
	}while(continuar == 1);
    // ----------------------------------- Presentación de la lista
    cout << "\nLista de libros capturados:\n";
    nodoLibro *iterador= inicio->getEnlace();
    while( iterador != NULL ){
        cout << iterador->getDato().getAutor() << ". " <<
             iterador->getDato().getNombre() << " (" <<
             iterador->getDato().getPublicacion() << ")\n\t$ " <<
             iterador->getDato().getPrecio() << "\n";
        iterador= iterador->getEnlace();    // Avanza al siguiente nodo
    }
    // ------------------------------------ Recorrido con recursividad
    cout << "\nRecorriendo la lista con recursividad:\n";
    recorrerListaPrincipio(inicio->getEnlace());
    // ------------------------------------ Recorrido Invertido con recursividad
    cout << "\nRecorriendo la lista invertida con recursividad:\n";
    recorrerListaInvertida(inicio->getEnlace());
    return 0;
}
