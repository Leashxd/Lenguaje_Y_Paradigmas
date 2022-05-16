/* Operadores de asignacion

De toda la vida que sabemos que podemos otorgar valores a las variables con un '='

Pero aqui java sube un poco el nivel y nos permite jugar con los asignadores colocandole operadores
para disminuir nuestro trabajo  -java +1 /  C te caes a pedazos-


*/
class Myclass{
    public static void main(String[ ] args){
        int num1 = 5;  //Definimos un numero
        int num2 = 6;       //Aumentamos el numero, es decir test ahora es igual a 5
        num2 += num1;       // es lo mismo que decir  num2= num2 + num1
        System.out.println(num2); //print test con su valor 11
    }
}
/* Ergo, lo mismo ocurre para el resto de operadores,


+= para la suma
-= para la resta
*= para la multiplicacion
/= para la division 


*/