#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BSIZE 1024
#define TRUE 1
#define FALSE 0

typedef struct columnas { //es necesario definir la longitud?
    char titulo[100];           //Asumimos que el titulo y el autor no pueden tener más de 100 caracteres :)
    char autor[100];
    char anio[100];               //el año no puede tener más de 4 números (char v int?)
    char estante_numero[100];
    char estante_seccion[100];
    char piso[100];
    char edificio[100];          //No tendrá más de 20 caracteres
    char sede[100];              //No tendrá más de 15 cáracteres

}dict;


void mostrar_valores(dict values[]){
    
    for(int i=0; i<1000; i=i+1){
        /* printf("titulo-> %s , autor-> %s , anio-> %s , estante_numero-> %s , estante_seccion-> %s , piso-> %s , edificio-> %s , sede-> %s ",values[i].titulo,values[i].autor,values[i].anio,values[i].estante_numero,values[i].estante_seccion,values[i].piso,values[i].edificio,values[i].sede); */
        printf(" Titulo: %s\n Autor: %s\n Anio: %s\n Estante Numero: %s\n Estante Seccion: %s\n Piso: %s\n Edificio: %s\n Sede:%s\n\n",
         values[i].titulo,
         values[i].autor,
         values[i].anio,
         values[i].estante_numero,
         values[i].estante_seccion, 
         values[i].piso,
         values[i].edificio,
         values[i].sede);
        
        

        
    }
}


void leer_csv(){
  /* DEFINIMOS VARIABLES PARA LEER EL CSV */
    int contador_filas = 0;
    int contador_celda = 0;
    char buffer[BSIZE];  //para leer el csv
    dict values[999];
    FILE *archivo = fopen("inventario_1.csv","r");  //puntero con la dirección del csv, con el caracter "r" -> read


    /* CONDICION EN CASO DE QUE NO PODAMOS LEER EL ARCHIVO */
    if (archivo == NULL){                       //condición en caso de que se presente algun problema al tratar de leer el archivo 
        perror("No es posible abrir el archivo, revise el formato y/o su directorio.");
        exit(1);
    }
    


    /* PROCESO PARA LEER EL CSV */
    
    int i = 0;  //variable que nos ayudará a recorrer las variables y colocarlas en el array.
    while(fgets(buffer, BSIZE , archivo)){

        
        contador_celda = 0;
        contador_filas ++;
        
        
        if (contador_filas == 1){               //el caso al leer la primera fila no nos interesa, dado que nos muestra el indice. asi pues solo lo saltamos
            continue;
        }

        char *celda = strtok(buffer, ",");      //leemos la cadena y separamos por excelencia ","


        while(celda){                          //creamos el otro while para el cual ira incluyendo cada elemento leido en el csv en el array


            if (contador_celda == 0){
                strcpy(values[i].titulo, celda);       //strcpy(valor1,valor2) reemplazamos/agregamos el valor1 por el valor2
            }
            if (contador_celda == 1){
                strcpy(values[i].autor, celda);       
            }
            if (contador_celda == 2){
                strcpy(values[i].anio, celda);       
            }
            if (contador_celda == 3){
                strcpy(values[i].estante_numero, celda);       
            }
            if (contador_celda == 4){
                strcpy(values[i].estante_seccion, celda);       
            }
            if (contador_celda == 5){
                strcpy(values[i].piso, celda);       
            }
            if (contador_celda == 6){
                strcpy(values[i].edificio, celda);       
            }
            if (contador_celda == 7){
                strcpy(values[i].sede, celda);       
            }

            celda= strtok(NULL, ","); 
            contador_celda++;
        }
        i++;

    }
    fclose(archivo); //cerramos el archivo ahora que tenemos todo el array

    mostrar_valores(values);

    /* for (int i=0; i<11;i++){
        printf()
    } */
    
    return ;        //el mítico return 0 :)
}


void buscar_libro(){


}


int main(){

    leer_csv();
    buscar_libro();
    return 0;

}