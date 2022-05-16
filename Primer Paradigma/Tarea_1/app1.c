#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BSIZE 1024
#define TRUE 1
#define FALSE 0
#define MAXLINE 100

//Struct
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

int leer_csv(dict values[], char *argv[]){
  /* DEFINIMOS VARIABLES PARA LEER EL CSV */
    int contador_filas = 0;
    int contador_celda = 0;
    char buffer[BSIZE];  //para leer el csv
    FILE *archivo = fopen(argv[1],"r");  //puntero con la dirección del csv, con el caracter "r" -> read

    /* CONDICION EN CASO DE QUE NO PODAMOS LEER EL ARCHIVO */
    if (archivo == NULL){                       //condición en caso de que se presente algun problema al tratar de leer el archivo 
        perror("No es posible abrir el archivo, revise el formato y/o su directorio.");
        exit(1);
    }

    /* PROCESO PARA LEER EL CSV */
    
    int i = 0;  //variable que nos ayudará a recorrer las filas y colocarlas en el array. Comenzamos en 1 para saltarnos indice de csv.
    while(fgets(buffer, BSIZE , archivo)){
        if(i == 0){
            i++;
            continue;} //se salta el primer fgets
        contador_filas++;
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
                celda[strcspn(celda, "\n")] = 0;
                strcpy(values[i-1].sede, celda);       
            }
            celda = strtok(NULL, "~");
        }
        i++;
    }
    fclose(archivo); //cerramos el archivo ahora que tenemos todo el array

    return(contador_filas);       
}

//Buscar libro
int buscar_libro(dict values[], int len){
    //CREAR UN MATCH ENTRE EN EL ARREGLO
    //Primero realizaremos un buscar por TITULO
    char input_titulo[100];
    char *auxiliar;
    int ch[100];
    fflush(stdout);
    printf("Ingrese el titulo del libro que desea buscar: ");

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
    for(int i=0; i<len; i=i+1){
        auxiliar = values[i].titulo;
        if ((strcmp( auxiliar, input_titulo)==0)){
            printf("\nHEMOS ENCONTRADO TU LIBRO!\n");
            printf("\n Titulo: %s\n Autor: %s\n Anio: %s\n Estante Numero: %s\n Estante Seccion: %s\n Piso: %s\n Edificio: %s\n Sede:%s\n\n",
            values[i].titulo,
            values[i].autor,
            values[i].anio,
            values[i].estante_numero,
            values[i].estante_seccion, 
            values[i].piso,
            values[i].edificio,
            values[i].sede);
            printf("Presione enter para continuar.");
            while( getchar() != '\n' );
            return i;
        }
    }
    printf("Lo sentimos, tu libro no es parte de nuestro repositorio: %s\n", input_titulo);
    printf("Presione enter para continuar.");
    while( getchar() != '\n' );
    return -1;
}

