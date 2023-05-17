package Clases;

//Importamos librerias
import java.util.Scanner; // para recibir inputs

import org.apache.commons.beanutils.converters.IntegerConverter;

import java.util.ArrayList; // para Arrays
import java.util.List; // para listas
import java.io.File;
import java.io.PrintWriter;
import java.io.FileNotFoundException;

//Importamos las clases
import Clases.Libros;
import Clases.LeerCSV;

public class Modificar {

  // VARIABLES
  List<Libros> ListaLibros;
  Scanner scan = new Scanner(System.in); // clase para recibir input
  // dejamos las cajas abiertas para almacenar
  private LeerCSV Lector;
  String input;
  String input_titulo;
  String input_autor;
  String input_anio;
  int LenList;
  private Boolean comparar;
  int encontrado;

  // Para Agregar Libro
  String titulo;
  String autor;
  String anio;
  String estante_numero;
  String estante_seccion;
  String piso;
  String edificio;
  String sede;

  // Para Menu Agregar

  // FUNCIONANDO
  public Modificar(LeerCSV lector_aux) {
    // ingresamos la lectura del csv en un metodo
    // ingresamos a Modificar un objeto de tipo lector, el cual lee el csv
    // en otras palabras importamos el csv a la clase modificar
    Lector = lector_aux;
    // de inmediato aprovechamos de obtener almacenar la lista de Leercsv en
    // ListaLibros
    ListaLibros = Lector.getlista();
    // Y su largo
    LenList = ListaLibros.size();
  }

  // Buscamos si el titulo existe
  // FUNCIONANDO
  public int ExisteLibro() {
    encontrado = 0;
    System.out.println("Ingrese el Titulo que desea buscar: ");
    input_titulo = scan.nextLine();
    System.out.println("Ingrese el Autor del libro: ");
    input_autor = scan.nextLine();
    System.out.println("Ingrese el Año del libro: ");
    input_anio = scan.nextLine();
    /*
     * Afables, no se asusten con el for de abajo, es un for simplificado que nos
     * han entregado los dioses -creadores de java- el cual me itera una variable
     * Indice de tipo Libros, el cual recorre ListaLibros.
     * Entonces, si al recorrer el indice, el titulo del "Indice" coincide con el
     * input_titulo asociado me retornara una variable encontrado.
     * Si encontrado != de -1 quiere decir que el libro que buscamos se encuentra en
     * la lista
     * Si encontrado == -1 quiere decir que se recorrio la lista completa y no se ha
     * encontrado el libro.
     * 
     * Si requieres mas informacion sobre este tipo de for para razas superiores
     * puedes encontrarlo en mi github >.0
     */
    for (Libros Indice : ListaLibros) {
      if (Indice.gettitulo().equals(input_titulo) && Indice.getautor().equals(input_autor) && Indice.getanio().equals(input_anio)) {
        encontrado = ListaLibros.indexOf(Indice);
      }
    }
    if (encontrado != 0) {
      return encontrado;
    } else {
      return -1;
    }
  }

  public int UltimoElemento() {
    return (ListaLibros.size() - 1);
  }

  // funcion InformacionLibro
  // FUNCIONANDO
  public void InformacionLibro(int encontrado) {
    // Mostramos la informacion del libro, la agregamos como funcion por temas de
    // practicidad.
    if (encontrado >= 0) {
      System.out.println("\n El resultado de tu accion se encuentra en la fila: " + encontrado + "\n");

      System.out.println(" Titulo: " + ListaLibros.get(encontrado).gettitulo() +
          "\n Autor: " + ListaLibros.get(encontrado).getautor() +
          "\n Año: " + ListaLibros.get(encontrado).getanio() +
          "\n Estante Numero: " + ListaLibros.get(encontrado).getestante_numero() +
          "\n Estante Seccion: " + ListaLibros.get(encontrado).getestante_seccion() +
          "\n Piso: " + ListaLibros.get(encontrado).getpiso() +
          "\n Edificio: " + ListaLibros.get(encontrado).getedificio() +
          "\n Sede: " + ListaLibros.get(encontrado).getsede() + "\n\n");
    } else {
      System.out.println("Lo sentimos, al parecer no tenemos su libro. Si gusta puede Intentarlo denuevo");
      // Corresponde a un Return, Aun no se hacia donde
    }
  }

