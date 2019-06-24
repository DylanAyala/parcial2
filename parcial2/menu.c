#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int menu(){
    int opcion;
    printf("Menu De oppcions\n");
    printf("1-Cargar Archivo\n");
    printf("2-Listar Archivo\n");
    printf("0-Salir\n\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
