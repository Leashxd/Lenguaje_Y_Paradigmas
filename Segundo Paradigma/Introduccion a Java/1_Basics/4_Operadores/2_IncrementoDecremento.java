/* Una funcion terriblemente util

Los decrementos o incrementos nos anuncian el aumento o disminucion de una variable 
asi pues

Como sabemos esto es trivial, creamos una clase */



//INCREMENTO
class Myclass{
    public static void main(String[ ] args){
        int test = 5;  //Definimos un numero
        ++test;        //Aumentamos el numero, es decir test ahora es igual a 5
        System.out.println(test); //print test con su valor
    }
}


//DECREMETNO
class Myclass{
    public static void main(String[ ] args){
        int test = 5;  //Definimos un numero
        --test;        //Disminuimos el numero, es decir test ahora es igual a 4
        System.out.println(test); //print test con su valor
    }
}



/* PREFIX Y POSTFIX

Existe una diferencia intrinseca entre colocar un ++x y un x++

Al primero se le otorga el nombre de prefix y este aumenta la variable y luego la asigna tal que:
*/
class Myclass{
    public static void main(String[ ] args){
        int test = 5;  //Definimos un numero
        int test_2 = ++test        //Aumentamos el numero y la asignamos a la variable, de ello test_2 tiene el valor de 6
        System.out.println(test_2); //print test con su valor

    }
}

/* POSTFIX

Es el inverso de PREFIX dado que primero asigna la variable1 a la variable2 y aumenta o decrece a la variable 1 
asi pues

*/
class Myclass{
    public static void main(String[ ] args){
        int test = 5;  //Definimos un numero
        int test_2 = test++      //El valor de test es 6 mientras que el valor de test_2 es 5
        System.out.println(test); //print test con su valor
    }
}