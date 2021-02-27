#ifndef MENUADMIN_H_INCLUDED
#define MENUADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <windows.h>
#include <ctype.h>

#include "../otrasFunciones.h"
#include "../subProgramas/subProgAdmin.h"
#include "../subProgramas/subProgUsuario.h"
#include "../subProgramas/subProgVeterinaria.h"

void menuAdmin(nodoArbolUsuario **usuarioIngresado, nodoArbolUsuario **arbolUsuario,nodoLDLBarrio **lista);

#endif // MENUADMIN_H_INCLUDED
