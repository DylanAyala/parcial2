#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parse.h"
#include "Dominios.h"

eDominio* eDominio_newParametros(char* idStr,char* dominioStr,char* anioStr)
{
    eDominio* this;
        if(idStr!=NULL && dominioStr!=NULL && anioStr!=NULL)
        {
            this= eDominio_new();
            if(this!=NULL)
            {
                if(!eDominio_setId(this,atoi(idStr)) || !eDominio_setDominio(this,dominioStr)
                   || !eDominio_setAnio(this,atoi(anioStr)))
                {
                    free(this);
                    this=NULL;
                }
            }
        }

    return this;
}

eDominio* eDominio_new()
{
    eDominio* this= (eDominio*) malloc(sizeof(eDominio));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->dominio,"");
        this->anio=0;
    }

    return this;
}

int eDominio_setId(eDominio* this,int id)
{
    int itsOk=0;
    if(this!=NULL && id >0)
    {
        this->id=id;
        itsOk=1;
    }

    return itsOk;
}



int eDominio_getId(eDominio* this,int* id)
{
    int itsOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        itsOk = 1;
    }
    return itsOk;
}


int eDominio_setDominio(eDominio* this,char* dominio)
{
    int itsOk=0;
    if(this!=NULL && dominio!=NULL)
    {
        strcpy(this->dominio,dominio);
        itsOk=1;

    }

    return itsOk;
}


int eDominio_getDominio(eDominio* this,char* dominio)
{
    int itsOk=0;
    if(this!=NULL && dominio!=NULL)
    {
        strcpy(dominio,this->dominio);
        itsOk=1;
    }

    return itsOk;
}



int eDominio_setAnio(eDominio* this,int anio)
{
    int todoOk=0;

    if(this!=NULL && anio>0)
    {
        this->anio=anio;
        todoOk = 1;
    }


    return todoOk;
}



int eDominio_getAnio(eDominio* this,int* anio)
{
    int todoOk=0;

    if(this!=NULL && anio>0)
    {
        *anio=this->anio;
        todoOk = 1;
    }


    return todoOk;
}

int showEDominiosLiked(LinkedList* pArrayListeDominio)
{
    int listOk=0;
    if(pArrayListeDominio!=NULL)
    {
        system("cls");
        printf(" ID  |  Dominio  | Anio\n\n");
        showEDominios(pArrayListeDominio);
        printf("\n");
        listOk=1;
    }

    return listOk;
}


void showEDominios(LinkedList* pArrayLinkedList)
{
    if(pArrayLinkedList!=NULL)
    {
        for(int i=0;i<ll_len(pArrayLinkedList);i++)
        {
            showEDominio((eDominio*) ll_get(pArrayLinkedList,i));
        }
        printf("\n\n");
    }
}


void showEDominio(eDominio* emp)
{
    if(emp!=NULL)
    printf("%4d  %10s  %5d \n\n",emp->id,emp->dominio,emp->anio);
}

int orderByDominio(void* dom1, void* dom2)
{
    int retorno=0;
    eDominio* p1;
    eDominio* p2;

    if(dom1 != NULL && dom2 != NULL)
    {
        p1=(eDominio*) dom1;
        p2=(eDominio*) dom2;

        if(strcmp(p1->dominio,p2->dominio)==-1)
            retorno = 1;
        else if(strcmp(p1->dominio,p2->dominio)==1)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}
