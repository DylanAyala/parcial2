#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Dominios.h"

int parser_eDominioFromText(FILE* pFile, LinkedList* pArrayListEDominio)
{
    int itsOk=-1;
    int counter;
    char buffer[3][150];
    if(pFile!=NULL && pArrayListEDominio!=NULL)
    {
        eDominio* eDominioNew;
            while(!feof(pFile))
            {
                counter=fscanf(pFile,"%[^,],%[^,],%[^\n] \n",buffer[0],buffer[1],buffer[2]);


                    if(counter==3)
                    {
                        eDominioNew=eDominio_newParametros(buffer[0],buffer[1],buffer[2]);
                        if(eDominioNew!=NULL)
                        {
                            ll_add(pArrayListEDominio,eDominioNew);
                            itsOk=1;
                        }
                    }

            }
    }
    return itsOk;
}