  // Funcion Buscar Libro
  // FUNCIONANDO
  public void BuscarLibro() {
    encontrado = 0;
    encontrado = ExisteLibro();
    this.InformacionLibro(encontrado);
  }

  // Funcion agregar libro
  // FUNCIONANDO
  public void AgregarLibro() {
    /*
     * Agregar libro funciona de forma trivial, generamos un objeto -Libro Agregar-
     * de tipo Libros al cual le agregamos el titulo y sus variables
     * condesendientes, asi pues luego agregamos lo recolectado a Lista Libros
     * 
     * Como podemos saber que esta funcionando? Pues se le agrega uno mas al largo
     * de Lista.Libros
     * 
     */
    Libros Libro_Agregar = new Libros();
    System.out.println("Ingrese los campos del libro que desea agregar");
    System.out.println("Titulo: ");
    titulo = scan.nextLine();
    Libro_Agregar.settitulo(titulo);

    System.out.println("Autor: ");
    autor = scan.nextLine();
    Libro_Agregar.setautor(autor);

    System.out.println("Año:");
    anio = scan.nextLine();
    Libro_Agregar.setanio(anio);

    System.out.println("Estante Numero:");
    estante_numero = scan.nextLine();
    Libro_Agregar.setestante_numero(estante_numero);

    System.out.println("Estante Seccion: ");
    estante_seccion = scan.nextLine();
    Libro_Agregar.setestante_seccion(estante_seccion);

    System.out.println("Piso:");
    piso = scan.nextLine();
    Libro_Agregar.setpiso(piso);

    System.out.println("Edificio: ");
    edificio = scan.nextLine();
    Libro_Agregar.setedificio(edificio);

    System.out.println("Sede: ");
    sede = scan.nextLine();
    Libro_Agregar.setsede(sede);

    ListaLibros.add(Libro_Agregar);
    // FUNCIONANDO, Puedes comprobarlo con la siguiente linea
    // System.out.println(ListaLibros.size());
  }

