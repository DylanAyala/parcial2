#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
typedef struct{
    int id;
    char dominio[20];
    int anio;

}eDominio;

eDominio* eDominio_newParametros(char* idStr,char* dominioStr,char* anioStr);

eDominio* eDominio_new();

int eDominio_setId(eDominio* this,int id);

int eDominio_getId(eDominio* this,int* id);

int eDominio_setDominio(eDominio* this,char* dominio);

int eDominio_getDominio(eDominio* this,char* dominio);

int eDominio_setAnio(eDominio* this,int anio);

int eDominio_getAnio(eDominio* this,int* anio);

void showEDominios(LinkedList* pArrayLinkedList);

void showEDominio(eDominio* emp);

int showEDominiosLiked(LinkedList* pArrayListeDominio);

int orderByDominio(void* dom1, void* dom2);



#endif // DOMINIOS_H_INCLUDED
