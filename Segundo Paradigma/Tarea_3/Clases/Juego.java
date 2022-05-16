//Empaquetamos la clase "Juego" en "Clases"
package Clases;

//Importamos las otras clases dentro de esta para usarlas
import Clases.Jugador;
import Clases.NumeroOculto;
import java.util.Scanner; // para recibir inputs

public class Juego {
  Scanner scan = new Scanner(System.in); 
  //Dejamos las cajas abiertas para almacenar
  NumeroOculto numero_oculto;
  Jugador Usuario;
  int Num_Usuario;
  int numero_oc;
  static final int MaxIntentos =3;

  //La clase juego necesita los dos parametros para inicarse
  public Juego(NumeroOculto numero_oculto_aux, Jugador Usuario_aux) {
    // definimos las variables que vamos a usar que nos entregamos en el main
    numero_oculto = numero_oculto_aux;
    Usuario = Usuario_aux;

    
  }
  // Creamos el metodo 'comparar' donde comparamos los numeros -generado aleatoriamente y el dado por el usuario-
  public static boolean comparar(int Num_Usuario,int numero_oc, int intentos){
    //Comprobamos si el numero ingresado del usuario es igual al random generado
    if (Num_Usuario != numero_oc){ 
      System.out.println("Lo sentimos no has adivinado el numero, te quedan "+ (2-intentos)+" intentos.");
      //generamos pistas
      if(Num_Usuario > numero_oc & intentos < MaxIntentos-1){
        System.out.println("Pista, el numero secreto es menor.");
        }
      else if(Num_Usuario < numero_oc & intentos < MaxIntentos-1){
        System.out.println("Pista, el numero secreto es mayor.");
        }
      return false;
      }
    else{
      //indicamos que el numero se ha encontrado
      System.out.println("Felicitaciones! Adivinaste el numero");
      return true;
      } 
 }

  public boolean Jugar(){
    // generamos las cajas para las variables
    boolean acerto = false, continuar;
    int intentos = 0;
    //Pedimos el int para jugar
    //Jugamos un poco con los booleanos, generamos un while TRUE para entrar a la condicion
    // si existe aciertos e intentos es menor al maximos de intentos, entramos
    while(!acerto & intentos<MaxIntentos){
      Usuario.PedirNumero();       
      //comparamos para saber si este acertó
      acerto = comparar(Usuario.getNumero(),numero_oculto.getNumeroOculto(), intentos);
      // si no lo hizo, simplemente agregamos un numero de intento más
      intentos++;
    }

    //Condicion para saber si deseamos seguir jugando
    while(true){
      //obtenemos el texto de respuesta
      System.out.println("¿Deseas seguir jugando? [S/N]");
      String input_continuar = scan.nextLine();
      // Para 'S' y 's'
      if(input_continuar.equals("S") | input_continuar.equals("s")){
        continuar = true;
        System.out.println("Iniciando nuevo juego, se ha cambiado el numero aleatorio.");
        break;
      }
      //Para 'N' y 'n'
      else if(input_continuar.equals("N") | input_continuar.equals("n")){
        continuar = false;
        break;
      }
      //verificamos que se ingrese lo que pedimos
      else{
        System.out.println("Favor ingresa una S o N, no otra cosa.");
      }
    }
    return continuar;
  }
}