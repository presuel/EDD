import java.util.Scanner;
import java.util.LinkedList;

public class list_Libros {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        LinkedList<Libro> lista = new LinkedList();
        //
        String continuar;
        do {
            String eleccion;
            Libro libroNuevo = new Libro();
            // ------- ------- ------- Captura
            System.out.print("Titulo del libro: ");
            libroNuevo.setNombre(scan.nextLine());
            System.out.print("Autor: ");
            libroNuevo.setAutor(scan.nextLine());
            System.out.print("Precio de compra: ");
            libroNuevo.setPrecio(scan.nextDouble());
            System.out.print("Año de publicacion: ");
            libroNuevo.setPublicacion(scan.nextInt());
            scan.nextLine();
            // ------- ------- ------- Añade a la lista
            System.out.println("[i] Agregar al inicio. [f] Agregar la final | Eleccion: ");
            eleccion = scan.nextLine();
            if (eleccion.equals("i")) {
                lista.addFirst(libroNuevo);
            } else {
                lista.addLast(libroNuevo);
            }
            // ------- ------- ------- Control del bucle
            System.out.println("[s] Agregar otro elemento. [n] Finalizar.");
            continuar = scan.nextLine();
        } while (continuar.equals("s"));

        // ------- ------- ------- Presentando
        System.out.println("Extrayendo los elementos de la lista.\n");
        while (!lista.isEmpty()) {
            String eleccion;
            Libro iterador;
            // ------- ------- ------- Extrae de la lista
            System.out.println("[i] Extrae del inicio. [f] Extrae del final | Eleccion: ");
            eleccion = scan.nextLine();
            if (eleccion.equals("i")) {
                iterador = lista.removeFirst();
            } else {
                iterador = lista.removeLast();
            }
            System.out.println(iterador.getAutor() + "(" +
                    iterador.getPublicacion() + "). " +
                    iterador.getNombre() + "\n" +
                    iterador.getPrecio());
        }
        //
        scan.close();
    }

}
