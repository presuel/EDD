#ifndef ARBOLBINARIO_LIBRO_H_INCLUDED
#define ARBOLBINARIO_LIBRO_H_INCLUDED
#include "nodoArbolLibro.h"
#include <iomanip> 

class arbolBinario{
	public:
    arbolBinario(){
        this->raiz= NULL;
    }

    bool estaVacio(){
        return this->raiz == NULL;
    }

    NodoArbol* getRaiz(){
        if(this->raiz){ 
            return this->raiz;
        } else {
            throw "árbol vacío"; 
        }
    }

    void setRaiz(Libro libro){
        NodoArbol *nuevo= new NodoArbol(libro);
        this->raiz= nuevo;
    }

    void agregar(Libro libro){
		if( !estaVacio() ){ // se buscará dónde colocar el nuevo libro
            NodoArbol *aux= getRaiz();
            bool requiereUbicar= true;
            while(requiereUbicar){
				// ------------------------------------------- || CRITERIO => Nombre del libro ||
                string valorAux= aux->getLibro().getNombre();
                string valorNodo= libro.getNombre();
                // compare results: 0= equal, <0= lower, >0= greater
                if( (valorNodo).compare(valorAux) < 0){
                    if( aux->getHijoIzq() == NULL ){
                        NodoArbol *nuevo= new NodoArbol(libro);
                        aux->setHijoIzq(nuevo);
                        requiereUbicar= false;
                    } else {
                        aux= aux->getHijoIzq();
                    }
                } else if((valorNodo).compare(valorAux)>0){
                    if( aux->getHijoDer() == NULL ){
                        NodoArbol *nuevo= new NodoArbol(libro);
                        aux->setHijoDer(nuevo);
                        requiereUbicar= false;
                    } else {
                        aux= aux->getHijoDer();
                    }
                } else { // el libro ya existe
                    requiereUbicar= false;
                }
			}
        } else { // el árbol está vacío, el nuevo libro será la raíz
            setRaiz(libro);
        }
	}

    void eliminar(Libro libro){
        //         
    }

    void encabezadoTabla(){
        cout << left << setw(30) << "Autor";
        cout << left << setw(80) << "Nombre del libro";
        cout << left << setw(15) << "Fecha";
        cout << left << setw(15) << "Precio";
        cout << "\n";        
        cout << left << setw(140) << setfill('-') << "-";
        cout << setfill(' ');
        cout << "\n";
    }

    void pieTabla(){
        cout << left << setw(140) << setfill('-') << "-";
        cout << setfill(' ');
        cout << "\n";
    }

    void filaTabla(Libro libro){
        cout << setw(30) << libro.getAutor();
        cout << setw(80) << libro.getNombre();
        cout << setw(15) << libro.getPublicacion();
        cout << setw(15) << libro.getPrecio() << "\n"; 
    }

    void preorden(){
        encabezadoTabla();
        preorden(this->raiz);
        pieTabla();
    }

    void inorden(){
        encabezadoTabla();
        inorden(this->raiz);
        pieTabla();
    }

    void posorden(){
        encabezadoTabla();
        posorden(this->raiz);
        pieTabla();
    }

    private:
    NodoArbol *raiz;

    void preorden(NodoArbol *r){ // raiz, izq, der    
        if( r != NULL ){
            Libro libro= r->getLibro();
            filaTabla(libro);
            preorden(r->getHijoIzq());
            preorden(r->getHijoDer());
        }
    }

    void inorden(NodoArbol *r){// izq, raiz, der
        if( r != NULL ){
            inorden(r->getHijoIzq());
            Libro libro= r->getLibro();
            filaTabla(libro);
            inorden(r->getHijoDer());
        }
    }

    void posorden(NodoArbol *r){// izq, der, raiz
        if( r != NULL ){
            posorden(r->getHijoIzq());
            posorden(r->getHijoDer());
            Libro libro= r->getLibro();
            filaTabla(libro);
        }
    }
};

#endif // ARBOLBINARIO_LIBRO_H_INCLUDED