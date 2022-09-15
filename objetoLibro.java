public class objetoLibro {

    public static void main(String[] args) {

        System.out.println("Primer archivo de libros");
        Libro ejemplar1 = new Libro();
        ejemplar1.setAutor("Jose Luis Joyanes");
        ejemplar1.setNombre("Programación en C, C++, Java y UML");
        ejemplar1.setPrecio(570);
        ejemplar1.setPublicacion(2012);
        // ---
        System.out.println("Libro recopilado: " +
                ejemplar1.getNombre() + "\n" +
                ejemplar1.getAutor() + "\n" +
                ejemplar1.getPublicacion() + "\n" +
                "$ " + ejemplar1.getPrecio() + "\n");

    }

}