//Agregar
void menu_agregar(dict values[],int *cantidad_filas_variable){
    int opcion;
    char opcion_char[MAXLINE];
    char repetir = TRUE;
    char titulo_agregar[100];           
    char autor_agregar[100];
    char anio_agregar[100];               
    char estante_numero_agregar[100];
    char estante_seccion_agregar[100];
    char piso_agregar[100];
    char edificio_agregar[100];          
    char sede_agregar[100];

    do{
        printf("\n\n\t\t\tMENU AGREGAR\n");
        printf("\t\t\t------------------------\n");
        printf("\n\t1. Libro\n");
        printf("\t2. Sección\n");
        printf("\t3. Piso\n");
        printf("\t4. Sede\n");
        printf("\t5. REGRESAR\n");
        printf("\n\tIngrese una opcion: ");
        fgets(opcion_char, MAXLINE, stdin);
        opcion = atoi(opcion_char);
        switch (opcion){
            case 1:
                printf("Nombre del libro que quiere agregar: ");
                fgets(titulo_agregar, MAXLINE, stdin);
                titulo_agregar[strcspn(titulo_agregar, "\n")] = 0;
                printf("Nombre del autor del libro: ");
                fgets(autor_agregar, MAXLINE, stdin);
                autor_agregar[strcspn(autor_agregar, "\n")] = 0;
                printf("Año del libro: ");
                fgets(anio_agregar, MAXLINE, stdin);
                anio_agregar[strcspn(anio_agregar, "\n")] = 0; 
                printf("En que estante lo quieres poner: ");
                fgets(estante_numero_agregar, MAXLINE, stdin);
                estante_numero_agregar[strcspn(estante_numero_agregar, "\n")] = 0;
                printf("En que sección lo quieres poner: ");
                fgets(estante_seccion_agregar, MAXLINE, stdin);
                estante_seccion_agregar[strcspn(estante_seccion_agregar, "\n")] = 0;
                printf("En que piso lo quieres poner: ");
                fgets(piso_agregar, MAXLINE, stdin);
                piso_agregar[strcspn(piso_agregar, "\n")] = 0;
                printf("En que edificio quieres ponerlo: ");
                fgets(edificio_agregar, MAXLINE, stdin);
                edificio_agregar[strcspn(edificio_agregar, "\n")] = 0;
                printf("¿En que sede?: ");
                fgets(sede_agregar, MAXLINE, stdin);
                sede_agregar[strcspn(sede_agregar, "\n")] = 0;

                for (int i = 0; i<*cantidad_filas_variable; i++){ //Revisar que si hay una fila y mismos parametros con vacios se ponga ahi.
                    if ((strcmp(values[i].titulo,"$Vacio$") == 0) && (strcmp(values[i].autor,autor_agregar) == 0||
                    strcmp(values[i].autor,"$Vacio$")==0) && (strcmp(values[i].anio, anio_agregar) ==0 ||
                    strcmp(values[i].anio,"$Vacio$")==0) && (strcmp(values[i].estante_numero,estante_numero_agregar)==0 ||
                    strcmp(values[i].estante_numero,"$Vacio$")==0) && (strcmp(values[i].estante_seccion, estante_seccion_agregar) ==0 ||
                    strcmp(values[i].estante_seccion,"$Vacio$") ==0) && (strcmp(values[i].piso,piso_agregar) == 0 ||
                    strcmp(values[i].piso,"$Vacio$")==0) && (strcmp(values[i].edificio,edificio_agregar)==0||
                    strcmp(values[i].edificio,"$Vacio$")==0) && (strcmp(values[i].sede,sede_agregar) ==0||
                    strcmp(values[i].sede,"$Vacio$")==0)){

                        strcpy(values[i].titulo,titulo_agregar);
                        strcpy(values[i].autor, autor_agregar);
                        strcpy(values[i].anio,anio_agregar);
                        strcpy(values[i].estante_numero,estante_numero_agregar);
                        strcpy(values[i].estante_seccion,estante_seccion_agregar);
                        strcpy(values[i].piso,piso_agregar);
                        strcpy(values[i].edificio,edificio_agregar);
                        strcpy(values[i].sede,sede_agregar);
                        break;                
                    }
                    if (i == (*cantidad_filas_variable-1)){
                        strcpy(values[*cantidad_filas_variable].titulo, titulo_agregar);
                        strcpy(values[*cantidad_filas_variable].autor, autor_agregar);
                        strcpy(values[*cantidad_filas_variable].anio,anio_agregar);
                        strcpy(values[*cantidad_filas_variable].estante_numero,estante_numero_agregar);
                        strcpy(values[*cantidad_filas_variable].estante_seccion,estante_seccion_agregar);
                        strcpy(values[*cantidad_filas_variable].piso,piso_agregar);
                        strcpy(values[*cantidad_filas_variable].edificio,edificio_agregar);
                        strcpy(values[*cantidad_filas_variable].sede,sede_agregar);

                        *cantidad_filas_variable+=1;

                        break;          
                    }
                }
                break;
            case 2:
                printf("En que sección lo quieres poner: ");
                fgets(estante_seccion_agregar, MAXLINE, stdin);
                estante_seccion_agregar[strcspn(estante_seccion_agregar, "\n")] = 0;
                printf("En que piso lo quieres poner: ");
                fgets(piso_agregar, MAXLINE, stdin);
                piso_agregar[strcspn(piso_agregar, "\n")] = 0;
                printf("En que edificio quieres agregarla: ");
                fgets(edificio_agregar, MAXLINE, stdin);
                edificio_agregar[strcspn(edificio_agregar, "\n")] = 0;
                printf("En que sede quieres agregarla: ");
                fgets(sede_agregar, MAXLINE, stdin);
                sede_agregar[strcspn(sede_agregar, "\n")] = 0;
                for (int i = 0; i < *cantidad_filas_variable; ++i){
                    if ((strcmp(values[i].estante_seccion,"$Vacio$")==0)
                    &&(strcmp(values[i].piso,piso_agregar) ==0 || strcmp(values[i].piso,"$Vacio$") ==0)
                    &&(strcmp(values[i].edificio,edificio_agregar) == 0|| strcmp(values[i].edificio,"$Vacio$")==0)
                    &&(strcmp(values[i].sede,sede_agregar)==0|| strcmp(values[i].sede,"$Vacio$")==0)){
                        strcpy(values[i].estante_seccion,estante_seccion_agregar);
                        strcpy(values[i].piso,piso_agregar);
                        strcpy(values[i].edificio,edificio_agregar);
                        strcpy(values[i].sede,sede_agregar);
                        break;                
                    }
                    if (i == (*cantidad_filas_variable-1)){
                        strcpy(values[*cantidad_filas_variable].titulo,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].autor,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].anio,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].estante_numero,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].estante_seccion,estante_seccion_agregar);
                        strcpy(values[*cantidad_filas_variable].piso,piso_agregar);
                        strcpy(values[*cantidad_filas_variable].edificio,edificio_agregar);
                        strcpy(values[*cantidad_filas_variable].sede,sede_agregar);
                        *cantidad_filas_variable+=1;       
                        break;   
                    }
                }
                break;
            case 3:
                printf("Inserte el piso que quieres agregar: ");
                fgets(piso_agregar, MAXLINE, stdin);
                piso_agregar[strcspn(piso_agregar, "\n")] = 0;
                printf("En que edificio quieres agregarlo: ");
                fgets(edificio_agregar, MAXLINE, stdin);
                edificio_agregar[strcspn(edificio_agregar, "\n")] = 0;
                printf("En que sede quieres agregarlo: ");
                fgets(sede_agregar, MAXLINE, stdin);
                sede_agregar[strcspn(sede_agregar, "\n")] = 0;
                for (int i = 0; i < *cantidad_filas_variable; ++i){
                    if ((strcmp(values[i].piso,"$Vacio$")==0)&&(strcmp(values[i].edificio,edificio_agregar)==0|| strcmp(values[i].edificio,"$Vacio$")==0)&&(strcmp(values[i].sede,sede_agregar) ==0|| strcmp(values[i].sede,"$Vacio$")==0)){
                        strcpy(values[i].piso,piso_agregar);
                        strcpy(values[i].edificio,edificio_agregar);
                        strcpy(values[i].sede,sede_agregar);
                        break;                
                    }
                    if (i == (*cantidad_filas_variable-1)){
                        strcpy(values[*cantidad_filas_variable].titulo,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].autor,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].anio,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].estante_numero,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].estante_seccion,"$Vacio$");
                        strcpy(values[*cantidad_filas_variable].piso,piso_agregar);
                        strcpy(values[*cantidad_filas_variable].edificio,edificio_agregar);
                        strcpy(values[*cantidad_filas_variable].sede,sede_agregar);
                        *cantidad_filas_variable+=1;
                        break;
                    }
                }
                break;
            case 4:   
                printf("Ingrese la sede que quiere agregar: ");
                fgets(sede_agregar, MAXLINE, stdin);
                sede_agregar[strcspn(sede_agregar, "\n")] = 0;
                strcpy(values[*cantidad_filas_variable].titulo,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].autor,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].anio,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].estante_numero,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].estante_seccion,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].piso,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].edificio,"$Vacio$");
                strcpy(values[*cantidad_filas_variable].sede,sede_agregar);
                *cantidad_filas_variable+=1;          
                break;
            case 5:
                repetir = FALSE;
                break;
            default:
                printf("Favor ingrese un valor valido.\n");
                break;
            }
        }while (repetir);
    return;
}

