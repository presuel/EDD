// SGL - SISTEMA GESTOR DE LIBROS

#include <iostream>
#include <cstdlib>
#include "listaDinamica_Libro.h"
using namespace std;

Libro capturaLibro(){
    cout << "Captura de datos del libro.\n\n";
    string tmp_string;
	int tmp_int;
	double tmp_double;
	Libro tmp_libro;
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
    return tmp_libro;
}

int main() {
    ListaDinamica_Libro misLibros;
    // ---------------------------------------------------------------------------
    int opc= 0;
    do {
        system("cls");
        cout << "Sistema Gestor de Libros.\n";
        cout << "1 | Agregar al Inicio.\n";
        cout << "2 | Agregar al Final.\n";
        cout << "3 | Eliminar el Primer libro.\n";
        cout << "4 | Eliminar el Ultimo libro.\n";
        cout << "5 | Cantidad de libros.\n";
        cout << "6 | Imprimir lista.\n";
        cout << "7 | Imprimir datos de un libro.\n";
        cout << "8 | Salir del programa.\n";
        cout << "Opcion: ";
        cin >> opc;
        cin.ignore();
        cout << "---------------------------------------------\n\n";
        switch(opc){
            case(1): {
                Libro nuevoLibro;
				nuevoLibro= capturaLibro();
                misLibros.agregaNodoInicio(nuevoLibro);
                break;
			}
            case(2): {
                Libro nuevoLibro;
				nuevoLibro= capturaLibro();
                misLibros.agregaNodoFinal(nuevoLibro);
                break;
			}
            case(3): {
                misLibros.eliminaNodoInicio();
                break;
			}
            case(4): {
                misLibros.eliminaNodoFinal();
                break;
			}
            case(5): {
                cout << "Libros contenidos en la lista: ";
                cout <<  misLibros.elementos() << "\n";
                break;
			}
            case(6): {
                if( misLibros.elementos() ){
                    for(int i= 0; i<misLibros.elementos(); i++){
                        Libro tmp_libro= misLibros.datoNodo(i);
                        cout << tmp_libro.getAutor() << ". " <<
                                tmp_libro.getNombre() << " (" <<
                                tmp_libro.getPublicacion() << ")\n\t$ " <<
                                tmp_libro.getPrecio() << "\n";
					}
				} else {
                    cout << "No hay libros en la lista.\n"; 
				}
                break;
			}
            case(7): {
                if( misLibros.elementos() ){
                    int num;
                    cout << "Ingrese el indice del elemento: ";
                    cin >> num;
                    if(num < 0 || num >= misLibros.elementos()) break;
                    Libro tmp_libro= misLibros.datoNodo(num);
                    cout << tmp_libro.getAutor() << ". " <<
                            tmp_libro.getNombre() << " (" <<
                            tmp_libro.getPublicacion() << ")\n\t$ " <<
                            tmp_libro.getPrecio() << "\n";
				} else {
                    cout << "Error, la lista esta vacia.\n";    
				}
                break;
			}
            case(8): {
                cout << "Finalizando programa.\n";
                break;
			}
            default:
                cout << "Opcion no configurada.\n";
		}
        system("pause");
	}while(opc != 8);
    // ---------------------------------------------------------------------------
    return 0;
}