/* 
Metodos y Return

Un metodo puede terminarse de varias formas ya sea imprimiendo un valor, colocando un break o 
devolviendo algun valor, para devolver los valores del metodo/funcion utilizaremos 
el mitico return

Este return puede devolver ya sea sumas o strings, todo depende de nuestra creatividad :)
Asi pues el codigo:
*/


class Myclass{
    //creamos nuestra funcion/metodo el cual lo definimos como una suma
    //esta necesita dos parametros para poder funcionar
    //y nos devuelve la suma entre val1 y val2
    static int sum(int val1, int val2){
        return val1+val2;
    }
    
    public static void main(String[] args){
        int x = sum(2,5); //el valor que se le asigna a x es lo que retorna la funcion sum
        System.out.println(x);
    }
}

/* Cuando no necesites devolver nada del metodo funcion, unicamente coloca void a la funcion 


Como hemos visto tenemos distintas formas de devolver un valor
Entonces

¿Qué es lo que se encuentra dentro del main?

Un array de llamado args de formato strings


*/


