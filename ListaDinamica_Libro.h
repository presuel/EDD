#ifndef LISTADINAMICA_LIBRO_H_INCLUDED
#define LISTADINAMICA_LIBRO_H_INCLUDED
#include <iostream>
#include "nodoLibro.h"

class ListaDinamica_Libro {
protected:
    nodoLibro *primero;     // Apuntador al primer nodo.
    nodoLibro *ultimo;      // Apuntador al último nodo.
    nodoLibro *iterador;    // Apuntador para recorrer.
    int contador;           // Cantidad de elementos.
public:
    ListaDinamica_Libro();
    void agregaNodoInicio(Libro libro);
    Libro eliminaNodoInicio();
    void agregaNodoFinal(Libro libro);
    Libro eliminaNodoFinal();
    int elementos();
    Libro datoNodo(int PosBaseCero);
};

ListaDinamica_Libro::ListaDinamica_Libro(){
    primero= new nodoLibro();
    ultimo= new nodoLibro();
    iterador= new nodoLibro();
    contador= 0;
}

void ListaDinamica_Libro::agregaNodoInicio(Libro libro){
    nodoLibro *nuevoLibro= new nodoLibro(libro);
    if( contador ){ // Lista con libros
        nuevoLibro->setEnlace( primero->getEnlace() );
        primero->setEnlace( nuevoLibro );
	} else { // Lista vacía
        primero->setEnlace( nuevoLibro );
        ultimo->setEnlace( nuevoLibro );
	}
    contador++;
}

void ListaDinamica_Libro::agregaNodoFinal(Libro libro){
    nodoLibro *nuevoLibro= new nodoLibro(libro);
    if( contador ){ // Lista con elementos
        ultimo->getEnlace()->setEnlace( nuevoLibro );
        ultimo->setEnlace( nuevoLibro );
	} else { // Lista vacía
        primero->setEnlace( nuevoLibro );
        ultimo->setEnlace( nuevoLibro );
	}
    contador++;
}

Libro ListaDinamica_Libro::eliminaNodoInicio(){
    nodoLibro *libroExtraido;
    if(contador){
        iterador= primero->getEnlace();
        libroExtraido= iterador;
        iterador= iterador->getEnlace();
        libroExtraido->setEnlace( NULL );
        primero->setEnlace( iterador );
        contador--;
	}
    return libroExtraido->getDato();
}

Libro ListaDinamica_Libro::eliminaNodoFinal(){
    nodoLibro *libroExtraido;
    if( contador ){
        iterador= primero->getEnlace();
        for(int i=0; i < contador-2; i++){
            iterador= iterador->getEnlace();
		}// Se coloca uno antes del ultimo
        libroExtraido= iterador->getEnlace();
        iterador->setEnlace( NULL );        
        ultimo->setEnlace( iterador );
        contador--;
	}
    return libroExtraido->getDato();
}

int ListaDinamica_Libro::elementos(){
    return contador;
}

Libro ListaDinamica_Libro::datoNodo(int PosBaseCero){
    if( PosBaseCero < contador ){
        iterador= primero->getEnlace();
        for(int i=0; i < PosBaseCero; i++){
            iterador= iterador->getEnlace();
		}
        return iterador->getDato();
	}
    Libro libro;
    return libro;
}

#endif // LISTADINAMICA_LIBRO_H_INCLUDED