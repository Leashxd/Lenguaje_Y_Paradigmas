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

    //SELECCIONAMOS EL LIBRO
    //Comprobando si funciona el array.
/* 
    int numero_libro;
    printf("Ingrese el libro que desea buscar por numero: ");
    scanf("%i",&numero_libro);
    printf("Tu numero libro es: %i\n ",numero_libro);
    if (numero_libro != NULL){

        printf("Encontramos tu libro! \nTitulo: %s\n Autor: %s\n Anio: %s\n Estante Numero: %s\n Estante Seccion: %s\n Piso: %s\n Edificio: %s\n Sede:%s\n\n",
         values[numero_libro].titulo,
         values[numero_libro].autor,
         values[numero_libro].anio,
         values[numero_libro].estante_numero,
         values[numero_libro].estante_seccion, 
         values[numero_libro].piso,
         values[numero_libro].edificio,
         values[numero_libro].sede);
    }
 */
    //En efecto hemos comprobado que podemos llamar a cada libro mediante un input.    
}

void buscar_libro(dict values[], int len){
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
            break;
        }
    }
    if((strcmp( auxiliar, input_titulo ))!=0){
            printf("Lo sentimos, tu libro no es parte de nuestro repositorio");
            printf("\nauxiliar= %s\n   \ninput_titulo: %s",auxiliar,input_titulo);
            
        }
    
}

int leer_csv(dict values[]){
  /* DEFINIMOS VARIABLES PARA LEER EL CSV */
    int contador_filas = 0;
    int contador_celda = 0;
    char buffer[BSIZE];  //para leer el csv
    //dict values[999];
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


/* void menu_principal(){
    int opcion;
    char repetir = TRUE;

    do
    {
        system("cls");

        printf("\n\n\t\t\tMENU PRINCIPAL\n");
        printf("\t\t\t--------------\n");
        printf("\n\t1. Agregar\n");
        printf("\t2. Quitar\n");
        printf("\t3. Editar\n");
        printf("\t0. SALIR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            menu_agregar();
            break;

        case 2:
            menu_quitar();
            break;

        case 3:
            menu_editar();
            break;  

        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

// Definiciones de las funciones

void menu_agregar(){
    int opcion;
    char repetir = TRUE;

    do
    {
        system("cls");

        printf("\n\n\t\t\tMENU AGREGAR\n");
        printf("\t\t\t------------------------\n");
        printf("\n\t1. Libro\n");
        printf("\t2. Sección\n");
        printf("\t3. Piso\n");
        printf("\t4. Sede\n");
        printf("\t0. REGRESAR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            //agregar_libro();
            break;

        case 2:
            //agregar_piso();
            break;

        case 3:
            //agregar_seccion();
            break;

        case 4:
            //agregar_sede();
            break;

        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

void menu_editar(){
    int opcion;
    char repetir = TRUE;

    do
    {
        system("cls");

        printf("\n\n\t\t\tMENU EDITAR\n");
        printf("\t\t\t------------------------\n");
        printf("\n\t1. Titulo Libro\n");
        printf("\t2. Autor Libro\n");
        printf("\t3. Año Libro\n");
        printf("\t4. Número estante Libro\n");
        printf("\t5. Sección estante Libro\n");
        printf("\t6. Piso Libro\n");
        printf("\t7. Edificio Libro\n");
        printf("\t8. Sede Libro\n");
        printf("\t0. REGRESAR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            //editar_titulo();
            break;

        case 2:
            //editar_autor();
            break;

        case 3:
            //editar_anio();
            break;

        case 4:
            //editar_estante_numero();
            break;

        case 5:
            //editar_estante_seccion();
            break;

        case 6:
            //editar_piso();
            break;

        case 7:
           // editar_edificio();
            break;

        case 8:
            //editar_sede();
            break;
          
        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

void menu_quitar(){
    int opcion;
    char repetir = TRUE;

    do
    {
        system("cls");

        printf("\n\n\t\t\tMENU QUITAR\n");
        printf("\t\t\t------------------------\n");
        printf("\n\t1. Libro\n");
        printf("\t2. Sección\n");
        printf("\t3. Piso\n");
        printf("\t4. Sede\n");
        printf("\t0. REGRESAR\n");

        printf("\n\tIngrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            //quitar_libro();
            break;

        case 2:
            //quitar_seccion();
            break;

        case 3:
            //quitar_piso();
            break;

        case 4:
            //quitar_sede();
            break;

        case 0:
            repetir = FALSE;
            break;
        }
    } while (repetir);
}

// _________________Funciones que alteran el csv________________________________
void quitar_libro(){
    char libro_quitar[100];
    printf("¿Qué libro deseas quitar?");
    scanf("%s", libro_quitar);

    // int i;
    // for (i = 0; i < ARRAY_SIZE; i++)
    // {
    //     if (strcmp(myPs[i].name, myName) == 0)
    //     {
    //         return myPs[i].age;
    //     }
    // }
    // return -1;

}

//______________________________________________________________________________
 */

//void seleccionar_libro(dict values[]){

    
    





int main(){
    dict values[999];
    int contador_filas = leer_csv(values);
    mostrar_valores(values, contador_filas);
    buscar_libro(values, contador_filas);
    // menu_principal() 
    return 0;
}