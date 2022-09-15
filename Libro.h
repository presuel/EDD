#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <iostream>
using namespace std;

// DECLARACION DE LA CLASE
class Libro{
	private:
    string nombre;
    string autor;
    int publicacion;
    double precio;
    //
    public:
    Libro();    
    ~Libro();
    void setNombre(string nombre);
    string getNombre();
    void setAutor(string autor);
    string getAutor();
    void setPublicacion(int publicacion);
    int getPublicacion();
    void setPrecio(double precio);
    double getPrecio();
};

// IMPLEMENTACION DE LA CLASE
Libro::Libro(){
    //
}

Libro::~Libro(){
    //
}

void Libro::setNombre(string nombre){
    this->nombre= nombre;
}

string Libro::getNombre(){
    return this->nombre;
}

void Libro::setAutor(string autor){
    this->autor= autor;
}

string Libro::getAutor(){
    return this->autor;
}

void Libro::setPublicacion(int publicacion){
    this->publicacion= publicacion;
}

int Libro::getPublicacion(){
    return this->publicacion;
}

void Libro::setPrecio(double precio){
    this->precio= precio;
}

double Libro::getPrecio(){
    return this->precio;
}

#endif // LIBRO_H_INCLUDED