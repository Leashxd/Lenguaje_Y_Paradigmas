/* 
Metodos

Los metodos definen el comportamiento de la clase.
Un metodo es una agrupacion de declaraciones las cuales realizan una operación.

Por ejemplo System.out.println() es un metodo, o en otras palabras más coloquiales podemos denominarlo función

Asi pues el codigo

*/
class Metodo{
    //creamos una función / metodo
    static void Hola(){
        System.out.println("Hola Mundo!");
    }
    //creamos nuestor main
    public static void main(String[] args){
        Hola();      //llamamos a la funcion metodo
    }
}
/* En terminos de practicidad, esto es lo que conocemos como una función. Sin embargo se le llama metodo. 

Como dato, puedo llamar al comportamiento de la clase las veces que sean necesarias.
*/
class Metodo2{
    //creamos una función / metodo
    static void Hola(){
        System.out.println("Hola Mundo!");
    }
    //creamos nuestor main
    public static void main(String[] args){
        Hola();
        Hola();
        Hola();
        Hola();
        Hola();
        Hola();
        Hola();
              //llamamos a la funcion metodo
    }
}
/* 
eventualmente podemos utilizar este comportamiento/funciones para crear funciones recursivas las cuales tiene el mismo proposito que los ciclos

METODOS Y PARAMETROS 

Los metodos que creamos tambien pueden contener datos dentro, a estos datos se les llaman parametros. Estos se colocan dentro de los parentesis
de la funcion/metodo llamado, lo cual nos permite modificar el resultado de el metodo en cuestion

Asi pues en el ejemplo, tomamos un metodo al cual estamos pidiendo un string como parametro
*/


class Metodo3{
    //creamos una función / metodo
    //Dentro de esta otorgamos las instrucciones de como queremos que se trabaje el parametro dentro de la funcion hola
    //en este caso queremos trabajar con un string que reciba el nombre de "nombre"
    static void Hola(String nombre){    
        System.out.println("Hola "+ nombre);
    }
    //creamos nuestor main
    public static void main(String[] args){
        Hola("David");
        Hola("Jose");
              //llamamos a la funcion metodo
    }
}

/*
 La utilidad de este metodo radica en que podemos reuzar el codigo de una forma más eficiente y no es necesario estar pegando
y copiando a cada rato el choclo de enigmas que desarrollamos

Además si hemos de crear la función en base a parametros no necesitamos cambiar variables ya que nuestro metodo se modificará
en calidad de las variables entregadas.
*/


