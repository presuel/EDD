// SGL - SISTEMA GESTOR DE LIBROS

#include <iostream>
#include <cstdlib>
#include <iomanip> 
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
    tmp_libro.setAutor("no");
    cout << "Fecha publicacion: ";
	cin >> tmp_int;
	cin.ignore();
	tmp_libro.setPublicacion(tmp_int);
    tmp_libro.setPublicacion(0);
    cout << "Precio compra: ";
	cin >> tmp_double;
	cin.ignore();
	tmp_libro.setPrecio(tmp_double);
    tmp_libro.setPrecio(0);
    return tmp_libro;
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

void filaTabla(Libro libro){
        cout << setw(30) << libro.getAutor();
        cout << setw(80) << libro.getNombre();
        cout << setw(15) << libro.getPublicacion();
        cout << setw(15) << libro.getPrecio() << "\n"; 
}

void pieTabla(){
        cout << left << setw(140) << setfill('-') << "-";
        cout << setfill(' ');
        cout << "\n";
}

int main() {
    ListaDinamica_Libro misLibros;
    // ---------------------------------------------------------------------------
    int opc= 0;
    int estilo= 0;
    int exit= 13;
    do {
        system("cls");
        if(estilo){ // Estilo reducido - 1
            cout << "---------------------------------------------\n";
            cout << "Agregar  | (1) Inicio (2) Final.\n";
            cout << "Eliminar | (3) Primer libro (4) Ultimo libro.\n";
            cout << "Imprimir | (5) Cantidad de libros (6) Lista (7) Datos de un libro.\n";
            cout << "Ordenar  | (8) Titulo (9) Autor (10) Precio Menor a Mayor (11) Precio Mayor a Menor.\n";
            cout << "Menu     | (12) Cambiar a menu expandido.\n";
            cout << "Salir    | (13) Sin guardar cambios.\n";
            cout << "---------------------------------------------\n";
            cout << "Opcion: ";
        }else{ // Estilo expandido - 0
            cout << " 1 | Agregar  | Inicio.\n";
            cout << " 2 | Agregar  | Final.\n";
            cout << " 3 | Eliminar | Primer libro.\n";
            cout << " 4 | Eliminar | Ultimo libro.\n";
            cout << " 5 | Imprimir | Cantidad de libros.\n";
            cout << " 6 | Imprimir | Lista completa.\n";
            cout << " 7 | Imprimir | Datos de un libro.\n";
            cout << " 8 | Ordenar  | Titulo.\n";
            cout << " 9 | Ordenar  | Autor.\n";
            cout << "10 | Ordenar  | Precio Menor a Mayor.\n";
            cout << "11 | Ordenar  | Precio Mayor a Menor.\n";
            cout << "12 | Menu     | Cambiar a menu reducido.\n";
            cout << "13 | Salir del programa.\n";
            cout << "---------------------------------------------\n";
            cout << "Opcion: ";
        }
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
                if( misLibros.elementos() ){
                    Libro retirado= misLibros.eliminaNodoInicio();
                    cout << "Se elimino el libro \"" << retirado.getNombre() << "\"\n";
                }else{
                    cout << "La lista esta vacia.\n";
                }
                break;
			}
            case(4): {
                if( misLibros.elementos() ){
                    Libro retirado= misLibros.eliminaNodoFinal();
                    cout << "Se elimino el libro \"" << retirado.getNombre() << "\"\n";
                }else{
                    cout << "La lista esta vacia.\n";
                }
                break;
			}
            case(5): {
                cout << "Libros contenidos en la lista: ";
                cout <<  misLibros.elementos() << "\n";
                break;
			}
            case(6): {
                if( misLibros.elementos() ){
                    encabezadoTabla();
                    for(int i= 0; i<misLibros.elementos(); i++){
                        Libro tmp_libro= misLibros.datoNodo(i);
                        filaTabla(tmp_libro);
					}
                    pieTabla();
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
                    Libro libro= misLibros.datoNodo(num);
                    cout << "Titulo: " << libro.getNombre() << "\n";
                    cout << "Autor: " << libro.getAutor() << "\n";
                    cout << "Publicacion: " << libro.getPublicacion() << "\n";
                    cout << "Precio: $" << libro.getPrecio() << "\n";
				} else {
                    cout << "Error, la lista esta vacia.\n";    
				}
                break;
			}
            case(8):{
                cout << "Lista ordenada por Titulo del libro!\n\n";
                misLibros.ordenarTitulo();
                break;
            }
            case(9):{
                cout << "Lista ordenada por Nombre del autor!\n\n";
                misLibros.ordenarAutor();
                break;
            }
            case(10):{
                cout << "Lista ordenada por Precio de menor a mayor!\n\n";
                misLibros.ordenarPrecioAsc();
                break;
            }
            case(11):{
                cout << "Lista ordenada por Precio de mayor a menor!\n\n";
                misLibros.ordenarPrecioDes();
                break;
            }
            case(12): {
                estilo= (estilo)?0:1;
                break;
			}
            case(13): {                
                system("cls");
                cout << "Finalizando programa.\n";
                break;
			}
            default:
                cout << "Opcion no configurada.\n";
		}
        system("pause");
	}while(opc != exit);
    // ---------------------------------------------------------------------------
    return 0;
}