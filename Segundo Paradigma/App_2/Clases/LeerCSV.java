
//Empaquetamos la clase
package Clases;

//importamos librerias para leer un csv
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;


public class LeerCSV {
  //Definimos el separador
  public static final String separator = ",";
  List<Libros> listLibros;

  // Este metodo retorna una lista obtenida de la tabla en CSV
  private List<Libros> csvRead(){
    BufferedReader bufferReader = null;
    try {
      // Abrir el .csv en buffer de lectura
      bufferReader = new BufferedReader(new FileReader("csv/inventario.csv"));

      // Leer primera línea del archivo
      String line = bufferReader.readLine();
      listLibros = new ArrayList<Libros>();
  
      while (line != null) {
        // Sepapar la linea leída con el separador definido previamente
        String[] campos = line.split(separator);
                  
        Libros Libros = new Libros();
        Libros.settitulo(campos[0]);
        Libros.setautor(campos[1]);
        Libros.setanio(campos[2]);
        Libros.setestante_numero(campos[3]);
        Libros.setestante_seccion(campos[4]);
        Libros.setpiso(campos[5]);
        Libros.setedificio(campos[6]);
        Libros.setsede(campos[7]);
        listLibros.add(Libros);    
  
        // leer siguiente línea del fichero
        line = bufferReader.readLine(); 
      }
      return listLibros;
    } 
    catch (IOException e) {
      e.printStackTrace();
    } 
    finally {
      // Cierro el buffer de lectura
      if (bufferReader != null) {
        try {
          bufferReader.close();
        } 
        catch (IOException e) {
          e.printStackTrace();
        }
      }
    }
    return null;
  }

  // Método main (acá inicia la ejecución)
  public static void Leer(){
    // Creamos objeto app a partir de la clase Main
    LeerCSV app = new LeerCSV();

    // Activamos el método csvRead para cargar el archivo en un List
    List<Libros> Libross = app.csvRead();

    // Creamos un iterador para hacer el recorrido
    Iterator<Libros> fila = Libross.iterator();
    while(fila.hasNext()) {
      Libros Libros = fila.next();
      System.out.println("Titulo: "+Libros.gettitulo() +
      "\n Autor: " + Libros.getautor() +
      "\n Año: " + Libros.getanio() + 
      "\n Estante Numero: " + Libros.getestante_numero() + 
      "\n Estante Seccion: " + Libros.getestante_seccion() + 
      "\n Piso: " + Libros.getpiso() + 
      "\n Edificio: " + Libros.getedificio() +
      "\n Sede: " + Libros.getsede() + "\n\n");
    }
  }
}


