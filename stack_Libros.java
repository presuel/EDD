import java.util.Scanner;
import java.util.Stack;

public class stack_Libros {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        // ------------------------------------------------
        Stack<Libro> pila = new Stack<>();
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
            // ------- ------- ------- Añade a la pila
            pila.push(libroNuevo);
            // ------- ------- ------- Control del bucle
            System.out.print("'s' agrega otro, 'n' finalizar. Opcion: ");
            continuar = scan.nextLine();
        } while (continuar.equals("s"));
        // ------- ------- ------- Presentando
        System.out.println("Extrayendo los elementos de la pila.\n");
        while (!pila.empty()) {
            Libro iterador = pila.pop();
            System.out.println(iterador.getAutor() + "(" +
                    iterador.getPublicacion() + "). " +
                    iterador.getNombre() + "\n" +
                    iterador.getPrecio());
        }
        // ------------------------------------------------
        scan.close();
    }
}
