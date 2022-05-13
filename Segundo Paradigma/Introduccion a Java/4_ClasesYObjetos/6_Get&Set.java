/* Los creadores de java son realmente unos seres de luz, los cuales piensan en todo

Exist un metodo bastante arcaico para proteger tus archivos en las clases 

Para obtener un atributo utilizaremos el get+variable


es decir

*/
public class vehiculo{
    private String color;
}
/* Para obtener el color */
public String getColor(){
    return color;
}
/*  Para colocar un color */
public  void setColor(String c){
    objeto.color = c;
}



/* Un get devuelve el valor del atributo
un Set toma un atributo para asignarle un valor o reescribirlo



Estos metodos se utilizan basicamente para obtener o escribir tus atributos sin tocar la variable, lo cual las protege

Asi simplemente solo llamamos a  nuestro main aplicamos lo que creamos


*/


public static void main(String[] args){
    Vehiculo Ford = new Vehiculo();
    Ford.setColor("Red");
    System.out.println(Ford.getColor());
}


/* Esto no es más que una buenisima practica ! */