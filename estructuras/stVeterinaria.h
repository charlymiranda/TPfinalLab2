#ifndef STVETERINARIA_H_INCLUDED
#define STVETERINARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

typedef struct
{
    int id;
    char nombre[50];
    char telefono[50];
    char direccion[50];
} stVeterinaria;

stVeterinaria cargarVeterinaria();
void mostrarVeterinaria(stVeterinaria vet);

#endif // STVETERINARIA_H_INCLUDED
