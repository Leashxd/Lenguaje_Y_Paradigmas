/* 
Lo esperado por todos, llego el momento de los ARRAYS MULTIDIMENSIONALES


Un array multidimensional es un array que contiene otros arrays, 
un array multidimensional de dos variables es basicamente una matriz

Para crear arrays multidimensionales nos basta con "corchetear el numero de dimensiones"
y colocar sus respectivos vectores asociados como variables


Asi pues el codigo:
*/


class ArrayMultidimensional{
    public static void main(String[] args){
        int[][] matriz={{1,2,3},{4,5,6}};  //Creamos el array matriz de 2x2 
        // crearemos una variable de placeholder para llamar al primer elemento de la segunda fila
        int x = matriz[1][0];
        //imprimimos
        System.out.println(x);
    }
}


/* Para efectos prácticos este array multidimencional es una matriz de 2x2, quiere decir
    que los valores de matriz[][] el primer corchete corresponde a las filas y el segundo a las columnas
*/



/* Cabe decir que los array multidimensionales no son exclusivos de dos variables,
Java permite obtener Arrays multidimensionales de las dimensiones que uno necesite.
¿Deben estar los todos los elementos?
No es necesario, podemos establecer el siguiente arreglo


*/

class arrayMultidimensional_2{
    public static void main(String[] args){
        int[][] matriz2={{1,2,3},{4},{5,6,7}};
        int x = matriz2[1][0];
        System.out.println(x);  //Se imprime la fila 2 en la posicion 0 es decir se devuelve el 4

    }
}