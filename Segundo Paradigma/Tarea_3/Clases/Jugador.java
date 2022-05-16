package Clases;
import java.util.Scanner; // para recibir inputs

public class Jugador {
  String nombre;
  String input;
  int NumeroUsuario;
  public static void main(String[] args) {
  }
  // creamos el objeto scanner para leer el input del teclado
  Scanner scan = new Scanner(System.in); 

  public void pedirNombre(){
    // Usuario ingresa nombre 
    System.out.println("Ingrese su nombre:");
    nombre = scan.nextLine();
  }

  
  public void PedirNumero(){
    //asumimos que es verdadero para inducir el ciclo
    while (true){
      // pedimos el numero
      System.out.println("Ingrese su Numero: ");
      input = scan.nextLine();
      // intentamos, saber si el Numero que ingresó el usuario esta entre 1 y 10
      try {
        NumeroUsuario = Integer.valueOf(input);
        if(NumeroUsuario>=1 & NumeroUsuario<=10){
          //si lo esta se rompe el ciclo y nos quedamos con el valor de numero usuario
          break;
        }else{
          // condiciones triviales al momento de no ingresar un input valido
          System.out.println("Favor ingrese un numero entre 1 y 10.");
          continue;
        }
      }
      catch(Exception e) {
        System.out.println("Favor ingrese un numero, no un texto.");
        continue;
      }
    }
  }
  
  /*Devolvemos el nombre*/
  public String getNombre(){
    return nombre;
  }
  // devolvemos el numero
  public int getNumero(){
    return NumeroUsuario;
  }
}
