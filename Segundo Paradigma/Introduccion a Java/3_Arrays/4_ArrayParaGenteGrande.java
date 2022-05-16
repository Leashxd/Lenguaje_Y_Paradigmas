

/* 
Bueno, conociendo lo basico de los arrays podemos descrubir el agua tibia :)

Podemos calcular la suma de los elementos que contiene el array usando ciclos

Es trivial hacerlo, imagina que tenemos un Array con X longitud, unicamente la recorremos con un ciclo
for con cada valor i dentro del largo y vamos sumando 

Asi pues el codigo.

*/


class SumaElementosArray{
    public static void main(String[] args){
        int [] arr = { 6,42,3,7}; //Definimos el array con sus valores
        int sum= 0; //definimos una variable de suma para almacenar la suma del array

        //creamos el for
        for(int x=0; x<arr.length;x++){
            sum += arr[x];//Por cada iteracion se sumara un elemento del array
        }
        //una vez que se ha completado la suma se imprime el valor
        System.out.println(sum);
    }
}


/* Quick question, la posición del ultimo elemento del array es arr.lenght-1 dado que el array comienza
desde 0 hasa n por lo tanto el array tiene n+1 elementos  */