  // Funcion quitar libro
  // FUNCIONANDO
  public void QuitarLibro() {
    System.out.println("Ingrese el Titulo del libro que desea quitar");
    encontrado = this.ExisteLibro();
    if(encontrado != 0){
      ListaLibros.remove(encontrado);
      //Fabuloso! Eliminamos el libro
    }
    else{
      System.out.println("No hemos encontrado tu libro, por favor Intentelo denuevo");
      
    }
}
  // Luego de aplicar cada metodo en el menu principal correponde un return el
  // cual es relativo
  public void MenuQuitar(){
    List<Libros> libro_lista_eliminar = new ArrayList<>();
    boolean repetir_quitar = true;
    String libro_quitar_titulo;
    String libro_quitar_autor;
    String libro_quitar_anio;
    String autor_quitar;
    String anio_quitar;
    String edificio_quitar;
    String estante_numero_quitar;
    String estante_seccion_quitar;
    String piso_quitar;
    String sede_quitar;
    int opcion_quitar =0;
    int contador_quitar;
    int contador_seccion_vacio = 0;
    int contador_piso_vacio = 0;
    int contador_sede_vacio = 0;
    int contador_unico;
  do{
    contador_unico = 0;
    contador_quitar = 0;
    System.out.println("\n\n\t\t\tMENU QUITAR\n");
    System.out.println("\t\t\t--------------\n");
    System.out.println("\n\t1. Libro\n");
    System.out.println("\t2. Sección\n");
    System.out.println("\t3. Piso\n");
    System.out.println("\t4. Sede\n");
    System.out.println("\t5. REGRESAR\n");
    //
    while(true){
      try {
        opcion_quitar = scan.nextInt();
        break;
      }
      catch(Exception e) {
        System.out.println("Por favor ingrese un numero entero, no otra cosa.");
      }
      scan.nextLine();
    }
    //
  
    switch (opcion_quitar){
        case 1:
          System.out.println("Nombre del libro que quiere quitar: ");
          libro_quitar_titulo = scan.nextLine();
          libro_quitar_titulo = scan.nextLine();
          System.out.println("Nombre del Autor del libro: ");
          libro_quitar_autor = scan.nextLine();
          System.out.println("Año del libro: ");
          libro_quitar_anio = scan.nextLine();
   
          

          for(Libros Indice : ListaLibros){
            if(Indice.gettitulo().equals(libro_quitar_titulo) && Indice.getautor().equals(libro_quitar_autor) && Indice.getanio().equals(libro_quitar_anio)){

              Indice.settitulo("$Vacio$");
              Indice.setautor("$Vacio$");
              Indice.setanio("$Vacio$");
              System.out.println("El libro se ha quitado ");
              contador_unico = 1;
              break;
              }
          }
          if(contador_unico == 0){
            System.out.println("No se encontro la combinacion que buscaste");
          }
          break;
          
        
        case 2:

          System.out.println("Qué sección quieres quitar ");
          estante_seccion_quitar = scan.nextLine();
          estante_seccion_quitar = scan.nextLine();
          
          System.out.println("De qué piso la quieres quitar: ");
          piso_quitar = scan.nextLine();
          
          System.out.println("De qué edificio la quieres quitar: ");
          edificio_quitar = scan.nextLine();
          
          System.out.println("De qué sede la quieres quitar: ");
          sede_quitar = scan.nextLine();

          contador_seccion_vacio = 0;
          for(Libros Indice : ListaLibros){
          
            if((!Indice.gettitulo().equals("$Vacio$")) &&
              Indice.getestante_seccion().equals(estante_seccion_quitar) &&
              Indice.getpiso().equals(piso_quitar) &&
              Indice.getedificio().equals(edificio_quitar) &&
              Indice.getsede().equals(sede_quitar)){

              System.out.println("La sección aún tiene libros");
              contador_seccion_vacio = 1;
              break;
              }
            
            }
          if(contador_seccion_vacio == 1){
            break;
          }
        
          for(Libros Indice : ListaLibros){
          
            if(Indice.gettitulo().equals("$Vacio$") &&
              Indice.getautor().equals("$Vacio$") &&
              Indice.getanio().equals("$Vacio$") &&
              Indice.getestante_seccion().equals(estante_seccion_quitar) &&
              Indice.getpiso().equals(piso_quitar) &&
              Indice.getedificio().equals(edificio_quitar) &&
              Indice.getsede().equals(sede_quitar)){
              if(contador_unico == 0){
                Indice.setestante_numero("$Vacio$");
                Indice.setestante_seccion("$Vacio$");
                System.out.println("Se eliminió la sección!");
                contador_unico = 1;
              }
              else{
                libro_lista_eliminar.add(Indice);
              }
                                          
            }
          }
          if(contador_unico == 0){
            System.out.println("No se encontro la combinacion que buscaste");
          }
          ListaLibros.removeAll(libro_lista_eliminar);
          break;
    
        case 3:
          
          System.out.println("Inserte el piso que quiere eliminar ");
          piso_quitar = scan.nextLine();
          piso_quitar = scan.nextLine();
          
          System.out.println("De qué edificio quiere eliminarlo: ");
          edificio_quitar = scan.nextLine();
          
          System.out.println("De qué sede quiere eliminarlo: ");
          sede_quitar = scan.nextLine();
          contador_piso_vacio = 0;
          for(Libros Indice : ListaLibros){
            
            if((!Indice.gettitulo().equals("$Vacio$")) &&
              Indice.getpiso().equals(piso_quitar) &&
              Indice.getedificio().equals(edificio_quitar) &&
              Indice.getsede().equals(sede_quitar)){

              contador_piso_vacio = 1;
              System.out.println("El piso aún tiene libros");
              break;
              }
            
            }
          if(contador_piso_vacio == 1){
            break;
          }
          for(Libros Indice : ListaLibros){
            if((Indice.getpiso().equals(piso_quitar)) &&
              (Indice.getedificio().equals(edificio_quitar)) &&
              (Indice.getsede().equals(sede_quitar))){
              if(contador_unico == 0){
                Indice.setpiso("$Vacio$");
                Indice.setestante_numero("$Vacio$");
                Indice.setestante_seccion("$Vacio$");
                System.out.println("Se eliminió el piso!");
                contador_unico = 1;
              }
              else{
                libro_lista_eliminar.add(Indice);
              }
            }
          }
          if(contador_unico == 0){
            System.out.println("No se encontro la combinacion que buscaste");
          }
          ListaLibros.removeAll(libro_lista_eliminar);
          break;
          
        case 4:  
          System.out.println("Que sede quiere quitar: ");
          sede_quitar = scan.nextLine();
          sede_quitar = scan.nextLine();
          contador_sede_vacio = 0;
          for(Libros Indice : ListaLibros){
            if(!Indice.gettitulo().equals("$Vacio$") && Indice.getsede().equals(sede_quitar)){
              contador_sede_vacio = 1;
              System.out.println("La sede aún tiene libros");
              break;
              }
            }
          
          if(contador_sede_vacio == 1){
            break;
          }
          for(Libros Indice : ListaLibros){
            if(Indice.getsede().equals(sede_quitar)){
              libro_lista_eliminar.add(Indice);
              contador_unico = 1;
            }
          }
          if(contador_unico == 0){
            System.out.println("No se encontro la combinacion que buscaste");
          }
          else{
            System.out.println("Eliminado!");
          }
          ListaLibros.removeAll(libro_lista_eliminar);
          break;
        

        case 5:
          scan.nextLine();
          repetir_quitar = false;
          break;

        default:
          System.out.println("Favor ingrese un valor.\n");
          break;  
      }    
          
   }while(repetir_quitar == true);
  } //Cierra Menu Quitar




