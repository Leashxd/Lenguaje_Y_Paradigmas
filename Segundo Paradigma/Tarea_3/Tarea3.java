/* 
Autor: Joaquin Leal
Lenguaje y Paradigmas 
*/

//Importamos librerias
import java.util.Scanner;  // Para recibir datos desde teclado

//importamos las clases que estan en archivos distintos

import Clase.NumeroOculto;

class Main{
    public static void main(String[] args){
        
        NumeroOculto Oculto = new NumeroOculto();

        System.out.println(Oculto.getiNumeroOculto());

    }
}