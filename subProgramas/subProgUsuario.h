#ifndef SUBPROGUSUARIO_H_INCLUDED
#define SUBPROGUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "../TDA/arbolUsuario.h"
#include "../TDA/listaSimpleUsuario.h"
#include "../otrasFunciones.h"
#include "../TDA/listaDeListasVeterinaria.h"

#define arUsuarios "arUsuarios.dat"

void pasarDeArchivoToMemoriaUsuario(nodoArbolUsuario **arbolUsuario);
nodoArbolUsuario* pasarDeArregloToArbolUsuario(nodoArbolUsuario *arbolUsuario, stUsuario arregloUsuario[], int ini, int fin);
void pasarDeArchivoToArregloUsuario(stUsuario arregloUsuario[], FILE *Buffer);
int ContarRegistrosUsuario(FILE *Buffer, int tstruct);
void crearCuentaUsuario(nodoArbolUsuario **arbolUsuario);
void ModificarUsuario(nodoArbolUsuario **usuarioIngresado);
void agregarPerro(nodoArbolUsuario **usuarioIngresado);
void mostrarPerrosUsuario(stPerro arregloPerros[], int perrosValidos);
int buscarPosPerro(stPerro perros[],char nombrePerro[], int perrosValidos);
void modificarPerros(nodoArbolUsuario **usuarioIngresado);
int darseDeBaja(nodoArbolUsuario **usuarioIngresado);
void pasardeArbolUsuarioToListaUsuario(nodoArbolUsuario *arbolUsuario, nodoListaUsuario **listaUsuario);
void pasarDeListaUsuarioToArchivoUsuario(nodoListaUsuario *listaUsuario);

#endif // SUBPROGUSUARIO_H_INCLUDED
