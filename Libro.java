public class Libro {
    // ------- ------- ------- ------- ------- Atributos
    private String nombre;
    private String autor;
    private int publicacion;
    private double precio;

    // ------- ------- ------- ------- ------- Constructor
    public Libro() {
        //
    }

    // ------- ------- ------- ------- ------- Setters and getters
    public String getNombre() {
        return this.nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getAutor() {
        return this.autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public int getPublicacion() {
        return this.publicacion;
    }

    public void setPublicacion(int publicacion) {
        this.publicacion = publicacion;
    }

    public double getPrecio() {
        return this.precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

}