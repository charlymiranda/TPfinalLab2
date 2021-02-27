#ifndef LISTASIMPLEVETERINARIA_H_INCLUDED
#define LISTASIMPLEVETERINARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "../estructuras/stVeterinaria.h"

typedef struct _nodoListaVeterinaria
{
    stVeterinaria dato;
    struct _nodoListaVeterinaria * siguiente;

} nodoListaVeterinaria;


void inicListaVeterinaria(nodoListaVeterinaria **pLista);
nodoListaVeterinaria *crearNodoListaVeterinaria(stVeterinaria dato);
void agregarPpioListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria);
void agregarFinalListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria);
nodoListaVeterinaria *buscarUltimoListaVeterinaria(nodoListaVeterinaria *pLista);
void borrarTodaLaListaVeterinaria(nodoListaVeterinaria **pLista);
void mostrarListaVeterinaria(nodoListaVeterinaria *pLista);
void borrarPrimernodoListaVeterinaria(nodoListaVeterinaria **pLista);
void borrarUltimonodoListaVeterinaria(nodoListaVeterinaria **pLista);
nodoListaVeterinaria *desvincularPrimernodoListaVeterinaria(nodoListaVeterinaria **pLista);
void mostrarNodoListaVeterinaria(nodoListaVeterinaria *aux);
nodoListaVeterinaria *buscarNodoListaVeterinaria(nodoListaVeterinaria **pLista, char nombre[]);
void borrarNodoListaVeterinaria(nodoListaVeterinaria **pLista, char nombre[]);
void agregarEnOrdenListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria);

#endif // LISTASIMPLEVETERINARIA_H_INCLUDED
