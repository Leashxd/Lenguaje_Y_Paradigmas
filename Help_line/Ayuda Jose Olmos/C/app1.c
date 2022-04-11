#include <stdio.h>
#include <stdlib.h>
#include <string.h> // concadenar cadenas, para leer el csv

#define buffersize 1024 // Variable auxiliar, para almacenar los datos del csv y poder usarlos

void mostrar_csv(){
    char titulo[100];
    char autor[100];
    char anio[100];
    char estante_numero[100];
    char estante_seccion[100];
    char piso[100];    
    char edificio[100];
    char sede[100];
    


    int contador_celdas = 0;
    int contador_filas = 0;
    char buffer[buffersize];
    FILE *libros =fopen("inventario_1.csv","r"); //r-> read

    if (libros == NULL){ // en caso de que no se pueda abrir la abrir
        printf("No es posible abrir el archivo, revisa nuevamente el directorio.");

        exit(1); //programa temrino de forma anormal
                    // exit (0) el programa temrino con exito
    }

    int contador=0;
    while (fgets(buffer, buffersize, libros)){ //fgets(donde se cguarda, que tamñano tiene , de donde saca la info) ESTE WHILE LEE LA FILA DEL CSV
        contador_celdas = 0;
        contador_filas++;
        char *celda;
        

        if (contador_filas == 1){ 
            continue;
        }

        celda =strtok(buffer,","); // strtok va a romper la cadena 


        while (celda){
            if (contador_celdas == 1){
                printf("%s", celda);
            }
            contador_celdas++;
            celda = strtok(NULL, ",");
        }
    } 

}


int main(){
    mostrar_csv();
    return 0;
}