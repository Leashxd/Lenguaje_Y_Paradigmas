package Clases;

import java.util.ArrayList;
import java.util.Scanner;
//importamos las clases creadas
import Clases.Libros;
import Clases.LeerCSV;
import Clases.Modificar;
import java.io.FileNotFoundException;

public class menu_principal {
  public int repetir = 1;
  public int opcion;
  Scanner scan = new Scanner(System.in);
  // Creamos la caja para la var accion
  Modificar Accion;
  // ReturnMenu
  String ReturnMenu;

  public menu_principal(Modificar Accion_aux) {
    Accion = Accion_aux;

  }

  public void SetOpcion(int opcion_ingresada) { //
    while(true){
      try {
        opcion_ingresada = scan.nextInt();
        break;
      }
      catch(Exception e) {
        System.out.println("Por favor ingrese un numero entero, no otra cosa.");
      }
      scan.nextLine();
    }
    this.opcion = opcion_ingresada;
  }

  public void NoRepetir() {
    this.repetir = 0;
  }

  public void VolverAlMenuP() {
    System.out.println("Presione Enter para continuar:");
    // SON NECESARIOS LOS DOS INPUTS PARA QUE FUNCIONE
    // Esto es dado que el primero aun esta manteniendo el input ingresado
    // anteriormente en la consola
    // asi nos viene a salvar el segundo input para dar un sidestep
    ReturnMenu = scan.nextLine();
    ReturnMenu = scan.nextLine();
  }

  public void presentar_menu_p() {
    while (repetir == 1) {
      System.out.println("\n\n\t\t\tMENU PRINCIPAL\n");
      System.out.println("\t\t\t--------------\n");
      System.out.println("\n\t1. Buscar\n");
      System.out.println("\t2. Agregar\n");
      System.out.println("\t3. Quitar\n");
      System.out.println("\t4. Editar\n");
      System.out.println("\t5. SALIR\n");

      while(true){
        this.SetOpcion(opcion);
        if(opcion >= 1 && opcion <= 5){
          break;
        }
        else{
          System.out.println("Favor ingrese un valor entre 1 y 5");
        }
      }
      
      switch (opcion) {
        case 1:// Buscar Libro
          // FUNCIONANDO
          System.out.println("Buscar Libro");
          Accion.BuscarLibro();
          VolverAlMenuP();
          break;

        case 2:// Agregar Libro
          // FUNCIONANDO
          System.out.println("Agregar Libro");
          Accion.MenuAgregar();
          VolverAlMenuP();
          break;

        case 3:// Quitar Libro
          // FUNCIONANDO
          System.out.println("Quitar Libro");
          Accion.MenuQuitar();
          VolverAlMenuP();
          break;

        case 4:// Editar Libro
          // FUNCIONANDO, queda retocar cosas
          System.out.println("Editar Libro");
          int Eleccion = Accion.EditarLibro();
          if(Eleccion != -1){
            while(true){
              SetOpcion(opcion);
              if(opcion >= 1 && opcion <= 8){
                break;
              }
              else{
                System.out.println("Favor ingrese un valor entre 1 y 8");
              }
            }
          }
          else{
            System.out.println("No se encontro el libro que estabas buscando, favor ingrese bien el titulo, en caso de tener ',' en el nombre, poner el nombre entre comillas.");
            break;
          }
          
          switch (opcion) {
            case 1:// Titulo
              Accion.EditarTitulo(Eleccion);
              break;
            case 2:// Autor
              Accion.EditarAutor(Eleccion);
              break;
            case 3:// Año
              Accion.EditarAnio(Eleccion);
              break;
            case 4:// Estante numero
              Accion.EditarEstante_numero(Eleccion);
              break;
            case 5:// Esatnte seccion
              Accion.EditarEstante_seccion(Eleccion);
              break;
            case 6:// Piso
              Accion.EditarPiso(Eleccion);
              break;
            case 7:// Edificio
              Accion.EditarEdificio(Eleccion);
              break;
            case 8:// Sede
              Accion.EditarSede(Eleccion);
              break;

          }
          VolverAlMenuP();
          break;

        case 5:
          try {
            Accion.guardarCSV();
          } catch (FileNotFoundException e) {
            System.out.println("No fue posible guardar el csv.");
          }

          System.out.println("Guardado el csv.");
          NoRepetir();
          break;

        default:
          System.out.println("Favor ingrese un valor valido.\n");
          break;

      }

    }

  }

}