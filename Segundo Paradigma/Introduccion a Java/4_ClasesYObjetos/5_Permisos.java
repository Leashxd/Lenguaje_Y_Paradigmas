/* Mira, los permisos son esenciales para que no te echen de la pega,asi que mejor aprenderlos ahora que
dps

Tenemos los miticos permisos, que como su plabara indica, les dan permisos a nuestras variables

Estos podemos utilizarlos en clases,atributos y metodos/funciones



Para las clases los permisos que puedes atribuirles son

public -> la clase puede ser accedida desde otra clase
default -> la clase es solo accedida desde el mismo package


Para los atributos y metodos,


default -> la clase o atributo será accedida desde cualquier otra cclase en el mismo package

public -> Puede ser accedida desde cualquier otra clase

protected  -> Solo las subclases y super clases pueden acceder a estos atributos

private -> Accesible solo con la clase que ha sido declarada



*/

public class vehiculo{
    private int Velocidad_maxima;
    private int Ruedas;
    private String Color;
    private double Capacidad_estanque;

    void horn(){
        System.out.println("BEEP!");
    }
}
