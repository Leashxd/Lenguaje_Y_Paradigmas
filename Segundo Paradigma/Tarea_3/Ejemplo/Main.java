import java.util.Random;   // Para números aleatorios
import java.util.Scanner;  // Para recibir datos desde teclado

class Main {
  static final int kIntentosMax = 3;
 
  public static void main(String[] args) {
    Random rnd = new Random();  // Inicia objeto random y planta semilla
    int iNumeroUsuario;
    int iNumeroOculto = rnd.nextInt(10) + 1;
    boolean bAdivinado = false;
    int iIntentos = 0;
    Scanner teclado = new Scanner(System.in);

    //System.out.println(iNumeroOculto);

    while (!bAdivinado && iIntentos < kIntentosMax){
      System.out.print("Ingrese un número entre 1 y 10 (quedan " + (kIntentosMax-iIntentos) + " intentos):");
      iNumeroUsuario = teclado.nextInt();
      if (iNumeroUsuario == iNumeroOculto)
        bAdivinado = true;
      iIntentos++;
    }
    if (bAdivinado){
      System.out.println("Wow...muy bien, deberías jugar más al loto !\n");
    }
    else {  
      System.out.println("No es tu día :( el número era el: " + iNumeroOculto);
    }
    teclado.close();
  }
}