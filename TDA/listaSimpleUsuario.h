#ifndef LISTASIMPLEUSUARIO_H_INCLUDED
#define LISTASIMPLEUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "../estructuras/stUsuario.h"

typedef struct _nodoListaUsuario
{
    stUsuario dato;
    struct _nodoListaUsuario * siguiente;

} nodoListaUsuario;

void inicListaListaUsuario(nodoListaUsuario **pLista);
nodoListaUsuario *crearNodoListaUsuario(stUsuario dato);
void agregarPpioListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario);
void agregarFinalListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario);
nodoListaUsuario *buscarUltimoListaUsuario(nodoListaUsuario *pLista);
void borrarTodaLaListaUsuario(nodoListaUsuario **pLista);
void mostrarListaUsuario(nodoListaUsuario **pLista);
void borrarPrimernodoListaUsuario(nodoListaUsuario **pLista);
void borrarUltimonodoListaUsuario(nodoListaUsuario **pLista);
nodoListaUsuario *desvincularPrimernodoListaUsuario(nodoListaUsuario **pLista);
void mostrarNodoListaUsuario(nodoListaUsuario *aux);
nodoListaUsuario *buscarNodoListaUsuario(nodoListaUsuario **pLista, char nombre[]);
void borrarNodoListaUsuario(nodoListaUsuario **pLista, char nombre[]);
void agregarEnOrdenListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario);

#endif // LISTASIMPLEUSUARIO_H_INCLUDED
