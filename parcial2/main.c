#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parse.h"
#include "Dominios.h"
#include "menu.h"
#include "loadText.h"


int main()
{
    LinkedList* dominioLinkedList=ll_newLinkedList();
    int result;
    int opcion;
    char archivo[20];

    do{
        system("cls");
        opcion = menu();

        switch(opcion){

        case 1:
            system("cls");
            printf("Ingrese el nombre del archivo: ");
            scanf("%s", archivo);
            result= loadFromText(archivo,dominioLinkedList);
            if(!result){
                printf("No se encontro el archivo indicado\n");
            }else{
                printf("Se cargo correctamente el archivo\n");
            }
            break;
        case 2:

            if(ll_isEmpty(dominioLinkedList)==0){
                ll_sort(dominioLinkedList, orderByDominio, 0);
                showEDominiosLiked(dominioLinkedList);
            }else{
                printf("La linkedList esta vacia\n");
            }
            break;
        case 0:
            break;
        default:
            printf("Error de dato ingreasado, reingrese\n");
            break;
        }
        system("pause");

    }while(opcion != 0);




    return 0;
}