  /*
   * 
   * La idea para Editar libro radica en usar el metodo
   * 
   * EditarLibro como un menu, el cual si se desea editar algun atributo del libro
   * solamente se mande a otro metodo, de los cuales estan hechos un poco más
   * abajo.
   * Estos metodos recibiran el indice encontrado, con el cual se podra acceder al
   * titulo y poder cambiar el atributo en si.
   * 
   */

   
    
  public int EditarLibro() {
    encontrado = ExisteLibro();
    if (encontrado == -1) {
      return encontrado;
    }
    InformacionLibro(encontrado);
    System.out.println("\n\n Ingrese el atributo del libro que desea cambiar: \n" +
        "\t\t\t--------------\n" +
        "\n\t1. Titulo\n" +
        "\t2. Autor\n" +
        "\t3. Año\n" +
        "\t4. Número del estante\n" +
        "\t5. Número del la sección\n" +
        "\t6. Piso\n" +
        "\t7. Edificio\n" +
        "\t8. Sede\n");
    return encontrado;
  }

  // FUNCIONANDO TODOS LOS EDITAR POR SEPARADO
  public void EditarTitulo(int encontrado) {
    System.out.println("El Titulo actual es: " +
        ListaLibros.get(encontrado).gettitulo() +
        "\n Ingrese el titulo por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).settitulo(input);
    System.out.println("El Titulo se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarAutor(int encontrado) {
    System.out.println("El Autor actual es: " +
        ListaLibros.get(encontrado).getautor() +
        "\n Ingrese el autor por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setautor(input);
    System.out.println("El Autor se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarAnio(int encontrado) {
    System.out.println("El Año actual es: " +
        ListaLibros.get(encontrado).getanio() +
        "\n Ingrese el anio por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setanio(input);
    System.out.println("El Año se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarEstante_numero(int encontrado) {
    System.out.println("El Estante Número actual es: " +
        ListaLibros.get(encontrado).getestante_numero() +
        "\n Ingrese el Estante numero por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setestante_numero(input);
    System.out.println("El Estante Número se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarEstante_seccion(int encontrado) {
    System.out.println("El Estante Seccion actual es: " +
        ListaLibros.get(encontrado).getestante_seccion() +
        "\n Ingrese el Estante Seccion por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setestante_seccion(input);
    System.out.println("El Estante Seccion se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarPiso(int encontrado) {
    System.out.println("El Piso actual es: " +
        ListaLibros.get(encontrado).getpiso() +
        "\n Ingrese el piso por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setpiso(input);
    System.out.println("El Piso se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarEdificio(int encontrado) {
    System.out.println("El Edificio actual es: " +
        ListaLibros.get(encontrado).getedificio() +
        "\n Ingrese el edificio por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setedificio(input);
    System.out.println("El Edificio se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  public void EditarSede(int encontrado) {
    System.out.println("La Sede actual es: " +
        ListaLibros.get(encontrado).getsede() +
        "\n Ingrese el sede por el cual desea reemplazar:");
    input = scan.nextLine();
    ListaLibros.get(encontrado).setsede(input);
    System.out.println("El Sede se ha cambiado con exito");
    InformacionLibro(encontrado);
    // Crear un return que diga "Volviendo al menu principal"

  }

  // AGREGAR
  public void MenuAgregar() {
    boolean repetir_agregar = true;
    String libro_agregar;
    String autor_agregar;
    String anio_agregar;
    String estante_numero_agregar;
    String estante_seccion_agregar;
    String piso_agregar;
    String edificio_agregar;
    String sede_agregar;
    int opcion_agregar = 0;
    int contador_agregar;
    int pos = 0;

    do {
      contador_agregar = 0;
      System.out.println("\n\n\t\t\tMENU AGREGAR\n");
      System.out.println("\t\t\t--------------\n");
      System.out.println("\n\t1. Libro\n");
      System.out.println("\t2. Sección\n");
      System.out.println("\t3. Piso\n");
      System.out.println("\t4. Sede\n");
      System.out.println("\t5. REGRESAR\n");
      //
      while(true){
        try {
          opcion_agregar = scan.nextInt();
          break;
        }
        catch(Exception e) {
          System.out.println("Por favor ingrese un numero entero, no otra cosa.");
        }
        scan.nextLine();
      }
      //
      switch (opcion_agregar) {
        case 1:
          System.out.println("Nombre del libro que quiere agregar: ");
          libro_agregar = scan.nextLine();
          libro_agregar = scan.nextLine();

          System.out.println("Nombre del autor del libro: ");
          autor_agregar = scan.nextLine();

          System.out.println("Año del libro: ");
          anio_agregar = scan.nextLine();

          System.out.println("En que estante lo quieres poner: ");
          estante_numero_agregar = scan.nextLine();

          System.out.println("En que sección lo quieres poner: ");
          estante_seccion_agregar = scan.nextLine();

          System.out.println("En que piso lo quieres poner: ");
          piso_agregar = scan.nextLine();

          System.out.println("En que edificio quieres ponerlo: ");
          edificio_agregar = scan.nextLine();

          System.out.println("¿En que sede?: ");
          sede_agregar = scan.nextLine();

          // -------

          /*
           * For Recorrer los libros
           * 
           * Comparar Año del libro con lo agregado
           * 
           * 
           */
          for (Libros Indice : ListaLibros) {
            if (Indice.gettitulo().equals("$Vacio$") &&
                (Indice.getautor().equals("$Vacio$") || Indice.getautor().equals(autor_agregar)) &&
                (Indice.getanio().equals("$Vacio$") || Indice.getanio().equals(anio_agregar)) &&
                (Indice.getestante_numero().equals("$Vacio$")
                    || Indice.getestante_numero().equals(estante_numero_agregar))
                &&
                (Indice.getestante_seccion().equals("$Vacio$")
                    || Indice.getestante_seccion().equals(estante_seccion_agregar))
                &&
                (Indice.getpiso().equals("$Vacio$") || Indice.getpiso().equals(piso_agregar)) &&
                (Indice.getedificio().equals("$Vacio$") || Indice.getedificio().equals(edificio_agregar)) &&
                (Indice.getsede().equals("$Vacio$") || Indice.getsede().equals(sede_agregar))) {

              Indice.settitulo(libro_agregar);
              Indice.setautor(autor_agregar);
              Indice.setanio(anio_agregar);
              Indice.setestante_numero(estante_numero_agregar);
              Indice.setestante_seccion(estante_seccion_agregar);
              Indice.setpiso(piso_agregar);
              Indice.setedificio(edificio_agregar);
              Indice.setsede(sede_agregar);
              pos = ListaLibros.indexOf(Indice);
              break;
            }
            contador_agregar++;
          }

          if (contador_agregar == ListaLibros.size()) {
            Libros Libro_Agregar = new Libros();
            Libro_Agregar.settitulo(libro_agregar);
            Libro_Agregar.setautor(autor_agregar);
            Libro_Agregar.setanio(anio_agregar);
            Libro_Agregar.setestante_numero(estante_numero_agregar);
            Libro_Agregar.setestante_seccion(estante_seccion_agregar);
            Libro_Agregar.setpiso(piso_agregar);
            Libro_Agregar.setedificio(edificio_agregar);
            Libro_Agregar.setsede(sede_agregar);
            ListaLibros.add(Libro_Agregar);
            pos = contador_agregar;
            break;
          }
          break;
        case 2:

          System.out.println("Que sección quieres agregar ");
          estante_seccion_agregar = scan.nextLine();
          estante_seccion_agregar = scan.nextLine();

          System.out.println("En que piso lo quieres poner: ");
          piso_agregar = scan.nextLine();

          System.out.println("En que edificio quieres agregarla: ");
          edificio_agregar = scan.nextLine();

          System.out.println("En que sede quieres agregarla: ");
          sede_agregar = scan.nextLine();

          for (Libros Indice : ListaLibros) {

            if ((Indice.getestante_seccion().equals("$Vacio$")) &&
                (Indice.getpiso().equals("$Vacio$") || Indice.getpiso().equals(piso_agregar)) &&
                (Indice.getedificio().equals("$Vacio$") || Indice.getedificio().equals(edificio_agregar)) &&
                (Indice.getsede().equals("$Vacio$") || Indice.getsede().equals(sede_agregar))) {

              Indice.settitulo("$Vacio$");
              Indice.setautor("$Vacio$");
              Indice.setanio("$Vacio$");
              Indice.setestante_numero("$Vacio$");
              Indice.setestante_seccion(estante_seccion_agregar);
              Indice.setpiso(piso_agregar);
              Indice.setedificio(edificio_agregar);
              Indice.setsede(sede_agregar);
              pos = ListaLibros.indexOf(Indice);
              break;
            }
            contador_agregar++;
          }

          if (contador_agregar == ListaLibros.size()) {
            Libros Libro_Agregar = new Libros();
            Libro_Agregar.settitulo("$Vacio$");
            Libro_Agregar.setautor("$Vacio$");
            Libro_Agregar.setanio("$Vacio$");
            Libro_Agregar.setestante_numero("$Vacio$");
            Libro_Agregar.setestante_seccion(estante_seccion_agregar);
            Libro_Agregar.setpiso(piso_agregar);
            Libro_Agregar.setedificio(edificio_agregar);
            Libro_Agregar.setsede(sede_agregar);
            ListaLibros.add(Libro_Agregar);
            pos = contador_agregar;
            break;
          }
          break;
        case 3:

          System.out.println("Inserte el piso que quiere agregar ");
          piso_agregar = scan.nextLine();
          piso_agregar = scan.nextLine();

          System.out.println("En que edificio quieres agregarlo: ");
          edificio_agregar = scan.nextLine();

          System.out.println("¿En que sede?: ");
          sede_agregar = scan.nextLine();

          for (Libros Indice : ListaLibros) {
            if ((Indice.getpiso().equals("$Vacio$")) &&
                (Indice.getedificio().equals("$Vacio$") || Indice.getedificio().equals(edificio_agregar)) &&
                (Indice.getsede().equals("$Vacio$") || Indice.getsede().equals(sede_agregar))) {

              Indice.settitulo("$Vacio$");
              Indice.setautor("$Vacio$");
              Indice.setanio("$Vacio$");
              Indice.setestante_numero("$Vacio$");
              Indice.setestante_seccion("$Vacio$");
              Indice.setpiso(piso_agregar);
              Indice.setedificio(edificio_agregar);
              Indice.setsede(sede_agregar);
              pos = ListaLibros.indexOf(Indice);
              break;
            }
            contador_agregar++;
          }

          if (contador_agregar == ListaLibros.size()) {
            Libros Libro_Agregar = new Libros();
            Libro_Agregar.settitulo("$Vacio$");
            Libro_Agregar.setautor("$Vacio$");
            Libro_Agregar.setanio("$Vacio$");
            Libro_Agregar.setestante_numero("$Vacio$");
            Libro_Agregar.setestante_seccion("$Vacio$");
            Libro_Agregar.setpiso(piso_agregar);
            Libro_Agregar.setedificio(edificio_agregar);
            Libro_Agregar.setsede(sede_agregar);
            ListaLibros.add(Libro_Agregar);
            pos = contador_agregar;
            break;
          }
          break;
        case 4:
          System.out.println("Que sede quiere agregar: ");
          sede_agregar = scan.nextLine();
          sede_agregar = scan.nextLine();

          Libros Libro_Agregar = new Libros();
          Libro_Agregar.settitulo("$Vacio$");
          Libro_Agregar.setautor("$Vacio$");
          Libro_Agregar.setanio("$Vacio$");
          Libro_Agregar.setestante_numero("$Vacio$");
          Libro_Agregar.setestante_seccion("$Vacio$");
          Libro_Agregar.setpiso("$Vacio$");
          Libro_Agregar.setedificio("$Vacio$");
          Libro_Agregar.setsede(sede_agregar);
          ListaLibros.add(Libro_Agregar);
          pos = ListaLibros.size() - 1;
          break;

        case 5:
          scan.nextLine();
          repetir_agregar = false;
          break;

        default:
          System.out.println("Favor ingrese un valor.\n");
          break;
      }
      if(repetir_agregar == true && opcion_agregar > 0 && opcion_agregar < 6){
        InformacionLibro(pos);
      }

    } while (repetir_agregar == true);

  }// Cierra Menu Agregar


  
  // RETORNAR LISTA
  public void guardarCSV() throws FileNotFoundException {
    File csvFile = new File("csv/inventario.csv");
    PrintWriter out = new PrintWriter(csvFile);
    for (Libros libro : ListaLibros) {
      out.printf("%s,%s,%s,%s,%s,%s,%s,%s\n", libro.gettitulo(), libro.getautor(),
          libro.getanio(), libro.getestante_numero(),
          libro.getestante_seccion(), libro.getpiso(), libro.getedificio(),
          libro.getsede());
    }
    out.close();
  }

} // Cierrra la Clase Modificar
