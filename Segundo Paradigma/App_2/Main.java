

import Clases.LeerCSV;
import Clases.Libros;

public class Main {
    public static void main(String[] args){
    
        //creamos los objetos para llamar a las funciones

        LeerCSV Lector = new LeerCSV();
        Libros Columna = new Libros();

        //Leemos el csv usando los objetos

        Lector.Leer();
    }
}