//Quitar
int validar_si_libro(dict values[], int len, char* sede, char* edificio, char* piso, char* seccion){
    int tiene_libro = 0; //=0 no tiene libro, 1= si tiene libro
    for (int i = 0; i < len; i++)
    {
        if (strcmp(values[i].estante_seccion, seccion) == 0 || strcmp(seccion, "~~>") == 0)
        {
            if (strcmp(values[i].piso, piso) == 0 || strcmp(piso, "~~>") == 0)
            {
                if (strcmp(values[i].edificio, edificio) == 0 || strcmp(edificio, "~~>") == 0)
                {
                    if (strcmp(values[i].sede, sede) == 0)
                    {
                        if (strcmp(values[i].titulo, "$Vacio$") != 0)
                        {
                            tiene_libro = 1;
                            break;
                        }          
                    }
                    
                }
                
            }
            
        }
        
    }
    return(tiene_libro);
}

int eliminar(dict values[], int len, char* sede, char* edificio, char* piso, char* seccion, char* libro){
    int dato_correcto = 0; //si se ingreso un dato real
    int contador = 0;
    for (int i = 0; i < len; i++)
    {
        if (strcmp(sede, "~~>") == 0)
        {
            if (strcmp(values[i].titulo, libro) == 0)
            {
                strcpy(values[i].titulo, "$Vacio$");
                strcpy(values[i].anio, "$Vacio$");
                strcpy(values[i].autor, "$Vacio$");
                dato_correcto = 1;
            }
            continue;
        }
        if (strcmp(values[i].sede, sede) == 0)
        {
            if (strcmp(edificio, "~~>") == 0)
            {
                strcpy(values[i].sede, "$Borrado$");
                dato_correcto = 1;
                continue;
            }
            if (strcmp(values[i].edificio, edificio) == 0)
            {
                if (strcmp(values[i].piso, piso) == 0 && strcmp(piso, "~~>") != 0)
                {
                    if (strcmp(seccion, "~~>") == 0)
                    {
                        if (contador == 0)
                        {
                            strcpy(values[i].piso, "$Vacio$");
                            strcpy(values[i].estante_seccion, "$Vacio$");
                            strcpy(values[i].estante_numero, "$Vacio$");
                            dato_correcto = 1;
                            contador++;
                            continue;
                        }
                        else{
                            strcpy(values[i].sede, "$Borrado$");
                            dato_correcto = 1;
                            contador++;
                            continue;
                        }
                    }
                    if (strcmp(values[i].estante_seccion, seccion) == 0)
                    {
                        if (contador == 0)
                        {
                            strcpy(values[i].estante_seccion, "$Vacio$");
                            strcpy(values[i].estante_numero, "$Vacio$");
                            dato_correcto = 1;
                            contador++;
                            continue;
                        }
                        else{
                            strcpy(values[i].sede, "$Borrado$");
                            dato_correcto = 1;
                            contador++;
                            continue;
                        }
                    }
                }
            }
        }
    }
    return dato_correcto;
}

