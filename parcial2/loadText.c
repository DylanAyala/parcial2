#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parse.h"



int loadFromText(char* path, LinkedList* pArrayList)
{
    int itsOk=-1;
    FILE* pFile;

    if(path!=NULL && pArrayList!=NULL)
    {
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            itsOk=0;
        }
        else
        {
            itsOk=parser_eDominioFromText(pFile,pArrayList);
        }

    }

    fclose(pFile);
    return itsOk;
}
