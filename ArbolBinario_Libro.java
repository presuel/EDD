public class ArbolBinario_Libro {
    // ------------------------------------------- Atributos
    protected nodoArbolLibro raiz;
    protected int elementos;

    // ------------------------------------------- Métodos
    public ArbolBinario_Libro() {
        this.raiz = null;
        elementos = 0;
    }

    public void agregarRaiz(Libro nuevo) {
        if (elementos == 0) {
            raiz = new nodoArbolLibro();
            this.raiz.setDato(nuevo);
            elementos++;
        }
    }

    public nodoArbolLibro getRaiz() {
        return this.raiz;
    }

    public void agregar(Libro libro) {
        if (elementos != 0) {
            nodoArbolLibro aux = raiz;
            boolean requiereUbicar = true;
            while (requiereUbicar) {
                // ------------------------------ - || CRITERIO => Nombre del libro
                String valorAux = aux.getDato().getNombre();
                String valorNodo = libro.getNombre();
                // 0 = equal, <0 = lower, >0 = greater
                if (valorNodo.compareTo(valorAux) < 0) {
                    if (aux.getHijoIzq() == null) {
                        nodoArbolLibro N = new nodoArbolLibro(libro);
                        aux.setHijoIzq(N);
                        requiereUbicar = false;
                    } else {
                        aux = aux.getHijoIzq();
                    }
                } else if (valorNodo.compareTo(valorAux) > 0) {
                    if (aux.getHijoDer() == null) {
                        nodoArbolLibro N = new nodoArbolLibro(libro);
                        aux.setHijoDer(N);
                        requiereUbicar = false;
                    } else {
                        aux = aux.getHijoDer();
                    }
                } else { // el libro ya existe
                    requiereUbicar = false;
                }
            }
            elementos++;
        } else {
            agregarRaiz(libro);
        }
    }

    public void eliminar(Libro libro) {
        //
    }

    public void preorden() {
        preorden(raiz);
    }

    public void inorden() {
        inorden(raiz);
    }

    public void postorden() {
        postorden(raiz);
    }

    private void fila(Libro libro) {
        System.out.println(libro.getAutor() + " (" +
                libro.getPublicacion() + "). " +
                libro.getNombre() + ". $ " +
                libro.getPrecio());
    }

    private void preorden(nodoArbolLibro iterador) {
        if (iterador != null) {
            Libro libro = iterador.getDato();
            fila(libro);
            preorden(iterador.getHijoIzq());
            preorden(iterador.getHijoDer());
        }
    }

    private void inorden(nodoArbolLibro iterador) {
        if (iterador != null) {
            Libro libro = iterador.getDato();
            inorden(iterador.getHijoIzq());
            fila(libro);
            inorden(iterador.getHijoDer());
        }
    }

    private void postorden(nodoArbolLibro iterador) {
        if (iterador != null) {
            Libro libro = iterador.getDato();
            postorden(iterador.getHijoIzq());
            postorden(iterador.getHijoDer());
            fila(libro);
        }
    }
}