void menu_quitar(dict values[], int len)
{   
    int opcion;
    char opcion_char[MAXLINE];
    int validacion;
    int dato_correcto;
    char libro[50];
    char sede[50];
    char edificio[50];
    char piso[50];
    char seccion[50];
    char repetir = TRUE;
    do
    {
        printf("\n\n\t\t\tMENU QUITAR\n");
        printf("\t\t\t------------------------\n");
        printf("\n\t1. Libro\n");
        printf("\t2. Sección\n");
        printf("\t3. Piso\n");
        printf("\t4. Sede\n");
        printf("\t5. REGRESAR\n");

        printf("\n\tIngrese una opcion: ");
        fgets(opcion_char, MAXLINE, stdin);
        opcion = atoi(opcion_char);
        switch (opcion)
        {
        case 1: //libro
            printf("\n\tIngrese el libro que quieres quitar: ");
            fgets(libro, MAXLINE, stdin);
            libro[strcspn(libro, "\n")] = 0;
            strcpy(edificio, "~~>");
            strcpy(piso, "~~>");
            strcpy(seccion, "~~>");
            strcpy(sede, "~~>");
            dato_correcto = eliminar(values, len, sede, edificio, piso, seccion, libro);
            if (dato_correcto == 1)
            {
                printf("Se elimino con exito!\n");
            }
            else
            {
                printf("Favor ingrese los datos de la misma forma que se encuentran en el archivo csv.\n");
            }
            break;

        case 2: //seccion
            printf("\n\tIngrese la sede de la cual quiere eliminar la seccion: ");
            fgets(sede, MAXLINE, stdin); //en el struct las sedes tienen saltos de linea, por lo que aqui no quitaremos salto de linea del fgets.
            sede[strcspn(sede, "\n")] = 0;
            printf("\n\tIngrese el edificio del cual quiere eliminar la seccion: ");
            fgets(edificio, MAXLINE, stdin);
            edificio[strcspn(edificio, "\n")] = 0;
            printf("\n\tIngrese el piso del cual quiere eliminar la seccion: ");
            fgets(piso, MAXLINE, stdin);
            piso[strcspn(piso, "\n")] = 0;
            printf("\n\tIngrese la seccion que quiere eliminar: ");
            fgets(seccion, MAXLINE, stdin);
            seccion[strcspn(seccion, "\n")] = 0;
            validacion = validar_si_libro(values, len, sede, edificio, piso, seccion);
            if (validacion == 1)
            {
                printf("Favor ingresar una seccion sin libros en su interior.\n");
                break;
            }
            else
            {
                dato_correcto = eliminar(values, len, sede, edificio, piso, seccion, libro);
                if (dato_correcto == 1)
                {
                    printf("Se elimino con exito!\n");
                }
                else
                {
                    printf("Favor ingrese los datos de la misma forma que se encuentran en el archivo csv.\n");
                }
            }
            break;

        case 3: //piso
            printf("\n\tIngrese la sede de la cual quiere eliminar la seccion: ");
            fgets(sede, MAXLINE, stdin);
            sede[strcspn(sede, "\n")] = 0;
            printf("\n\tIngrese el edificio del cual quiere eliminar la seccion: ");
            fgets(edificio, MAXLINE, stdin);
            edificio[strcspn(edificio, "\n")] = 0;
            printf("\n\tIngrese el piso del cual quiere eliminar la seccion: ");
            fgets(piso, MAXLINE, stdin);
            piso[strcspn(piso, "\n")] = 0;
            strcpy(seccion, "~~>");
            validacion = validar_si_libro(values, len, sede, edificio, piso, seccion);
            if (validacion == 1)
            {
                printf("Favor ingresar un piso sin libros en su interior.\n");
                break;
            }
            else
            {
                dato_correcto = eliminar(values, len, sede, edificio, piso, seccion, libro);
                if (dato_correcto == 1)
                {
                    printf("Se elimino con exito!\n");
                }
                else
                {
                    printf("Favor ingrese los datos de la misma forma que se encuentran en el archivo csv.\n");
                }
            }
            break;

        case 4: //sede
            printf("\n\tIngrese la sede de la cual quiere eliminar la seccion: ");
            fgets(sede, MAXLINE, stdin);
            sede[strcspn(sede, "\n")] = 0;
            strcpy(edificio, "~~>");
            strcpy(piso, "~~>");
            strcpy(seccion, "~~>");
            validacion = validar_si_libro(values, len, sede, edificio, piso, seccion);
            if (validacion == 1)
            {
                printf("Favor ingresar una seccion sin libros en su interior.\n");
                break;
            }
            else
            {
                dato_correcto = eliminar(values, len, sede, edificio, piso, seccion, libro);
                if (dato_correcto == 1)
                {
                    printf("Se elimino con exito!\n");
                }
                else
                {
                    printf("Favor ingrese los datos de la misma forma que se encuentran en el archivo csv.\n");
                }
            }
            break;

        case 5:
            repetir = FALSE;
            break;

        default:
            printf("Favor ingrese un valor valido.\n");
            break;
        }
        
    } while (repetir);
    return;
}

