/* Podemos incluir operadores logicos 

¿A que responden los operadores logicos?

Sabemos que podemos concadenar tanto if como sean posibles, pero responder a demasiados if no es practico para nadie
asi pues:
podemos reemplazar tantos if con los operadores logicos.

*/

class operador{
    public static void main(String[] args){
        int edad = 5;//definimos un numero
        int dinero= 19;
        if(edad < 45  && dinero==19){ //creamos una condicion
            System.out.println("Hi"); //si la condicion se cumple entra e imprime 
        }
    }
}


/* Siguiendo con los operadores logicos, tenemos 

&& para AND
|| para OR

!(condicion ) para el NOT

*/