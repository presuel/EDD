public class nodoLibro { // [ ELEMENTO | *ENLACE ]
    private Libro elemento;
    private nodoLibro enlace;

    public nodoLibro() {
        this.elemento = null;
        this.enlace = null;
    }

    public nodoLibro(Libro elemento) {
        this.elemento = elemento;
        this.enlace = null;
    }

    public nodoLibro(Libro elemento, nodoLibro enlace) {
        this.elemento = elemento;
        this.enlace = enlace;
    }

    public void setElemento(Libro elemento) {
        this.elemento = elemento;
    }

    public Libro getElemento() {
        return elemento;
    }

    public nodoLibro getEnlace() {
        return enlace;
    }

    public void setEnlace(nodoLibro enlace) {
        this.enlace = enlace;
    }

}
