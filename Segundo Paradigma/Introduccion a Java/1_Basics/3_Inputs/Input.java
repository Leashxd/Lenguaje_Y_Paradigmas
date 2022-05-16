/* 

Mira, la cosa aqui es simple, como en todo lenguaje existen MIL MANERAS de hacer lo mismo

en java una manera comun de pedir un input es con el OBJETO Scanner

el cual hemos de importar para poder utilizarlo de la forma

*/

import java.util.Scanner;

/* Para utilizar la clase hemos de crear una clase con una funcion con sus atributos
como ya hemos practicado en los modulos anteriores
*/
class Myclass{
    public static void main(String[ ] args){
        Scanner myvar= new Scanner(System.in);  //creamos variable a la cual se le atribuye el objeto scanner
        System.out.println(myvar.nextLine());
    }


}

/* 
No hemos de olvidar que Existen mil funciones para obtener inputs y todas estas funcionan exactamente de la misma manera

podemos

Leer un byte -> nextByte()
Leer un short -> nextShort()
Leer un int -> nextInt()
Leer un long -> nextLong()
Leer un float -> nextFloat()
Leer un double -> nextDouble()
Leer un boolean -> nextBoolean()
Leer un linea completa ->nextLine()
Leer un una palabra ->next()

*/