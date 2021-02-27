#ifndef LISTADELISTASVETERINARIA_H_INCLUDED
#define LISTADELISTASVETERINARIA_H_INCLUDED

#include "../estructuras/stVeterinaria.h"
#include "../TDA/listaSimpleVeterinaria.h"

typedef struct _nodoLDLBarrio
{
    char barrio[50];
    nodoListaVeterinaria *listaVeterinaria;
    struct _nodoLDLBarrio *siguiente;
} nodoLDLBarrio;

void inicLDLBarrio(nodoLDLBarrio **LDLBarrio);
nodoLDLBarrio *crearnodoLDLBarrio(char barrio[]);
void agregarPpioLDLBarrio(nodoLDLBarrio **LDLBarrio, nodoLDLBarrio *nuevo);
void altaLDLBarrio(nodoLDLBarrio **LDLBarrio, nodoListaVeterinaria *nuevaVeterinaria, char barrio[]);
nodoLDLBarrio *buscarLDLBarrio(nodoLDLBarrio *LDLBarrio, char barrio[]);
void recorrerYMostrarLDLBarrio(nodoLDLBarrio *LDLBarrio);

#endif // LISTADELISTASVETERINARIA_H_INCLUDED
