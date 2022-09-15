import java.util.Scanner;
import java.util.LinkedList; // A falta de un queue

public class queue_Libros {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //
        LinkedList<Libro> cola = new LinkedList();
        String continuar;
        do {
            Libro libroNuevo = new Libro();
            // ------- ------- ------- Captura
            System.out.println("Título del libro: ");
            libroNuevo.setNombre(scan.nextLine());
            System.out.println("Autor: ");
            libroNuevo.setAutor(scan.nextLine());
            System.out.println("Precio de compra: ");
            libroNuevo.setPrecio(scan.nextDouble());
            System.out.println("Año de publicación: ");
            libroNuevo.setPublicacion(scan.nextInt());
            scan.nextLine();
            // ------- ------- ------- Añade a la cola
            cola.addLast(libroNuevo);
            // ------- ------- ------- Control del bucle
            System.out.print("[s] Agregar otro [n] Finalizar: ");
            continuar = scan.nextLine();
        } while (continuar.equals("s"));
        // ------- ------- ------- Presentando
        System.out.println("Extrayendo los elementos de la cola.\n");
        while (!cola.isEmpty()) {
            Libro iterador = cola.removeFirst();
            System.out.println(iterador.getAutor() + "(" +
                    iterador.getPublicacion() + "). " +
                    iterador.getNombre() + "\n" +
                    iterador.getPrecio());
        }
        //
        scan.close();
    }
}
