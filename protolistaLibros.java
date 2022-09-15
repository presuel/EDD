import java.util.Scanner;

public class protolistaLibros {

    public static void imprimirLista(nodoLibro iterador) {
        if (iterador != null) {
            System.out.println(iterador.getElemento().getAutor() + "(" +
                    iterador.getElemento().getPublicacion() + "). " +
                    iterador.getElemento().getNombre() + "\n$ " +
                    iterador.getElemento().getPrecio());
            //
            imprimirLista(iterador.getEnlace());
        }
    }

    public static void imprimirListaInvertida(nodoLibro iterador) {
        if (iterador != null) {
            imprimirListaInvertida(iterador.getEnlace());
            //
            System.out.println(iterador.getElemento().getAutor() + "(" +
                    iterador.getElemento().getPublicacion() + "). " +
                    iterador.getElemento().getNombre() + "\n$ " +
                    iterador.getElemento().getPrecio());
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //
        nodoLibro primero = new nodoLibro();
        int continuar = 1;
        while (continuar != 0) {
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
            System.out.println("Finalizado la captura del libro...\n");
            // ------- ------- ------- Agregando a la lista
            nodoLibro nuevo = new nodoLibro(libroNuevo);
            nodoLibro iterador;
            iterador = primero;
            while (iterador.getEnlace() != null) {
                iterador = iterador.getEnlace();
            }
            iterador.setEnlace(nuevo);
            // ------- ------- ------- Control del bucle
            System.out.println("Para continuar oprima 1, para finalizar 0.");
            System.out.print("Respuesta: ");
            continuar = scan.nextInt();
            scan.nextLine();
        }
        // ------- Presentación
        System.out.println("\nLista de libros capturados.\n");
        nodoLibro iterador;
        iterador = primero.getEnlace();
        while (iterador != null) {
            System.out.println(iterador.getElemento().getAutor() + "(" +
                    iterador.getElemento().getPublicacion() + "). " +
                    iterador.getElemento().getNombre() + "\n" +
                    iterador.getElemento().getPrecio());
            iterador = iterador.getEnlace();
        }
        //
        System.out.println("\nLista de libros en orden de captura.\n");
        imprimirLista(primero.getEnlace());
        System.out.println("\nLista de libros en orden invertido.\n");
        imprimirListaInvertida(primero.getEnlace());
        //
        scan.close();
    }
}
