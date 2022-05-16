/* 
*Inserte Speech Profe*
Sabemos que esta puede ser la parte latera, pero pongamosle weno





UN array en una coleccion de variables del mismo tipo

Cuando necesitas almacenar una lista de valores, ya sea del tipo numero o string, tu puedes hacerlo en un arrray
en vez de declarar cada variable por separado

¿SIentes el poder del array?


En java para declarar un array necesitas colocar el tipo de variable e insertar corchetes
y definir el nombre.

Además hemos de definirle su largo

Luego escribiremos una variable del array con algun valor


Asi pues en codigo:
*/


class myArray{
    public static void main(String[] args){
        int[] arr;  //definimos el array, entonces tenemos un array con el nombre arr del tipo int

        int[] arr = new int[5]; //Definimos el largo del array mediante la funcion new y el int encerrado en corchetes
        //lo que nos permite tener un array de 5 elementos

        arr[2] = 42; //reescribimos la posicion 3 con el numero 42

    }
}