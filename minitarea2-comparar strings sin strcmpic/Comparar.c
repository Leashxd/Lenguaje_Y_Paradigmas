

/* 
Hecho por Joaquin Leal >.0
 */


#include <stdio.h>



char string1[30];       //Asumimos el largo 30, realmente no creo que exista una palabra más larga que eso.
char string2[30];





int comparar(char *palabra1, char *palabra2){

    int alerta=0, i=0;                  //contaremos con una alerta, en el caso de que se active querrá decir que los strings no son iguales
    //Como ya tenemos almacenadas las variables podemos trabajarlas como listas y concadenarlas generando condiciones
    //asi pues trabajaremos con un while, que recorrerá los strings comparando

    while (*palabra1!='\0' && *palabra2!='\0'){
        
        /*  Explciación de las condiciones del while

            ¿Que diablos acaba de suceder aqui? Como todos sabemos C es terriblemente mañoso
            de ello tiene una forma bastante particular de concadenar los elementos de sus listas
            dado que; Supongamos que tenemos una array que contempla

            array[] = "Comida";
            
            ¿Como sabe C que la cadena array ha terminado? C tiene variables de control para notificar los terminos debajo de la mesa
            asi pues \0 notifica el término de la cadena comida almacenandose de la manera

            {'c','o,''m','i','d','a','\0'}

            Entonces, basicamente estamos diciendo en este while es: mientras ninguno de los valores que estan almacenados en los punteros haya terminado
            usted sigale pa' delante.
         */

        if( *palabra1 != *palabra2){    //si los strings son distintos
            alerta=1; 
            break;
        }                               //como la lista debe seguir, aumentamos :)
        palabra1++;
        palabra2++;

        
    }
    
    if(alerta==0){
            return 0;
        }
}











int main(){
    // Como nuestro objetivo es comparar dos strings, lo primero que debemos hacer
    // es crear las variables Strings que me permitiran almacenar los dos input que deseo ingresar
    
    //Debemos de rellenar de alguna manera las variables que acabamos de crear.
    printf("Ingresa tu primera palabra:");
    scanf("%s",&string1);                        //Utilizamos el scanf para crear un input que me permita almacenar en string1
    printf("Ingresa tu segunda palabra:");
    scanf("%s",&string2);                        //La gracia de crear la variable con "&" Radica en que estamos rellenando la variable como si fuera un puntero.
    
    printf("\nTu primera palabra es: %s\n", string1);
    printf("Tu segunda palabra es: %s\n\n", string2);

    int comp = comparar(string1,string2);        //simplemente estamos almacenando el valor del resultado de nuestra funcion para poder dar un ultimatum al asunto
    
    if (comp == 0){
        printf("Tus palabras son iguales!", string1, string2);
    }
    else{
        printf("Tus palabras son distintas! \n %s Es distinto a %s", string1, string2);
    }

    return 0;
}