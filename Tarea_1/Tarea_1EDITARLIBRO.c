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

void mostrar_valores(dict values[], int len){

    for(int i=0; i<len-1; i=i+1){
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

int buscar_libro(dict values[], int len){
    //CREAR UN MATCH ENTRE EN EL ARREGLO
    //Primero realizaremos un buscar por TITULO
    char input_titulo[100];
    char *auxiliar;
    int ch[100];
    fflush(stdout);
    printf("Ingrese el titulo del libro que desea buscar:\n");

    
    fgets(input_titulo,100,stdin);                       //Usamos Fgets para obtener toda la frase y no unicamente la primera palabra
    input_titulo[strlen(input_titulo)-1]='\0';          /* 
                                                        fgets tiene una forma partituclar de expresar las cadenas, al obtener una este la almacena siempre terminandola
                                                        en un \n es decir, con un salto de linea que si nosotros almacenamos la cadena "hola" C la leera como:

                                                        {"h","o","l","a","\n"}

                                                        Sin embargo, las cadenas que almacenamos por el csv estan almacenadas con el termino'\0' la cual expresa un termino de cadena
                                                        de ello hemos de cambiar el final de fgets con:

                                                        input_titulo[strlen(input_titulo)-1]='\0';
                                        
                                                        */


    
    //Comprobando como funciona el strcmp(), veamos si funciona con listas 

      /* 
      BUSCAR LIBRO MEDIANTE TITULO

      creamos un for con el largo de nustro array, y nuestro objetivo es comparar nuestro input con cada valor
      i del titulo que ya ha sido almacenado. de ello crearemos una variable auxiliar que almacene el titulo
      temporal con el cual queremos comparar
      lo que logramos hacer es comparar el titulo[i] con el input y cuando este se encuentre el match pasar al 
      if demostrar que hemos encontrado el libro

      EXISTE UN PROBLEMA!
        unicamente podemos hacer match con el primer libro que encontremos
        Si aun no me hago entender es que no podemos demostrar que se han encontrado dos libros iguales /ediiones distintas

             :))
        
    
    
     */

    //EN ESTRICTO RIGOR ESTO DEBERIA ESTAR DENTRO DE UN WHILE HASTA QUE EL USUARIO QUIERA SALIR DEL LOOP
    //CONDICIÓN A AGREGAR.
    for(int i=0; i<len-1; i=i+1){
        auxiliar = values[i].titulo;
        if ((strcmp( auxiliar, input_titulo)==0)){
            printf("\nHEMOS ENCONTRADO TU LIBRO!\n");
            printf("\nTitulo: %s\n Autor: %s\n Anio: %s\n Estante Numero: %s\n Estante Seccion: %s\n Piso: %s\n Edificio: %s\n Sede:%s\n\n",
            values[i].titulo,
            values[i].autor,
            values[i].anio,
            values[i].estante_numero,
            values[i].estante_seccion, 
            values[i].piso,
            values[i].edificio,
            values[i].sede);
            return i;
            
            
        }
    }
    if((strcmp(auxiliar, input_titulo ))!=0){
            printf("Lo sentimos, tu libro no es parte de nuestro repositorio");
            printf("\nauxiliar= %s\n   \ninput_titulo: %s",auxiliar,input_titulo);
            return -1;

            
        }
    
}

int leer_csv(dict values[]){
  /* DEFINIMOS VARIABLES PARA LEER EL CSV */
    int contador_filas = 0;
    int contador_celda = 0;
    char buffer[BSIZE];  //para leer el csv
    FILE *archivo = fopen("inventario_1.csv","r");  //puntero con la dirección del csv, con el caracter "r" -> read

    /* CONDICION EN CASO DE QUE NO PODAMOS LEER EL ARCHIVO */
    if (archivo == NULL){                       //condición en caso de que se presente algun problema al tratar de leer el archivo 
        perror("No es posible abrir el archivo, revise el formato y/o su directorio.");
        exit(1);
    }

    /* PROCESO PARA LEER EL CSV */
    
    int i = 0;  //variable que nos ayudará a recorrer las filas y colocarlas en el array. Comenzamos en 1 para saltarnos indice de csv.
    while(fgets(buffer, BSIZE , archivo)){
        contador_filas++;
        if(i == 0){
            i++;
            continue;} //se salta el primer fgets
        
        contador_celda = 0;
        int comillas = 0;
        for (int j = 0; j < strlen(buffer); j++) //Se quitan las , que no sean separadores reales
        {
            if (buffer[j] == '"' && comillas == 0){
                comillas = 1;
                continue;
            }
            if (buffer[j] == '"' && comillas == 1){
                comillas = 0;
                continue;
            }
            if (buffer[j] == ',' && comillas == 0){
                buffer[j] = '~';
            }
        }
        char *celda = strtok(buffer, "~");      //leemos la cadena y separamos por excelencia ","

        for(contador_celda = 0; contador_celda < 8; contador_celda++){ //creamos el otro while para el cual ira incluyendo cada elemento leido en el csv en el array
                                                                        /* 
                                                                        Definamos un concepto, llamaremos celda a cada atributo encerrados por "," de aquel modo, -> ,titulo, es una celda.

                                                                        De ello, el primer while itera entre las filas del dataframe, leyendo mediante la funcion fgets y el buffer
                                                                        Sin embargo, esto nos permite unicamente leer el csv entero y no clasificarlo. Con ello hemos de crear otro while 
                                                                        que se expresa mediante la definición de "celda". Entonces, como sabemos que existen 8 campos por los cuales nos interesa
                                                                                                                                                                        
                                                                        */
            if (contador_celda == 0){
                strcpy(values[i-1].titulo, celda);       //strcpy(valor1,valor2) reemplazamos/agregamos el valor1 por el valor2
            }
            if (contador_celda == 1){
                strcpy(values[i-1].autor, celda);       
            }
            if (contador_celda == 2){
                strcpy(values[i-1].anio, celda);       
            }
            if (contador_celda == 3){
                strcpy(values[i-1].estante_numero, celda);       
            }
            if (contador_celda == 4){
                strcpy(values[i-1].estante_seccion, celda);       
            }
            if (contador_celda == 5){
                strcpy(values[i-1].piso, celda);       
            }
            if (contador_celda == 6){
                strcpy(values[i-1].edificio, celda);       
            }
            if (contador_celda == 7){
                strcpy(values[i-1].sede, celda);       
            }
            celda = strtok(NULL, "~");
        }
        i++;
    }
    fclose(archivo); //cerramos el archivo ahora que tenemos todo el array

    return(contador_filas);       
}

void editar_libro(dict values[], int len){
    
    //para editar un libro primero hay verificar si este existe, para ello usaremos la función buscar libro
    int pos_editar_libro;
    pos_editar_libro = buscar_libro(values, len);       //basicamente este es nuestro values
    
    if (pos_editar_libro != -1){  //para cualquier valor que sea distinto a -1 querrá decir que se ha encontrado el libro, entonces, hemos de elegir que es lo que queremos editar

        //Dejamos al usuario elegir sobre que quiere editar
        int editar_elegir;
        char editar_input;
        printf("1.- Titulo\n");
        printf("2.- Autor\n");
        printf("3.- Anio\n");
        printf("4.- Estante_numero\n");
        printf("5.- Estante_seccion\n");
        printf("6.- Piso;\n");
        printf("7.- Edificio;\n");
        printf("8.- Sede;\n");
        printf("9.- Salir del Menú;\n");
        printf("Seleccione el campo del libro que desea editar: ");
        scanf("%i",&editar_elegir);
        while(1){  
            if (editar_elegir == 1){ //editamos el titulo

                printf("El titulo libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].titulo);
                printf("Ingrese el titulo que desea:\n");
                fgets(editar_input,100,stdin);
                //scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].titulo, editar_input);
                printf("Se ha cambiado");
                editar_libro(values, len);
            }
            if (editar_elegir == 2){ //editamos autor

                printf("El autor libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].autor);
                printf("Ingrese el autor que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].autor, editar_input);
                printf("Se ha cambiado");

            }
            if (editar_elegir == 3){ //editamos el anio

                printf("El año libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].anio);
                printf("Ingrese el año que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].anio, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 4){ //editamos el estante_numero

                printf("El estante numero del libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].estante_numero);
                printf("Ingrese el estante_numero que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].estante_numero, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 5){ //editamos el esatnte_seccion

                printf("el estante seccion del libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].estante_seccion);
                printf("Ingrese el estante_seccion que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].estante_seccion, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 6){ //editamos el piso
                printf("el piso del libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].piso);
                printf("Ingrese el piso que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].piso, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 7){ //editamos el edificio

                printf("el edificio del libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].edificio);
                printf("Ingrese el edificio que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].edificio, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 8){ //editamos la sede

                printf("el estante seccion del libro actualmente es:\n");
                printf("%s\n", values[pos_editar_libro].estante_seccion);
                printf("Ingrese el titulo que desea:\n");
                scanf("%s", &editar_input);
                strcpy(values[pos_editar_libro].estante_seccion, editar_input);
                printf("Se ha cambiado!");
            }
            if (editar_elegir == 9){
                break;
            }
        }
    } 

}
 



int main(){
    
    dict values[999];
    int contador_filas = leer_csv(values);
    //mostrar_valores(values, contador_filas);
    //buscar_libro(values, contador_filas);
    
    editar_libro(values, contador_filas);    
    
    
    // menu_principal() 
    return 0;
}