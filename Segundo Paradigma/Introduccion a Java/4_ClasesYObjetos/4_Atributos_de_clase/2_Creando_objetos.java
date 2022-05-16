/* Ya que no estamos en la prehistoria podemos crear varios objetos dentro de una clase




POr ejemplo, tenemos la clase vehiculo
*/

public class vehiculo{
    int Velocidad_maxima;
    int Ruedas;
    String Color;
    double Capacidad_estanque;
    



    void horn(){
        System.out.println("BEEP!");
    }
}



class Myclass {
    public static void main(String[] args){
        /* Clase + Variable = nueva clase  Ergo es un nuevo objeto */

        Vehiculo Ford = new Vehiculo(); /* Tenemos un nuevo objeto llamado FORD de la clase vehiculo */
        Vehiculo Kia= new Vehiculo();   /* Tenemos un nuevo objeto llamado KIA de la clase vehiculi */

        /* Podemos definir los atributos que tienen los objetos en su clase */   

        Ford.Color ="Rojo";
        Kia.Ruedas=16;

        Kia.bocina();

    }
}