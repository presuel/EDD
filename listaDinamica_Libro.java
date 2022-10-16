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
        if (elementos > 1) {
            nodoLibro extraido = new nodoLibro();
            iterador = primero.getEnlace();
            for (int i = 0; i < elementos - 2; i++) { // Al penúltimo nodo
                iterador = iterador.getEnlace();
            }
            extraido = iterador.getEnlace();
            iterador.setEnlace(null);
            ultimo.setEnlace(iterador);
            elementos--;
            return extraido.getElemento();
        } else if (elementos == 1) {
            nodoLibro extraido = primero.getEnlace();
            primero.setEnlace(null); // desconexión
            ultimo.setEnlace(null);
            elementos--;
            return extraido.getElemento();
        } else {
            return ultimo.getElemento();
        }
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

    // public void ordenarTitulo() { // ITERATIVO, INTERCAMBIANDO VALORES
    // if (this.getElementos() > 1) {
    // nodoLibro itemA = primero.getEnlace();
    // for (int i = 0; i < this.getElementos() - 1; i++) {
    // nodoLibro itemB = itemA.getEnlace();
    // for (int j = i + 1; j < this.getElementos(); j++) {
    // // Nombre
    // if
    // ((itemA.getElemento().getNombre()).compareTo(itemB.getElemento().getNombre())
    // > 0) {
    // nodoLibro itemX = new nodoLibro();
    // itemX.setElemento(itemB.getElemento());
    // itemB.setElemento(itemA.getElemento());
    // itemA.setElemento(itemX.getElemento());
    // }
    // itemB = itemB.getEnlace();
    // }
    // itemA = itemA.getEnlace();
    // }
    // }
    // }

    // public void ordenarAutor() { // ITERATIVO, INTERCAMBIANDO VALORES
    // if (this.getElementos() > 1) {
    // nodoLibro itemA = primero.getEnlace();
    // for (int i = 0; i < this.getElementos() - 1; i++) {
    // nodoLibro itemB = itemA.getEnlace();
    // for (int j = i + 1; j < this.getElementos(); j++) {
    // // Autor
    // if
    // ((itemA.getElemento().getAutor()).compareTo(itemB.getElemento().getAutor()) >
    // 0) {
    // nodoLibro itemX = new nodoLibro();
    // itemX.setElemento(itemB.getElemento());
    // itemB.setElemento(itemA.getElemento());
    // itemA.setElemento(itemX.getElemento());
    // }
    // itemB = itemB.getEnlace();
    // }
    // itemA = itemA.getEnlace();
    // }
    // }
    // }

    // public void ordenarPrecioAsc() { // ITERATIVO, INTERCAMBIANDO VALORES
    // if (this.getElementos() > 1) {
    // nodoLibro itemA = primero.getEnlace();
    // for (int i = 0; i < this.getElementos() - 1; i++) {
    // nodoLibro itemB = itemA.getEnlace();
    // for (int j = i + 1; j < this.getElementos(); j++) {
    // // Precio Ascencente
    // if (itemA.getElemento().getPrecio() > itemB.getElemento().getPrecio()) {
    // nodoLibro itemX = new nodoLibro();
    // itemX.setElemento(itemB.getElemento());
    // itemB.setElemento(itemA.getElemento());
    // itemA.setElemento(itemX.getElemento());
    // }
    // itemB = itemB.getEnlace();
    // }
    // itemA = itemA.getEnlace();
    // }
    // }
    // }

    // public void ordenarPrecioDes() { // ITERATIVO, INTERCAMBIANDO VALORES
    // if (this.getElementos() > 1) {
    // nodoLibro itemA = primero.getEnlace();
    // for (int i = 0; i < this.getElementos() - 1; i++) {
    // nodoLibro itemB = itemA.getEnlace();
    // for (int j = i + 1; j < this.getElementos(); j++) {
    // // Precio Descencente
    // if (itemA.getElemento().getPrecio() < itemB.getElemento().getPrecio()) {
    // nodoLibro itemX = new nodoLibro();
    // itemX.setElemento(itemB.getElemento());
    // itemB.setElemento(itemA.getElemento());
    // itemA.setElemento(itemX.getElemento());
    // }
    // itemB = itemB.getEnlace();
    // }
    // itemA = itemA.getEnlace();
    // }
    // }
    // }

    public void ordenarTitulo() { // RECURSIVO, MANIPULANDO APUNTADORES
        QuickTitulo(primero, ultimo);
    }

    public void ordenarAutor() { // RECURSIVO, MANIPULANDO APUNTADORES
        QuickAutor(primero, ultimo);
    }

    public void ordenarPrecioAsc() { // RECURSIVO, MANIPULANDO APUNTADORES
        QuickPrecioAsc(primero, ultimo);
    }

    public void ordenarPrecioDes() { // RECURSIVO, MANIPULANDO APUNTADORES
        QuickPrecioDes(primero, ultimo);
    }

    private void QuickTitulo(nodoLibro inicial, nodoLibro elfinal) {
        // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
        iterador = inicial.getEnlace();
        nodoLibro pivote = elfinal.getEnlace();
        if (iterador != pivote) {
            int menores = 0, mayores = 0;
            nodoLibro D_i = new nodoLibro();
            nodoLibro D_f = new nodoLibro();
            nodoLibro I_i = new nodoLibro();
            nodoLibro I_f = new nodoLibro();
            while (iterador != pivote) {
                if ((iterador.getElemento().getNombre()).compareTo(pivote.getElemento().getNombre()) > 0) {
                    if (mayores > 0) {
                        I_f.getEnlace().setEnlace(iterador);
                    } else {
                        I_i.setEnlace(iterador);
                    }
                    I_f.setEnlace(iterador);
                    mayores++;
                } else {
                    if (menores > 0) {
                        D_f.getEnlace().setEnlace(iterador);
                    } else {
                        D_i.setEnlace(iterador);
                    }
                    D_f.setEnlace(iterador);
                    menores++;
                }
                iterador = iterador.getEnlace();
            }
            // Llamada recursiva para ordenamiento de los segmentos
            if (menores > 1)
                QuickTitulo(D_i, D_f);
            if (mayores > 1)
                QuickTitulo(I_i, I_f);
            // Reunión de segmentos
            if (menores > 0 && mayores > 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            } else if (menores > 0 && mayores == 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                elfinal.setEnlace(pivote);
            } else if (menores == 0 && mayores > 0) {
                inicial.setEnlace(pivote);
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            }
        }
    }

    private void QuickAutor(nodoLibro inicial, nodoLibro elfinal) {
        // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
        iterador = inicial.getEnlace();
        nodoLibro pivote = elfinal.getEnlace();
        if (iterador != pivote) {
            int menores = 0, mayores = 0;
            nodoLibro D_i = new nodoLibro();
            nodoLibro D_f = new nodoLibro();
            nodoLibro I_i = new nodoLibro();
            nodoLibro I_f = new nodoLibro();
            while (iterador != pivote) {
                if ((iterador.getElemento().getAutor()).compareTo(pivote.getElemento().getAutor()) > 0) {
                    if (mayores++ > 0) {
                        I_f.getEnlace().setEnlace(iterador);
                    } else {
                        I_i.setEnlace(iterador);
                    }
                    I_f.setEnlace(iterador);
                } else {
                    if (menores++ > 0) {
                        D_f.getEnlace().setEnlace(iterador);
                    } else {
                        D_i.setEnlace(iterador);
                    }
                    D_f.setEnlace(iterador);
                }
                iterador = iterador.getEnlace();
            }
            // Llamada recursiva para ordenamiento
            if (menores > 1)
                QuickAutor(D_i, D_f);
            if (mayores > 1)
                QuickAutor(I_i, I_f);
            // Reunión de segmentos
            if (menores > 0 && mayores > 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            } else if (menores > 0 && mayores == 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                elfinal.setEnlace(pivote);
            } else if (menores == 0 && mayores > 0) {
                inicial.setEnlace(pivote);
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            }
        }
    }

    private void QuickPrecioAsc(nodoLibro inicial, nodoLibro elfinal) {
        // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
        iterador = inicial.getEnlace();
        nodoLibro pivote = elfinal.getEnlace();
        if (iterador != pivote) {
            int menores = 0, mayores = 0;
            nodoLibro D_i = new nodoLibro();
            nodoLibro D_f = new nodoLibro();
            nodoLibro I_i = new nodoLibro();
            nodoLibro I_f = new nodoLibro();
            while (iterador != pivote) {
                if (iterador.getElemento().getPrecio() > pivote.getElemento().getPrecio()) {
                    if (mayores++ > 0) {
                        I_f.getEnlace().setEnlace(iterador);
                    } else {
                        I_i.setEnlace(iterador);
                    }
                    I_f.setEnlace(iterador);
                } else {
                    if (menores++ > 0) {
                        D_f.getEnlace().setEnlace(iterador);
                    } else {
                        D_i.setEnlace(iterador);
                    }
                    D_f.setEnlace(iterador);
                }
                iterador = iterador.getEnlace();
            }
            // Llamada recursiva para ordenamiento
            if (menores > 1)
                QuickAutor(D_i, D_f);
            if (mayores > 1)
                QuickAutor(I_i, I_f);
            // Reunión de segmentos
            if (menores > 0 && mayores > 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            } else if (menores > 0 && mayores == 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                elfinal.setEnlace(pivote);
            } else if (menores == 0 && mayores > 0) {
                inicial.setEnlace(pivote);
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            }
        }
    }

    private void QuickPrecioDes(nodoLibro inicial, nodoLibro elfinal) {
        // AAPR 2022 - Ordenamiento mediante manipulación de apuntadores y recursión.
        iterador = inicial.getEnlace();
        nodoLibro pivote = elfinal.getEnlace();
        if (iterador != pivote) {
            int menores = 0, mayores = 0;
            nodoLibro D_i = new nodoLibro();
            nodoLibro D_f = new nodoLibro();
            nodoLibro I_i = new nodoLibro();
            nodoLibro I_f = new nodoLibro();
            while (iterador != pivote) {
                if (iterador.getElemento().getPrecio() < pivote.getElemento().getPrecio()) {
                    if (mayores++ > 0) {
                        I_f.getEnlace().setEnlace(iterador);
                    } else {
                        I_i.setEnlace(iterador);
                    }
                    I_f.setEnlace(iterador);
                } else {
                    if (menores++ > 0) {
                        D_f.getEnlace().setEnlace(iterador);
                    } else {
                        D_i.setEnlace(iterador);
                    }
                    D_f.setEnlace(iterador);
                }
                iterador = iterador.getEnlace();
            }
            // Llamada recursiva para ordenamiento
            if (menores > 1)
                QuickAutor(D_i, D_f);
            if (mayores > 1)
                QuickAutor(I_i, I_f);
            // Reunión de segmentos
            if (menores > 0 && mayores > 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            } else if (menores > 0 && mayores == 0) {
                D_f.getEnlace().setEnlace(pivote);
                inicial.setEnlace(D_i.getEnlace());
                elfinal.setEnlace(pivote);
            } else if (menores == 0 && mayores > 0) {
                inicial.setEnlace(pivote);
                pivote.setEnlace(I_i.getEnlace());
                elfinal.setEnlace(I_f.getEnlace());
            }
        }
    }

    public Libro buscarLibro_Nombre(String buscado) {
        Libro libro = new Libro();
        libro.setNombre("error");
        iterador = primero.getEnlace();
        while (iterador != null) {
            if ((iterador.getElemento().getNombre()).compareTo(buscado) == 0) {
                libro = iterador.getElemento();
                return libro;
            }
            iterador = iterador.getEnlace();
        }
        return libro;
    }

    public Libro buscarLibro_Autor(String buscado) {
        Libro libro = new Libro();
        libro.setAutor("error");
        iterador = primero.getEnlace();
        while (iterador != null) {
            if ((iterador.getElemento().getAutor()).compareTo(buscado) == 0) {
                libro = iterador.getElemento();
                return libro;
            }
            iterador = iterador.getEnlace();
        }
        return libro;
    }

    listaDinamica_Libro buscarLibros_Nombre(String buscado) {
        listaDinamica_Libro encontrados = new listaDinamica_Libro();
        iterador = primero.getEnlace();
        while (iterador != null) {
            if ((iterador.getElemento().getNombre()).compareTo(buscado) == 0) {
                encontrados.agregaFinal(iterador.getElemento());
            }
            iterador = iterador.getEnlace();
        }
        return encontrados;
    }

    listaDinamica_Libro buscarLibros_Autor(String buscado) {
        listaDinamica_Libro encontrados = new listaDinamica_Libro();
        iterador = primero.getEnlace();
        while (iterador != null) {
            if ((iterador.getElemento().getAutor()).compareTo(buscado) == 0) {
                encontrados.agregaFinal(iterador.getElemento());
            }
            iterador = iterador.getEnlace();
        }
        return encontrados;
    }

}
