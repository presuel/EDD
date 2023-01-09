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
    void ordenarTitulo();
    void ordenarAutor();
    void ordenarPrecioAsc();
    void ordenarPrecioDes();
    void QuickTitulo (nodoLibro *inicial, nodoLibro *final);
    void QuickAutor (nodoLibro *inicial, nodoLibro *final);
    void QuickPrecioAsc (nodoLibro *inicial, nodoLibro *final);
    void QuickPrecioDes (nodoLibro *inicial, nodoLibro *final);
    Libro buscarLibro_Nombre(string buscado);
    Libro buscarLibro_Autor(string buscado);
    ListaDinamica_Libro buscarLibros_Nombre( string buscado );
    ListaDinamica_Libro buscarLibros_Autor( string buscado );
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
    if(contador){
        nodoLibro *extraido;
        iterador= primero->getEnlace();
        extraido= iterador;
        iterador= iterador->getEnlace();
        primero->setEnlace( iterador );
        extraido->setEnlace( NULL );        
        contador--;
        return extraido->getDato();
	}else{
        return ultimo->getDato();
    }
}

Libro ListaDinamica_Libro::eliminaNodoFinal(){
    if( contador > 1 ){
        iterador= primero->getEnlace();
        nodoLibro *extraido= iterador->getEnlace();
        while( extraido != ultimo->getEnlace() ){
            iterador= iterador->getEnlace();
            extraido= extraido->getEnlace();
        }
        ultimo->setEnlace( iterador ); // desconexión
        iterador->setEnlace( NULL );
        contador--;
        return extraido->getDato();
    } else if ( contador == 1 ){
        nodoLibro *extraido= primero->getEnlace();
        primero->setEnlace( NULL ); // desconexión
        ultimo->setEnlace( NULL );
        contador--;
        return extraido->getDato();
    } else {
        return ultimo->getDato();
    }
    nodoLibro *libroExtraido;
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

/*
void ListaDinamica_Libro::ordenarTitulo(){      // ITERATIVO, INTERCAMBIANDO VALORES
    if( this->elementos() > 1){
        nodoLibro *itemA= primero->getEnlace();
        for(int i=0; i < this->elementos()-1; i++){
            nodoLibro *itemB= itemA->getEnlace();
            for(int j=i+1; j<this->elementos(); j++){
                //Nombre
                if( (itemA->getDato().getNombre()).compare( itemB->getDato().getNombre()) > 0){
                    nodoLibro itemX;
                    itemX.setElemento( itemB->getDato() );
                    itemB->setElemento( itemA->getDato() );
                    itemA->setElemento( itemX.getDato() );
                }
                itemB= itemB->getEnlace();
            }
            itemA= itemA->getEnlace();
        }
    }
}

void ListaDinamica_Libro::ordenarAutor(){      // ITERATIVO, INTERCAMBIANDO VALORES
    if( this->elementos() > 1){
        nodoLibro *itemA= primero->getEnlace();
        for(int i=0; i < this->elementos()-1; i++){
            nodoLibro *itemB= itemA->getEnlace();
            for(int j=i+1; j<this->elementos(); j++){
                //Autor
                if( (itemA->getDato().getAutor()).compare( itemB->getDato().getAutor()) > 0){
                    nodoLibro itemX;
                    itemX.setElemento( itemB->getDato() );
                    itemB->setElemento( itemA->getDato() );
                    itemA->setElemento( itemX.getDato() );
                }
                itemB= itemB->getEnlace();
            }
            itemA= itemA->getEnlace();
        }
    }
}

void ListaDinamica_Libro::ordenarPrecioAsc(){      // ITERATIVO, INTERCAMBIANDO VALORES
    if( this->elementos() > 1){
        nodoLibro *itemA= primero->getEnlace();
        for(int i=0; i < this->elementos()-1; i++){
            nodoLibro *itemB= itemA->getEnlace();
            for(int j=i+1; j<this->elementos(); j++){
                //Precio Ascencente
                if( itemA->getDato().getPrecio() > itemB->getDato().getPrecio() ){
                    nodoLibro itemX;
                    itemX.setElemento( itemB->getDato() );
                    itemB->setElemento( itemA->getDato() );
                    itemA->setElemento( itemX.getDato() );
                }
                itemB= itemB->getEnlace();
            }
            itemA= itemA->getEnlace();
        }
    }
}

void ListaDinamica_Libro::ordenarPrecioDes(){      // ITERATIVO, INTERCAMBIANDO VALORES
    if( this->elementos() > 1){
        nodoLibro *itemA= primero->getEnlace();
        for(int i=0; i < this->elementos()-1; i++){
            nodoLibro *itemB= itemA->getEnlace();
            for(int j=i+1; j<this->elementos(); j++){
                //Precio Descendente
                if( itemA->getDato().getPrecio() < itemB->getDato().getPrecio() ){
                    nodoLibro itemX;
                    itemX.setElemento( itemB->getDato() );
                    itemB->setElemento( itemA->getDato() );
                    itemA->setElemento( itemX.getDato() );
                }
                itemB= itemB->getEnlace();
            }
            itemA= itemA->getEnlace();
        }
    }
}
*/

void ListaDinamica_Libro::ordenarTitulo(){      // RECURSIVO, MANIPULANDO APUNTADORES
    QuickTitulo (primero, ultimo);
}

void ListaDinamica_Libro::ordenarAutor(){      // RECURSIVO, MANIPULANDO APUNTADORES
    QuickAutor (primero, ultimo);
}

void ListaDinamica_Libro::ordenarPrecioAsc(){      // RECURSIVO, MANIPULANDO APUNTADORES
    QuickPrecioAsc (primero, ultimo);
}

void ListaDinamica_Libro::ordenarPrecioDes(){      // RECURSIVO, MANIPULANDO APUNTADORES
    QuickPrecioDes (primero, ultimo);
}

void ListaDinamica_Libro::QuickTitulo (nodoLibro *inicial, nodoLibro *final) {
    // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
    // Probar a futuro convertir a función lambda.
    iterador= inicial->getEnlace();
    nodoLibro *pivote= final->getEnlace();
    if( iterador != pivote ){
        int menores= 0, mayores= 0;
        nodoLibro *D_i= new nodoLibro;
        nodoLibro *D_f= new nodoLibro; 
        nodoLibro *I_i= new nodoLibro;
        nodoLibro *I_f= new nodoLibro;
        while( iterador != pivote ) {
            // cout << iterador->getDato().getNombre() << " vs " << pivote->getDato().getNombre() << "\n";
            if( (iterador->getDato().getNombre()).compare(pivote->getDato().getNombre())>0){
                (mayores++)? I_f->getEnlace()->setEnlace(iterador) : I_i->setEnlace(iterador);
                I_f->setEnlace(iterador);
            } else {
                (menores++)? D_f->getEnlace()->setEnlace(iterador) : D_i->setEnlace(iterador);
                D_f->setEnlace(iterador);
            }
            iterador= iterador->getEnlace();
        }
        // Llamada recursiva para ordenamiento
        if(menores>1) QuickTitulo(D_i, D_f);
        if(mayores>1) QuickTitulo(I_i, I_f);
        // Reunión de segmentos
        if( menores>0 && mayores>0 ){
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores>0 && mayores==0) {
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            final->setEnlace( pivote );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores==0 && mayores>0) {
            inicial->setEnlace( pivote );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        }
    }
}

void ListaDinamica_Libro::QuickAutor (nodoLibro *inicial, nodoLibro *final) {
    // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
    iterador= inicial->getEnlace();
    nodoLibro *pivote= final->getEnlace();
    if( iterador != pivote ){
        int menores= 0, mayores= 0;
        nodoLibro *D_i= new nodoLibro;
        nodoLibro *D_f= new nodoLibro;
        nodoLibro *I_i= new nodoLibro;
        nodoLibro *I_f= new nodoLibro;
        while( iterador != pivote ) {
            if( (iterador->getDato().getAutor()).compare(pivote->getDato().getAutor())>0){
                (mayores++)? I_f->getEnlace()->setEnlace(iterador) : I_i->setEnlace(iterador);
                I_f->setEnlace(iterador);
            } else {
                (menores++)? D_f->getEnlace()->setEnlace(iterador) : D_i->setEnlace(iterador);
                D_f->setEnlace(iterador);
            }
            iterador= iterador->getEnlace();
        }
        // Llamada recursiva para ordenamiento
        if(menores>1) QuickAutor(D_i, D_f);
        if(mayores>1) QuickAutor(I_i, I_f);
        // Reunión de segmentos
        if( menores>0 && mayores>0 ){
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores>0 && mayores==0) {
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            final->setEnlace( pivote );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores==0 && mayores>0) {
            inicial->setEnlace( pivote );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        }
    }
}

void ListaDinamica_Libro::QuickPrecioAsc (nodoLibro *inicial, nodoLibro *final) {
    // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
    iterador= inicial->getEnlace();
    nodoLibro *pivote= final->getEnlace();
    if( iterador != pivote ){
        int menores= 0, mayores= 0;
        nodoLibro *D_i= new nodoLibro;
        nodoLibro *D_f= new nodoLibro;
        nodoLibro *I_i= new nodoLibro;
        nodoLibro *I_f= new nodoLibro;
        while( iterador != pivote ) {
            if( iterador->getDato().getPrecio() > pivote->getDato().getPrecio() ){
                (mayores++)? I_f->getEnlace()->setEnlace(iterador) : I_i->setEnlace(iterador);
                I_f->setEnlace(iterador);
            } else {
                (menores++)? D_f->getEnlace()->setEnlace(iterador) : D_i->setEnlace(iterador);
                D_f->setEnlace(iterador);
            }
            iterador= iterador->getEnlace();
        }
        // Llamada recursiva para ordenamiento
        if(menores>1) QuickPrecioAsc(D_i, D_f);
        if(mayores>1) QuickPrecioAsc(I_i, I_f);
        // Reunión de segmentos
        if( menores>0 && mayores>0 ){
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores>0 && mayores==0) {
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            final->setEnlace( pivote );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores==0 && mayores>0) {
            inicial->setEnlace( pivote );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        }
    }
}

void ListaDinamica_Libro::QuickPrecioDes (nodoLibro *inicial, nodoLibro *final) {
    // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
    iterador= inicial->getEnlace();
    nodoLibro *pivote= final->getEnlace();
    if( iterador != pivote ){
        int menores= 0, mayores= 0;
        nodoLibro *D_i= new nodoLibro;
        nodoLibro *D_f= new nodoLibro;
        nodoLibro *I_i= new nodoLibro;
        nodoLibro *I_f= new nodoLibro;
        while( iterador != pivote ) {
            if( iterador->getDato().getPrecio() < pivote->getDato().getPrecio() ){
                (mayores++)? I_f->getEnlace()->setEnlace(iterador) : I_i->setEnlace(iterador);
                I_f->setEnlace(iterador);
            } else {
                (menores++)? D_f->getEnlace()->setEnlace(iterador) : D_i->setEnlace(iterador);
                D_f->setEnlace(iterador);
            }
            iterador= iterador->getEnlace();
        }
        // Llamada recursiva para ordenamiento
        if(menores>1) QuickPrecioDes(D_i, D_f);
        if(mayores>1) QuickPrecioDes(I_i, I_f);
        // Reunión de segmentos
        if( menores>0 && mayores>0 ){
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores>0 && mayores==0) {
            D_f->getEnlace()->setEnlace( pivote );
            inicial->setEnlace( D_i->getEnlace() );
            final->setEnlace( pivote );
            final->getEnlace()->setEnlace(NULL);
        } else if(menores==0 && mayores>0) {
            inicial->setEnlace( pivote );
            pivote->setEnlace( I_i->getEnlace() );
            final->setEnlace( I_f->getEnlace() );
            final->getEnlace()->setEnlace(NULL);
        }
    }
}

Libro ListaDinamica_Libro::buscarLibro_Nombre(string buscado){
    Libro libro;
    iterador= primero->getEnlace();
    while(iterador){
        if((iterador->getDato().getNombre()).compare(buscado)==0){
            libro= iterador->getDato();
            return libro;
        }
        iterador= iterador->getEnlace();
    }
    return libro;
}

Libro ListaDinamica_Libro::buscarLibro_Autor(string buscado){
    Libro libro;
    iterador= primero->getEnlace();
    while(iterador){
        if((iterador->getDato().getAutor()).compare(buscado)==0){
            libro= iterador->getDato();
            return libro;
        }
        iterador= iterador->getEnlace();
    }
    return libro;
}

ListaDinamica_Libro ListaDinamica_Libro::buscarLibros_Nombre( string buscado ){
    ListaDinamica_Libro encontrados;
    iterador= primero->getEnlace();
    while(iterador){
        if((iterador->getDato().getNombre()).compare(buscado)==0){
            encontrados.agregaNodoFinal( iterador->getDato() );
        }
        iterador= iterador->getEnlace();
    }
    return encontrados;
}

ListaDinamica_Libro ListaDinamica_Libro::buscarLibros_Autor( string buscado ){
    ListaDinamica_Libro encontrados;
    iterador= primero->getEnlace();
    while(iterador){
        if((iterador->getDato().getAutor()).compare(buscado)==0){
            encontrados.agregaNodoFinal( iterador->getDato() );
        }
        iterador= iterador->getEnlace();
    }
    return encontrados;
}

#endif // LISTADINAMICA_LIBRO_H_INCLUDED