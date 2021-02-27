#ifndef SUBPROGADMIN_H_INCLUDED
#define SUBPROGADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#define arAdmins "arAdmins.dat"

#include "../TDA/arbolUsuario.h"
#include "../TDA/listaSimpleUsuario.h"
#include "../TDA/listaDeListasVeterinaria.h"
#include "../otrasFunciones.h"

void verUsuarios(nodoArbolUsuario *arbolUsuario);
void buscarYMostrarUsuarioAdmin(nodoArbolUsuario *arbolUsuario);
void bajaAltaAdmin(nodoArbolUsuario *arbolUsuario);
void verPerros(nodoArbolUsuario *arbolUsuario);
void convertirAdmin(nodoArbolUsuario *arbolUsuario);

#endif // SUBPROGADMIN_H_INCLUDED
