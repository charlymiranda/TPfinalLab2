#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

typedef struct
{
    int id;
    char nombrePerro[50];
    char raza[50];
    char descripcion[50];
    int perdido; //1-si 0-no
} stPerro;

typedef struct
{
    char user[50];
    char pass[50];
    char nombre[50];
    char apellido[50];
    int edad;
    char DNI[50];
    char mail[50];
    stPerro perro[20]; //Mamixo 20 Perros por persona
    int perrosValidos;
    int alta;//1 activo - 0 inactivo
    int rol; //1-Usuario 2-Admin
} stUsuario;

stUsuario cargarUsuario();
void mostrarUsuario(stUsuario dato);
void cargarPerro(stUsuario *user, int i);
void mostrarPerro(stPerro perro);
void mostrarUsuarioSinPerro(stUsuario dato);


#endif // USUARIO_H_INCLUDED
