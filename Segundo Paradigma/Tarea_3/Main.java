import Clases.Juego;
import Clases.Jugador;
import Clases.NumeroOculto;

/*
Integrantes:

Benjamin Lillo
Klaus Molt
Joaquin Leal
Camila Martinez
Javier Aguilera
*/

class Main {
  
  public static void main(String[] args) {

  //pedimos el nombre a traves de la clase usuario
  Jugador Usuario = new Jugador();
  Usuario.pedirNombre();
  System.out.println("Saludos " +Usuario.getNombre() + ", bienvenido a adivine el numero!");
  System.out.println("En este juego tendras que elegir un numero entre 1 y 10 y ver si adivinaste el numero elegido al azar por la maquina, tienes 3 intentos.");
  boolean continuar = true;
  while(continuar){
    NumeroOculto numero_oculto = new NumeroOculto();
    //Creamos un objeto de tipo juego al cual le entregamos dos parametros de tipo objeto, numero_oculto y Usuario
    Juego Comenzar = new Juego(numero_oculto,Usuario);
    continuar = Comenzar.Jugar();
    }
  }
}