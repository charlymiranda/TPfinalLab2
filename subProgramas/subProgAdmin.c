#include "subProgAdmin.h"
/*********************************************************//**
*
* \brief mostrar usuariios
* \param ele arbol de los usuarios
* \return
*
***********************************************************/
void verUsuarios(nodoArbolUsuario *arbolUsuario)
{
    char opcion;

    do
    {
        clear();

        color(12);
        gotoxy(44,7);

        printf("VER USUARIOS\n\n");
        color(7);
        gotoxy(42,10);
        printf("1. Usuarios Activos\n");
        gotoxy(42,12);
        printf("2. Usuarios Inactivos\n");
        color(12);
        gotoxy(42,14);
        printf("0.Atras");
        color(7);
        fflush(stdin);
        opcion=getch();

        switch(opcion)
        {
        case 49:
            clear();
            color(12);
            printf(" LISTA DE USUARIOS ACTIVOS\n\n");
            color(7);
            preorderUsuarioFiltro(arbolUsuario, 1);
            pause();

            break;
        case 50:
            clear();
            color(12);
            printf(" LISTA DE USUARIOS INACTIVOS\n\n");
            color(7);
            preorderUsuarioFiltro(arbolUsuario, 0);
            pause();
            break;
        }
    }
    while(opcion!=48);
}


void verPerros(nodoArbolUsuario *arbolUsuario)
{
    char opcion;

    do
    {
        clear();




        color(12);
        gotoxy(44,7);
        printf("VER PERROS\n\n");
        color(7);
        gotoxy(42,10);
        printf("1. Perros Con sus dueños\n");
        gotoxy(42,12);
        printf("2. Perridos\n");
        color(12);
        gotoxy(42,14);
        printf("0. Atrás");
        color(7);
        fflush(stdin);
        opcion=getch();

        switch(opcion)
        {
        case 49:
            clear();
            printf("Perros Con sus dueños\n\n");
            preorderUsuarioFiltroPerros(arbolUsuario, 0);/**/
            pause();

            break;
        case 50:
            clear();
            printf("Perridos\n\n");
            preorderUsuarioFiltroPerros(arbolUsuario, 1);
            pause();
            break;
        }
    }
    while(opcion!=48);
}

void buscarYMostrarUsuarioAdmin(nodoArbolUsuario *arbolUsuario)
{
    char com;
    char user[50];

    do
    {
        clear();
        color(12);
        gotoxy(44,7);
        printf(" BUSCAR USUARIOS\n\n");
        color(7);
        gotoxy(42,10);
        printf(" Ingrese usuario a buscar: ");
        fflush(stdin);
        gets(user);
        nodoArbolUsuario *buscado=buscarArbolUsuario(arbolUsuario, user);
        if(buscado)
        {
            printf("\n");

            mostrarUsuario(buscado->dato);
        }
        else
        {
            color(12);
            printf("\n El usuario no existe.\n\n");
        }
        color(7);
        printf("Desea buscar a otro usuario? [s/n]: ");
        scanf("%c", &com);
    }
    while(com=='s');
}

void bajaAltaAdmin(nodoArbolUsuario *arbolUsuario)
{
    char com;
    char user[50];

    do
    {
        clear();

        color(12);
        gotoxy(44,7);
        printf("BAJAS DE USUARIOS\n\n");
        color(7);
        gotoxy(42,10);

        printf("Ingrese usuario a buscar: ");
        fflush(stdin);
        gets(user);

        nodoArbolUsuario *buscado=buscarArbolUsuario(arbolUsuario, user);

        if(buscado)
        {

            mostrarUsuario(buscado->dato);

            if(buscado->dato.alta)
            {
                color(7);
                printf("\n Desea darlo de baja?[s/n]: ");

                fflush(stdin);
                scanf("%c", &com);

                if(com=='s')
                {
                    buscado->dato.alta=0;
                    color(12);
                    printf("\n El usuario se ha dado de baja.\n");
                }
            }
            else
            {
                color(7);
                printf("\n Desea darlo de alta?[s/n]: ");

                fflush(stdin);
                scanf("%c", &com);

                if(com=='s')
                {
                    buscado->dato.alta=1;
                    color(3);
                    printf("\n El usuario se ha dado de alta.\n");
                }
            }
        }
        else
        {
            color(12);
            printf("\n El usuario no existe.\n\n");
        }

        printf("\n Desea dar de baja otro usuario [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
    while(com=='s');
}

void convertirAdmin(nodoArbolUsuario *arbolUsuario)
{

    char com;
    char user[50];

    do
    {
        clear();

        color(12);
        gotoxy(44,7);
        printf("NUEVO ADMIN\n\n");
        color(7);
        gotoxy(42,10);

        printf("Ingrese usuario a convertir: ");
        fflush(stdin);
        gets(user);

        nodoArbolUsuario *buscado=buscarArbolUsuario(arbolUsuario, user);

        if(buscado)
        {

            mostrarUsuario(buscado->dato);

            if(buscado->dato.rol == 1)
            {
                color(7);
                printf("\n Desea volverlo administrador?[s/n]: ");

                fflush(stdin);
                scanf("%c", &com);

                if(com=='s')
                {
                    buscado->dato.rol=2;
                    color(12);
                    printf("\n El usuario se ha vuelto administrador.\n");
                }
            }
            else
            {
                color(7);
                printf("\n Desea volverlo Usuario Normal?[s/n]: ");

                fflush(stdin);
                scanf("%c", &com);

                if(com=='s')
                {
                    buscado->dato.rol=1;
                    color(3);
                    printf("\n El usuario se ha vuelto Usuario normal.\n");
                }
            }
        }
        else
        {
            color(12);
            printf("\n El usuario no existe.\n\n");
        }

        printf("\n Desea convertir otro usuario [s/n]: ");
        fflush(stdin);
        scanf("%c", &com);
    }
    while(com=='s');
}