//Editar
void editar_libro(dict values[], int len){
    
    //para editar un libro primero hay verificar si este existe, para ello usaremos la función buscar libro
    int pos_editar_libro = buscar_libro(values, len);       //basicamente este es nuestro values
    
    if (pos_editar_libro != -1){  //para cualquier valor que sea distinto a -1 querrá decir que se ha encontrado el libro, entonces, hemos de elegir que es lo que queremos editar

        //Dejamos al usuario elegir sobre que quiere editar
        int editar_elegir;
        char opcion_char[MAXLINE];
        char editar_input[100];
        int repetir = TRUE;
        while (repetir)
        {
            printf("\n\n\t1.- Titulo\n");
            printf("\t2.- Autor\n");
            printf("\t3.- Año\n");
            printf("\t4.- Estante_numero\n");
            printf("\t5.- Estante_seccion\n");
            printf("\t6.- Piso\n");
            printf("\t7.- Edificio\n");
            printf("\t8.- Sede\n");
            printf("\t9.- Volver\n");
            printf("Seleccione el campo del libro que desea editar: ");
            fgets(opcion_char, MAXLINE, stdin);
            editar_elegir = atoi(opcion_char);
            printf("\n");

            switch (editar_elegir)
            {
                case 1: //Titulo
                    printf("El titulo libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].titulo);
                    printf("Ingrese el titulo que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].titulo, editar_input);
                    printf("\nSe ha cambiado");
                    break;
                case 2: //Autor
                    printf("El autor libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].autor);
                    printf("Ingrese el autor que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].autor, editar_input);
                    printf("\nSe ha cambiado");
                    break;
                case 3: //Anio
                    printf("El año libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].anio);
                    printf("Ingrese el año que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].anio, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 4: //Estante_numero
                    printf("El estante numero del libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].estante_numero);
                    printf("Ingrese el estante_numero que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].estante_numero, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 5: //Estante_seccion
                    printf("El estante seccion del libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].estante_seccion);
                    printf("Ingrese el estante_seccion que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].estante_seccion, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 6: //Piso
                    printf("El piso del libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].piso);
                    printf("Ingrese el piso que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].piso, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 7: //Edificio
                    printf("El edificio del libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].edificio);
                    printf("Ingrese el edificio que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].edificio, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 8: //Sede
                    printf("La sede del libro actualmente es: ");
                    printf("%s\n", values[pos_editar_libro].sede);
                    printf("Ingrese la sede que desea: ");
                    fgets(editar_input, MAXLINE, stdin);
                    editar_input[strcspn(editar_input, "\n")] = 0;
                    strcpy(values[pos_editar_libro].sede, editar_input);
                    printf("\nSe ha cambiado!");
                    break;
                case 9: //Volver
                    repetir = FALSE;
                    break;
                default:
                    printf("Favor ingrese un valor valido.\n");
                    break;
            }
        }
    }
    if (pos_editar_libro == -1)
    {
        printf("No se encontro el libro que quiere editar, favor ingresar el titulo de la misma forma que se encuentra en el csv.\n");
    }
    return;
}

//Guardar
void archivo(dict values[], int largo, char *argv[]){
    FILE *fout = fopen(argv[1], "w");
    fprintf(fout, "%s\n", "titulo,autor,anio,estante_numero,estante_seccion,piso,edificio,sede");
    for(int i=0; i<largo; i++){
        if (strcmp(values[i].sede, "$Borrado$") != 0)
        {
            fprintf(fout,"%s,%s,%s,%s,%s,%s,%s,%s\n",
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
    fclose(fout);
}

//Menu principal
void menu_principal(dict values[], char *argv[])
{
    char opcion_char[MAXLINE];
    int repetir = TRUE;
    int opcion;
    int pos;
    int len = leer_csv(values, argv);

    while (repetir)
    {
        printf("\n\n\t\t\tMENU PRINCIPAL\n");
        printf("\t\t\t--------------\n");
        printf("\n\t1. Buscar\n");
        printf("\t2. Agregar\n");
        printf("\t3. Quitar\n");
        printf("\t4. Editar\n");
        printf("\t5. SALIR\n");

        printf("\n\tIngrese una opcion: ");
        fgets(opcion_char, MAXLINE, stdin);
        opcion = atoi(opcion_char);

        switch (opcion)
        {
            case 1:; //si no se usa ; no se puede sobreescribir variable dsp de instancia case o goto
                pos = buscar_libro(values, len);
                break;
            case 2:
                menu_agregar(values, &len);
                break;

            case 3:
                menu_quitar(values, len);
                break;

            case 4:
                editar_libro(values, len);
                break;  

            case 5:
                repetir = FALSE;
                archivo(values, len, argv);
                break;
            default:
                printf("Favor ingrese un valor valido.\n");
                break;
        }
    }
}

int main(int argc, char *argv[]){
    dict values[999];
    menu_principal(values, argv);
    return 0;
}