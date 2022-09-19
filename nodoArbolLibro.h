#ifndef NODOARBOLLIBRO_H_INCLUDED
#define NODOARBOLLIBRO_H_INCLUDED
#include "Libro.h"

class NodoArbol{
	public:
    NodoArbol(){
        this->izq= NULL;
        this->der= NULL;
    }

    NodoArbol(Libro libro){
        this->libro= libro;
        this->izq= NULL;
        this->der= NULL;
    }

    void setLibro(Libro libro){
        this->libro= libro;
    }

    Libro getLibro(){
        return this->libro;
    }

    void setHijoIzq(NodoArbol *izq){
        this->izq= izq;
    }

    NodoArbol* getHijoIzq(){
        return this->izq;
    }

    void setHijoDer(NodoArbol *der){
        this->der= der;
    }

    NodoArbol* getHijoDer(){
        return this->der;
    }

    protected:
    Libro libro;
    NodoArbol *izq;
    NodoArbol *der;
};

#endif // NODOARBOLLIBRO_H_INCLUDED