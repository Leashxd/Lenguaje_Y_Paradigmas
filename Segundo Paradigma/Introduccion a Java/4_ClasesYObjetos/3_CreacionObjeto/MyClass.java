/* 
CREACION DE OBJETOS

Creemos nuestro primer objeto

*/
//Primero Crearemos una clase
//en estricto rigor esta clase deberia ir en otro archivo pero por temas practicos lo recreamos en el mismo.

//llamamos al otro archivo .java el cual contiene nuestros atributo
import Clase.Animal;

class MyClass{
    //entonces creamos nuestro mitico main 
    public static void main(String[] args){
        // Tenemos la variable perro a la cual le estamos asignando la clase animal, lo cual genera que este sea un objeto
        Animal perro = new Animal();
        //entonces tenemos el objeto perro al cual le estamos dando un comportamiento, un metodo el cual es ladrar
        perro.ladrar();

    }
}