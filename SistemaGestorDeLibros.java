import java.io.*;
import java.util.Scanner;

public class SistemaGestorDeLibros {

    private static void capturaDatos(listaDinamica_Libro coleccion, String ubicacion) {
        Scanner lectura = new Scanner(System.in);
        Libro libroNuevo = new Libro();
        // ------- ------- ------- Captura
        System.out.println("_______Ingrese los datos del libro_______");
        System.out.print("Titulo del libro: ");
        libroNuevo.setNombre(lectura.nextLine());
        System.out.print("Autor: ");
        libroNuevo.setAutor(lectura.nextLine());
        System.out.print("Precio de compra: ");
        libroNuevo.setPrecio(lectura.nextDouble());
        System.out.print("Fecha de publicacion: ");
        libroNuevo.setPublicacion(lectura.nextInt());
        // ------- ------- ------- Incersión
        switch (ubicacion) {
            case "i":
                coleccion.agregaInicio(libroNuevo);
                break;
            case "f":
                coleccion.agregaFinal(libroNuevo);
                break;
            default:
                // Si llegó a este punto, es un ERROR.
                break;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int contador= -1;
        // -------------------------------------------------------------------------
        try ( FileWriter fw = new FileWriter("biblioteca.txt", true) ){            
            fw.close();
            contador= 0;
        }catch(Exception e){
            e.printStackTrace();
        }
        // -------------------------------------------------------------------------
        try ( BufferedReader bfr = new BufferedReader(new FileReader("biblioteca.txt")) ){
            String cadena = bfr.readLine();
            contador++;
            while( cadena != null ){
                cadena= bfr.readLine(); // Se cuentan las lineas en general y luego se divide por el número de campos
                contador++;
            }
            contador /= 4;
        }catch(Exception e){
            e.printStackTrace();
        }
        // -------------------------------------------------------------------------
        if( contador > 0){
            System.out.println("Registros de libros encontrados: " + contador);
        } else {
            System.out.println("Nose encontraron registros de libros.");
        }
        System.out.println("------- Oprima ENTER para continuar -------");
        scan.nextLine();
        // -------------------------------------------------------------------------
        listaDinamica_Libro coleccion = new listaDinamica_Libro();
        int opcion;
        int exit = 18;
        do {
            // Menu
            System.out.print("\033[H\033[2J");
            System.out.println("------- ------- ------- ------- -------");
            System.out.println("Sistema Gestor de Libros.");
            System.out.println(" 1 | Agregar  | Inicio.");
            System.out.println(" 2 | Agregar  | Final.");
            System.out.println(" 3 | Eliminar | Primer libro.");
            System.out.println(" 4 | Eliminar | Ultimo libro.");
            System.out.println(" 5 | Imprimir | Cantidad de libros.");
            System.out.println(" 6 | Imprimir | Lista completa.");
            System.out.println(" 7 | Imprimir | Datos de un libro.");
            System.out.println(" 8 | Ordenar  | Titulo.");
            System.out.println(" 9 | Ordenar  | Autor.");
            System.out.println("10 | Ordenar  | Precio Menor a Mayor.");
            System.out.println("11 | Ordenar  | Precio Mayor a Menor.");
            System.out.println("12 | Buscar   | Libro por Titulo.");
            System.out.println("13 | Buscar   | Libro por Autor.");
            System.out.println("14 | Buscar   | Libros por Titulo.");
            System.out.println("15 | Buscar   | Libros por Autor.");
            System.out.println("16 | Archivo  | Cargar registros.");
            System.out.println("17 | Archivo  | Guardar registros");
            System.out.println("18 | Salir del programa.");
            System.out.println("------- ------- ------- ------- -------");
            System.out.print("Accion a realizar: ");
            opcion = scan.nextInt();
            scan.nextLine();
            // -----------------
            switch (opcion) {
                case 1:
                    capturaDatos(coleccion, "i");
                    System.out.println("Se agregó el libro!");
                    break;
                case 2:
                    capturaDatos(coleccion, "f");
                    System.out.println("Se agregó el libro!");
                    break;
                case 3:
                    if (!coleccion.isEmpty()) {
                        coleccion.eliminaInicio();
                        System.out.println("Se eliminó el libro!");
                    } else {
                        System.out.println("La lista esta vacia.");
                    }
                    break;
                case 4:
                    if (!coleccion.isEmpty()) {
                        coleccion.eliminaFinal();
                        System.out.println("Se eliminó el libro!");
                    } else {
                        System.out.println("La lista esta vacia.");
                    }
                    break;
                case 5:
                    System.out.println("Elementos: " + coleccion.getElementos() + ".\n");
                    break;
                case 6:
                    if (!coleccion.isEmpty()) {
                        for (int i = 0; i < coleccion.getElementos(); i++) {
                            System.out.println(coleccion.getDatosLibro(i));
                        }
                        System.out.println("------- Oprima ENTER para continuar -------");
                        scan.nextLine();
                    } else {
                        System.out.println("No hay libros en la coleccion");
                    }
                    break;
                case 7:
                    int indice;
                    System.out.println("Ingrese el indice del libro: ");
                    indice = scan.nextInt();
                    if (indice > -1 && indice < coleccion.getElementos()) {
                        Libro accedido;
                        accedido = coleccion.getLibro(indice);
                        System.out.println("Título: " + accedido.getNombre());
                        System.out.println("Autor: " + accedido.getAutor());
                        System.out.println("Año: " + accedido.getPublicacion());
                        System.out.println("Precio: $ " + accedido.getPrecio());
                    }
                    break;
                case 8: {
                    coleccion.ordenarTitulo();
                    System.out.println("Se ordenó la lista dinámica!");
                    break;
                }
                case 9: {
                    coleccion.ordenarAutor();
                    System.out.println("Se ordenó la lista dinámica!");
                    break;
                }
                case 10: {
                    coleccion.ordenarPrecioAsc();
                    System.out.println("Se ordenó la lista dinámica!");
                    break;
                }
                case 11: {
                    coleccion.ordenarPrecioDes();
                    System.out.println("Se ordenó la lista dinámica!");
                    break;
                }
                case 12: {
                    System.out.println("Nombre de libro a buscar (coincidencia exacta): ");
                    Libro libro = coleccion.buscarLibro_Nombre(scan.nextLine());
                    if (libro.getNombre().compareTo("error") != 0) {
                        System.out.println("----------------------------------------------");
                        System.out.println("Titulo: " + libro.getNombre());
                        System.out.println("Autor: " + libro.getAutor());
                        System.out.println("Publicacion: " + libro.getPublicacion());
                        System.out.println("Precio: $" + libro.getPrecio());
                        System.out.println("----------------------------------------------");
                    } else {
                        System.out.println("No se encontro el libro.");
                    }
                    break;
                }
                case 13: {
                    System.out.println("Nombre del autor del libro (coincidencia exacta): ");
                    Libro libro = coleccion.buscarLibro_Autor(scan.nextLine());
                    if (libro.getAutor().compareTo("error") != 0) {
                        System.out.println("----------------------------------------------");
                        System.out.println("Titulo: " + libro.getNombre());
                        System.out.println("Autor: " + libro.getAutor());
                        System.out.println("Publicacion: " + libro.getPublicacion());
                        System.out.println("Precio: $" + libro.getPrecio());
                        System.out.println("----------------------------------------------");
                    } else {
                        System.out.println("No se encontro ningun libro de ese autor.");
                    }
                    break;
                }
                case 14: {
                    System.out.println("Nombre de libro a buscar (coincidencia exacta): ");
                    listaDinamica_Libro encontrados = coleccion.buscarLibros_Nombre(scan.nextLine());
                    if (encontrados.getElementos() > 0) {
                        // titulo 50 autor 30 fecha 10 precio 10
                        System.out.println("------- ------- ------- ------- -------");
                        System.out.print(String.format("%1$-50s", "Titulo"));
                        System.out.print(String.format("%1$-30s", "Autor"));
                        System.out.print(String.format("%1$-10s", "Fecha"));
                        System.out.println(String.format("%1$-10s", "Precio"));
                        for (int i = 0; i < encontrados.getElementos(); i++) {
                            Libro libro = encontrados.getLibro(i);
                            System.out.print(String.format("%1$-50s", libro.getNombre()));
                            System.out.print(String.format("%1$-30s", libro.getAutor()));
                            System.out.print(String.format("%1$-10s", libro.getPublicacion()));
                            System.out.println(String.format("%1$-10s", libro.getPrecio()));
                        }
                        System.out.println("------- Oprima ENTER para continuar -------");
                        scan.nextLine();
                    } else {
                        System.out.println("No se encontraron coincidencias con el libro.\n");
                    }
                    break;
                }
                case 15: {
                    System.out.println("Nombre del autor del libro a buscar (coincidencia exacta): ");
                    listaDinamica_Libro encontrados = coleccion.buscarLibros_Autor(scan.nextLine());
                    if (encontrados.getElementos() > 0) {
                        System.out.println("------- ------- ------- ------- -------");
                        System.out.print(String.format("%1$-50s", "Titulo"));
                        System.out.print(String.format("%1$-30s", "Autor"));
                        System.out.print(String.format("%1$-10s", "Fecha"));
                        System.out.println(String.format("%1$-10s", "Precio"));
                        for (int i = 0; i < encontrados.getElementos(); i++) {
                            Libro libro = encontrados.getLibro(i);
                            System.out.print(String.format("%1$-50s", libro.getNombre()));
                            System.out.print(String.format("%1$-30s", libro.getAutor()));
                            System.out.print(String.format("%1$-10s", libro.getPublicacion()));
                            System.out.println(String.format("%1$-10s", libro.getPrecio()));
                        }
                        System.out.println("------- Oprima ENTER para continuar -------");
                        scan.nextLine();
                    } else {
                        System.out.println("No se encontraron coincidencias con el autor.\n");
                    }
                    break;
                }
                case 16: {                    
                    try ( BufferedReader bfr = new BufferedReader(new FileReader("biblioteca.txt")) ){
                        for(int i=0; i<contador; i++){
                            String cadena1, cadena2, cadena3, cadena4;
                            cadena1= bfr.readLine();
                            cadena2= bfr.readLine();
                            cadena3= bfr.readLine();
                            cadena4= bfr.readLine();
                            Libro nuevo= new Libro();
                            if( !cadena1.isEmpty() ){
                                nuevo.setNombre(cadena1);
                                nuevo.setAutor(cadena2);
                                nuevo.setPublicacion(  Integer.parseInt(cadena3));
                                nuevo.setPrecio( Double.parseDouble(cadena4) );
                                coleccion.agregaFinal(nuevo);
                            }
                        }
                        System.out.println("Se recuperaron los registros almacenados en el archivo.");
                    }catch(Exception e){
                        e.printStackTrace();
                    }
                    break;
                }
                case 17: {
                    if(coleccion.getElementos() > 0){
                        try ( BufferedWriter archivo = new BufferedWriter(new FileWriter("biblioteca.txt")) ){
                            for(int i= 0; i<coleccion.getElementos(); i++){
                                Libro tmp_libro= coleccion.getLibro(i);
                                archivo.write( tmp_libro.getNombre() + "\n");
                                archivo.write( tmp_libro.getAutor() + "\n" );
                                archivo.write( tmp_libro.getPublicacion() + "\n" );
                                archivo.write( String.valueOf(tmp_libro.getPrecio()) + "\n" );
                            }
                            System.out.println("Se guardaron los registros en el archivo.");
                        }catch(Exception e){
                            e.printStackTrace();
                        }
                    }else{
                        System.out.print("No hay registros en la Lista Dinamica.");
                    }
                    break;
                }
                case 18:
                    System.out.println("Finalizando el programa!");
                    break;
                default:
                    System.out.println("Error en la opcion ingresada.");
            }
            // Ligero detenimiento
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } while (opcion != exit);
        scan.close();
    }
}
