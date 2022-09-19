public class nodoArbolLibro {
    // ------- ------- ------- ------- ------- Atributos
    private Libro libro;
    private nodoArbolLibro izquierdo;
    private nodoArbolLibro derecho;

    // ------- ------- ------- ------- ------- Métodos
    public nodoArbolLibro() {
        this.libro = null;
        this.izquierdo = null;
        this.derecho = null;
    }

    public nodoArbolLibro(Libro libro) {
        this.libro = libro;
        this.izquierdo = null;
        this.derecho = null;
    }

    public void setDato(Libro libro) {
        this.libro = libro;
    }

    public Libro getDato() {
        return this.libro;
    }

    public void setHijoIzq(nodoArbolLibro izquierdo) {
        this.izquierdo = izquierdo;
    }

    public nodoArbolLibro getHijoIzq() {
        return this.izquierdo;
    }

    public void setHijoDer(nodoArbolLibro derecho) {
        this.derecho = derecho;
    }

    public nodoArbolLibro getHijoDer() {
        return this.derecho;
    }
}
