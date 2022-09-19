import java.util.Scanner;

public class arbol_Libros {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Coleccion de Libros mediante Arbol binario.");
        ArbolBinario_Libro coleccion = new ArbolBinario_Libro();
        int respuesta;
        do {
            Libro libroNuevo = new Libro();
            // ------- ------- ------- Captura
            System.out.println("\nCapture los datos del libro.");
            System.out.println("Titulo del libro: ");
            libroNuevo.setNombre(scan.nextLine());
            System.out.println("Autor: ");
            libroNuevo.setAutor(scan.nextLine());
            System.out.println("Precio de compra: ");
            libroNuevo.setPrecio(scan.nextDouble());
            System.out.println("Fecha de publicacion: ");
            libroNuevo.setPublicacion(scan.nextInt());
            scan.nextLine();
            coleccion.agregar(libroNuevo);
            // ------- control de bucle
            System.out.println("[1] Capturar otro libro. [0] Finalizar.");
            respuesta = scan.nextInt();
            scan.nextLine();
        } while (respuesta != 0);
        // Presentación de datos capturados
        System.out.println("\n[PRE]_______P R E O R D E N_______[PRE]\n");
        coleccion.preorden();
        System.out.println("\n[IN]_______I N O R D E N_______[IN]\n");
        coleccion.inorden();
        System.out.println("\n[POST]_______P O S T O R D E N_______[POST]\n");
        coleccion.postorden();
        // Finalizando
        scan.close();
    }
}
