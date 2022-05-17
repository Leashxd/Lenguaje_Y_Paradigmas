package Clases;

/*
  Clase Libros
*/
public class Libros {
    // Atributos
    private String titulo;           
    private String autor;
    private String anio;              
    private String estante_numero;
    private String estante_seccion;
    private String piso;
    private String edificio;         
    private String sede;     

    // Métodos getter y setter

    //Para titulo
    public String gettitulo() {
        return titulo;
    }
    public void settitulo(String titulo) {
        this.titulo = titulo;
    }
    //Para autor
    public String getautor() {
        return autor;
    }
    public void setautor(String autor) {
        this.autor = autor;
    }
    //para año
    public String getanio() {
        return anio;
    }
    public void setanio(String anio) {
        this.anio = anio;
    }
    //Para estante_numero
    public String getestante_numero() {
        return estante_numero;
    }
    public void setestante_numero(String estante_numero) {
        this.estante_numero = estante_numero;
    }
    //para Estante_seccion
    public String getestante_seccion() {
        return estante_seccion;
    }
    public void setestante_seccion(String estante_seccion) {
        this.estante_seccion = estante_seccion;
    }
    //Para piso
    public String getpiso() {
        return piso;
    }
    public void setpiso(String piso) {
        this.piso = piso;
    }
    //para edificio
    public String getedificio() {
        return edificio;
    }
    public void setedificio(String edificio) {
        this.edificio = edificio;
    }
    //para sede
    public String getsede() {
        return sede;
    }
    public void setsede(String sede) {
        this.sede = sede;
    }
    

}