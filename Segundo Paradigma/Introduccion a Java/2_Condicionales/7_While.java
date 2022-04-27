/* 

Como los ciclos de toda la vida, tenemos el mitico While
Un ciclo, una condicion que se repite y repite hasta el infinito si la tratamos mal

Asi que debemos trabajarla con cariño para que no se taime.


Asi pues en codigo
*/


class Ciclo_While{
    public static void main(String[ ] args){
        int x = 3;
        while (x>0){
            System.out.println(x);
            x--;
            /* Imprime
            3
            2
            1
            0 
            Termina el ciclo
            */
        }

        //Cuando el ciclo termina, lo demostramos
        System.out.println("El ciclo ha terminado");
    }
}