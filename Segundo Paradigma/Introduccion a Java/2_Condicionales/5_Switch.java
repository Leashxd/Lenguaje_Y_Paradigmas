/* 



Imagina que deseamos cumplir una lista de cosas que queremos cumplir, bueno hasta ahora
podriamos usar perfectamente muchos if para cumplir las condiciones, sim embargo existe otra opcion que es 
un poco más eficiente respecto al entrar a las condiciones


Esta condicion es el SWITCH

Un switch esta compuesto por


switch(expresion){
    case value1:
        break // es opcional el break
    case value2:
        break // es opcional el break
    case value3:
        break // es opcional el break
    default: //opcional tambien
}   


Hay que considear un par de cosas para trabajar con switches dado que:

    *Cuando se entre a una condicion este trabajara igual que un if y se recorrera hasta que encuentre un break

    *Si se encuentra un break, el switch termina inmediatamente, no buscará más condiciones

    *No todos los casos deben contener un break, si no se encuentra un break se seguirá por mlos otros casos hasta
    encontrar uno, esto dependiendo de lo que desees hacer puede ser beneficioso o no


Ahora bien , en la practica:
*/


class operador{
    public static void main(String[] args){
        int dia = 3;
        switch(dia){
            case 1:
                System.out.println("Lunes");
                break;
            case 2:
                System.out.println("Martes");
                break;
            case 3:
                System.out.println("Miercoles");
                break;
            default: //Es es caso por defecto, lo cual puede indicarnos que el valor no es ninguno de los anteriores
                System.out.println("DiaSemana")
        }
    }
}