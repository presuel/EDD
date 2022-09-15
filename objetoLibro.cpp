#include <iostream>
#include "libro.h"      // Clase Libro
using namespace std;

int main(){
    //
    Libro ejemplar1;
    ejemplar1.setAutor("Jose Luis Joyanes");
    ejemplar1.setNombre("Programacion en C, C++, Java y UML");
    ejemplar1.setPrecio(570.00);
    ejemplar1.setPublicacion(2012);
    //
    cout << "Datos del libro: " << ejemplar1.getNombre() << ". "
         << ejemplar1.getAutor() << " (" << ejemplar1.getPublicacion() << "). "
         << "$ " << ejemplar1.getPrecio() << endl;
    //
    return 0;
}