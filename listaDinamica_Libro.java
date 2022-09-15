public class listaDinamica_Libro {
    // ------- ------- ------- ------- ------- Atributos
    protected nodoLibro primero;
    protected nodoLibro ultimo;
    protected nodoLibro iterador;
    protected int elementos;

    // ------- ------- ------- ------- ------- Constructores
    public listaDinamica_Libro() {
        primero = new nodoLibro();
        ultimo = new nodoLibro();
        iterador = new nodoLibro();
        elementos = 0;
    }

    // ------- ------- ------- ------- ------- Módulos
    public int getElementos() {
        return this.elementos;
    }

    public boolean isEmpty() {
        return this.elementos == 0;
    }

    // agrega un libro (en un nodo) al inicio.
    public int agregaInicio(Libro nuevo) {
        nodoLibro nuevoLibro = new nodoLibro(nuevo);
        if (elementos > 0) {
            nuevoLibro.setEnlace(primero.getEnlace());
            primero.setEnlace(nuevoLibro);
        } else {
            primero.setEnlace(nuevoLibro);
            ultimo.setEnlace(nuevoLibro);
        }
        return elementos++;
    }

    // agrega un libro (en un nodo) al final.
    public int agregaFinal(Libro nuevo) {
        nodoLibro nuevoLibro = new nodoLibro(nuevo);
        if (elementos > 0) {
            ultimo.getEnlace().setEnlace(nuevoLibro);
            ultimo.setEnlace(nuevoLibro);
        } else {
            primero.setEnlace(nuevoLibro);
            ultimo.setEnlace(nuevoLibro);
        }
        return elementos++;
    }

    // elimina un libro al inicio.
    public Libro eliminaInicio() {
        nodoLibro extraido = new nodoLibro();
        if (elementos > 0) {
            iterador = primero.getEnlace();
            extraido = iterador;
            iterador = iterador.getEnlace();
            extraido.setEnlace(null);
            primero.setEnlace(iterador);
            elementos--;
        }
        return extraido.getElemento();
    }

    // elimina un libro al final.
    public Libro eliminaFinal() {
        nodoLibro extraido = new nodoLibro();
        if (elementos > 0) {
            iterador = primero.getEnlace();
            for (int i = 0; i < elementos - 2; i++) { // Al penúltimo nodo
                iterador = iterador.getEnlace();
            }
            extraido = iterador.getEnlace();
            iterador.setEnlace(null);
            ultimo.setEnlace(iterador);
            elementos--;
        } //
        return extraido.getElemento();
    }

    // dato de un nodo
    public Libro getLibro(int posicion) {
        Libro accedido = new Libro();
        if (posicion < elementos) {
            iterador = primero.getEnlace();
            for (int i = 0; i < posicion; i++) {
                iterador = iterador.getEnlace();
            }
            accedido = iterador.getElemento();
        }
        return accedido;
    }

    public String getDatosLibro(int posicion) {
        String contenido = "";
        if (posicion < elementos) {
            iterador = primero.getEnlace();
            for (int i = 0; i < posicion; i++) {
                iterador = iterador.getEnlace();
            }
            contenido = iterador.getElemento().getAutor() + "(" +
                    iterador.getElemento().getPublicacion() + "). " +
                    iterador.getElemento().getNombre() + ". $ " +
                    iterador.getElemento().getPrecio();
        }
        return contenido;
    }

}
