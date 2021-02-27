#ifndef ARBOLUSUARIO_H_INCLUDED
#define ARBOLUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "../estructuras/stUsuario.h"

typedef struct _nodoArbolUsuario
{
    stUsuario dato;
    struct _nodoArbolUsuario *izq;
    struct _nodoArbolUsuario *der;

} nodoArbolUsuario;

void inicArbolUsuario(nodoArbolUsuario **arbolito);
nodoArbolUsuario* crearNodoArbolUsuario(stUsuario dato);
nodoArbolUsuario* insertarArbolUsuario(nodoArbolUsuario *arbolito, stUsuario dato);
void preorderUsuarioFiltro(nodoArbolUsuario *arbolito, int alta);
void preorderUsuarioFiltroPerros(nodoArbolUsuario *arbolito, int perdido);
void preorderUsuario(nodoArbolUsuario *arbolito);
void inorderUsuario(nodoArbolUsuario *arbolito);
void postorderUsuario(nodoArbolUsuario *arbolito);
nodoArbolUsuario *buscarArbolUsuario(nodoArbolUsuario *arbolito, char user[]);
nodoArbolUsuario *buscarArbolUsuarioConPass(nodoArbolUsuario *arbolito, char user[], char pass[]);
nodoArbolUsuario *buscarNombreArbolUsuario(nodoArbolUsuario *arbolito, char nombre[]);
int mayorArbolUsuario(int izquierdo, int derecho);
int alturaDelArbolUsuario(nodoArbolUsuario *arbolito);
int cantidadDeNodosArbolUsuario(nodoArbolUsuario *arbolito);
int cantidadDeNodosFiltradoArbolUsuario(nodoArbolUsuario *arbolito);
int cuentaHojasUsuario(nodoArbolUsuario *arbolito);
int sumaRecursivaArbolUsuario(nodoArbolUsuario *arbolito);
int sumaRecursivaArbolParesUsuario(nodoArbolUsuario *arbolito);

#endif // ARBOLUSUARIO_H_INCLUDED
