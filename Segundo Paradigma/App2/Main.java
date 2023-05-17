// Integrantes:
// Joaquin Leal
// Klaus Molt
// Javier Aguilera
// Camila Martinez
// Benjamin Lillo

import Clases.LeerCSV;
import Clases.Libros;
import Clases.Modificar;
import Clases.menu_principal;

public class Main {
    public static void main(String[] args){
      //Creamos el objeto lector para leer el csv
      LeerCSV Lector = new LeerCSV();      
      //Le otorgamos Lector al objeto accion para que pueda trabajar con todos sus atributos
      Modificar Accion = new Modificar(Lector);
      //Y de igual manera, delegamos accion a Menu para poder utilizarlas con el menú
      menu_principal Menu = new menu_principal(Accion);
      
      Menu.presentar_menu_p();
      System.out.println("FIN");
    }
}
