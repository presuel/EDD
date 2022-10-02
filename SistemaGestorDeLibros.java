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
        listaDinamica_Libro coleccion = new listaDinamica_Libro();
        int opcion;
        int exit = 12;
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
            System.out.println("12 | Salir del programa.");
            System.out.println("------- ------- ------- ------- -------");
            System.out.print("Accion a realizar: ");
            opcion = scan.nextInt();
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
                case 12:
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
