#include "listaDeListasVeterinaria.h"

void inicLDLBarrio(nodoLDLBarrio **LDLBarrio)
{
    *LDLBarrio=NULL;
}

nodoLDLBarrio *crearnodoLDLBarrio(char barrio[])
{
    nodoLDLBarrio *nuevo = (nodoLDLBarrio*) malloc(sizeof(nodoLDLBarrio));/*crea un nodo de la lista principal*/
    strcpy(nuevo->barrio, barrio);/*e indentifica por el nombrede cada uno  de los barrios*/
    inicListaVeterinaria(&nuevo->listaVeterinaria);/* inicia la lista secundaria*/
    nuevo->siguiente=NULL;

    return nuevo;
}

void agregarPpioLDLBarrio(nodoLDLBarrio **LDLBarrio, nodoLDLBarrio *nuevo)
{
    if(!(*LDLBarrio))
    {
        *LDLBarrio=nuevo;
    }
    else
    {
        nuevo->siguiente=*LDLBarrio;
        *LDLBarrio=nuevo;
    }
}
///da de alta un nuevo nodo el la lista principal si el barrio no fue encontrado previamente
void altaLDLBarrio(nodoLDLBarrio **LDLBarrio, nodoListaVeterinaria *nuevaVeterinaria, char barrio[])
{
    nodoLDLBarrio *barrioEncontrado = buscarLDLBarrio(*LDLBarrio, barrio);

    if(!barrioEncontrado)/*si no se encuentra el barrio*/
    {
        agregarPpioLDLBarrio(LDLBarrio, crearnodoLDLBarrio(barrio));
        agregarFinalListaVeterinaria(&(*LDLBarrio)->listaVeterinaria, nuevaVeterinaria);
    }
    else /*si existe el barrio aagrega la veterinaria al final*/
    {
        agregarFinalListaVeterinaria(&barrioEncontrado->listaVeterinaria, nuevaVeterinaria);
    }
}
/*busca el nodo en la lista pricipal segundo el barrio*/
nodoLDLBarrio *buscarLDLBarrio(nodoLDLBarrio *LDLBarrio, char barrio[])
{
    int flag=0;
    nodoLDLBarrio *barrioEncontrado=NULL;

    while(LDLBarrio && flag==0)
    {
        if(strcmpi(LDLBarrio->barrio, barrio)==0)/*si lo encuentra*/
        {
            barrioEncontrado=LDLBarrio;/* lo iguala*/
            flag=1;
        }
        LDLBarrio=LDLBarrio->siguiente;
    }

    return barrioEncontrado;
}

void recorrerYMostrarLDLBarrio(nodoLDLBarrio *LDLBarrio)
{
    while(LDLBarrio)
    {
        printf("\nBARRIO: %s\n", LDLBarrio->barrio);
        mostrarListaVeterinaria(LDLBarrio->listaVeterinaria);
        LDLBarrio=LDLBarrio->siguiente;
    }
}



