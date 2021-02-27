#ifndef SUBPROGVETERINARIA_H_INCLUDED
#define SUBPROGVETERINARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "../TDA/listaSimpleVeterinaria.h"
#include "../TDA/listaDeListasVeterinaria.h"
#include "../otrasFunciones.h"

#define arVeterinarias "arVeterinarias.dat"

typedef struct
{
    int id;
    char nombre[50];
    char direccion[50];
    char telefono[50];
    char barrio[50];
} registroVeterinaria;

void agregarVeterinaria(nodoLDLBarrio **lDLBarrios);
void pasarDeArchivoToLDLVeterinaria(nodoLDLBarrio **LDLBarrio);
void pasarDeLDLToArchivoVeterinaria(nodoLDLBarrio *LDLBarrio);
nodoListaVeterinaria *buscarVeterinaria(nodoLDLBarrio *LDLBarrio, char nombreVet[]);
void ModificarVeterinaria(nodoLDLBarrio **LDLBarrio);
void buscarVeterinariaPorBarrio(nodoLDLBarrio *LDLBarrio);
void buscarVeterinariaPorNombre(nodoLDLBarrio *LDLBarrio);

#endif // SUBPROGVETERINARIA_H_INCLUDED
