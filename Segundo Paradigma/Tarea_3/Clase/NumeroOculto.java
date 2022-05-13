package Clase;

import java.util.Random;   // Para números aleatorios



//Creamos la clase numero oculto
public class NumeroOculto{
    Random rnd = new Random(); //Creamos el objeto random
    int iNumeroOculto = rnd.nextInt(10)+1;


    public int getiNumeroOculto(){
        return iNumeroOculto;
    }
}