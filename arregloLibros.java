import java.util.Scanner;

public class arregloLibros {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Primer archivo de libros");
        //
        int cantidad = 2;
        Libro[] arreglo = new Libro[cantidad];
        // ------ inicialización del arreglo
        for (int i = 0; i < cantidad; i++) {
            Libro ejemplar = new Libro();
            arreglo[i] = ejemplar;
        }
        // ------- Captura
        for (int i = 0; i < cantidad; i++) {
            System.out.print("Libro numero" + (i + 1) + "\n");
            System.out.println("Titulo del libro: ");
            arreglo[i].setNombre(scan.nextLine());

            System.out.print("Autor: ");
            arreglo[i].setAutor(scan.nextLine());

            System.out.print("Precio de compra: ");
            arreglo[i].setPrecio(scan.nextDouble());

            System.out.print("Año de publicacion: ");
            arreglo[i].setPublicacion(scan.nextInt());
            scan.nextLine();

            System.out.println("\n... .. . Libro capturado.\n");
        }

        // ------- Presentación
        System.out.println("Datos de los libros del arreglo.\n");
        for (int i = 0; i < cantidad; i++) {
            System.out.print(arreglo[i].getAutor() + " " +
                    "(" + arreglo[i].getPublicacion() + "). " +
                    arreglo[i].getNombre() + "\n\t$ " +
                    arreglo[i].getPrecio() + "\n");
        }
        //
        scan.close();
    }
}
