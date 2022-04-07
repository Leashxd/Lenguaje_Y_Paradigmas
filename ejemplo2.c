#include <stdio.h>

void print_line(char* text) {
    printf("%s\n", text);
 }
int main(void) {
    printf("Ingresa tu nombre: ");
    char name[50];
    scanf("%s", name);
    print_line(name);
    return 0;

 }

 /* Toma unicamente una variable, BUSCAR UNA FORMA DE TOMAR DOS O N VARIABLES */
 /* Cambiar el codigo para formar una funcion */
