/* 

Este es un paso un poco más interesante,

Switch puede trabajarse de una forma aun más eficiente permitiendo guardar una decision a multiples variables

Asi pues ya en codigo

*/

class SwitchExpression{
    public static void main(String[] args){
        int dia=2;
        String Tipo_de_dia = switch(dia){  //definimos una variable del tripo string que tiene el valor dependiene de switch
            case 1,2,3,4,5 -> "Dia habil"; //para los dias de semana, es decir los casos 1,2,3,4,5 es un dia habil
            case 6,7 -> "Fin de semana";
            default -> "Dia invalido";
            //Es estrictamente necesario utilizar este tipo de flecha para referirse a los valores que va a utilizar
        };
    }
}

