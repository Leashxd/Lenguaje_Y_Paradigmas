/* 
CICLO MEJORADO FOR
Java sigue sobrepasando los limites que podemos entender y su gente nos lleva años luz de ventaja

resulta que dentro de Java existe un ciclo con una particularidad, un ciclo mejorado.
El cual se le atribuye al for
Algunas veces se le llama "una función para cada elemento" la cual hace justamente lo que su nombre dice

Sus ventajas radican en que es menos probable que le ocurra un bug y es más intuitivo de leer

Asi pues el codigo:
*/

class LoopMejorado {
    public static void main(String[] args){
        int[] primos = {2,3,5,7,11}; //Creamos un array atribuido a los primos
        //ahora bien deseamos iterar el array, el cual perfectamente podriamos hacerlo con el codigo for que sabemos utilizar
        //Pero como somos gente de grado superior hacemos
        for(int t: primos){
            System.out.println(t);
        }

        /* WOOOOW ¿LO SIENTEN?
        Este es el poder del for mejorado, este automaticamente itera una variable t que recorre el array de "primos"
        Entonces el unico argumento que se necesita dentro del for para este caso es que se imprima la variable t
        */
    }
    
}
