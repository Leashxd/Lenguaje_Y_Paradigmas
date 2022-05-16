package Clases;
import java.util.Random; //para numeros Aleatorios

public class NumeroOculto{
  Random rnd= new Random(); //Iniciamos un objeto Random
  int iNumeroOculto = rnd.nextInt(10)+1; // generamos el numero aleatorio
  
  //llamamos la numero  oculto
  public int getNumeroOculto(){
    return iNumeroOculto;
  }
}