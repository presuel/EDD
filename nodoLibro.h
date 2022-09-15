#ifndef NODOLIBRO_H_INCLUDED
#define NODOLIBRO_H_INCLUDED
#include "libro.h"

class nodoLibro{        // [ ELEMENTO | *ENLACE ]
    private:
    Libro elemento;
	nodoLibro *enlace;

public:
    nodoLibro(){
		this->enlace= NULL; 
	}

    nodoLibro(Libro elemento){
		this->elemento= elemento;
		this->enlace= NULL; 
	}

    nodoLibro(Libro elemento, nodoLibro *enlace){
		this->elemento= elemento;
		this->enlace= enlace;
	}

    ~nodoLibro() { /**/ }

    void setElemento(Libro elemento){
        this->elemento= elemento;
    }

    Libro getDato(){
        return this->elemento;
    }

    void setEnlace(nodoLibro *enlace){
        this->enlace= enlace;
    }

    nodoLibro *getEnlace(){
        return enlace;
    }

};

#endif // NODOLIBRO_H_INCLUDED