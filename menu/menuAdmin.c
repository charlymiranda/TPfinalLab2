#include "menuAdmin.h"
/*********************************************************//**
*
* \brief Menu administrador
* \param puntero doble usuarioingresado / arbolUsuario / LDLBarrio
* \return
*
***********************************************************/
void menuAdmin(nodoArbolUsuario **usuarioIngresado, nodoArbolUsuario **arbolUsuario, nodoLDLBarrio **LDLBarrio)
{
    char opcion;

    do
    {
        system("cls");

        tituloGeneral();
        color(7);
        gotoxy(44,7);
        color(12);
        printf("    MENU ADMINISTRADOR");
        color(7);
        gotoxy(42,9);
        printf("   ¿Que desea hacer ahora?");

        gotoxy(42,12);
        printf("   1: Administrar Usuarios");
        gotoxy(42,14);
        printf("   2: Administrar Perros");
        gotoxy(42,16);
        printf("   3: Administar Veterinarias");
        gotoxy(42,18);
        printf("   4: Mi perfil");
        gotoxy(45,20);
        color(12);
        printf("   ESC: Cerrar sesion");

        fflush(stdin);
        opcion=getch();

        switch (opcion)
        {
//////////////////////////////////////////////////////////////////////////

        ///MENU USUARIOS
        case 49 :
            do
            {
                clear();



                color(12);
                gotoxy(44,7);
                printf("ADMINISTRAR USUARIOS\n\n");
                color(7);
                gotoxy(42,10);
                printf("1. Ver usuarios\n");
                gotoxy(42,12);
                printf("2. Buscar usuario\n");
                gotoxy(42,14);
                printf("3. Dar de baja/alta usuario\n\n");
                gotoxy(42,16);
                printf("4. Convertir Usuarios\n\n");
                gotoxy(42,18);

                color(12);
                printf("0. Atras");

                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {
                case 49:
                    verUsuarios(*arbolUsuario);/*Ver todos los usuarios en el arbol*/
                    break;

                case 50:
                    buscarYMostrarUsuarioAdmin(*arbolUsuario);/*Buscar y mostrar un solo usuario*/
                    break;

                case 51:
                    bajaAltaAdmin(*arbolUsuario);/*dar de baja o alta a un usuario*/
                    break;

                case 52:
                    convertirAdmin(*arbolUsuario);/*Cambiar el rol de un usuario a daministrador o al reves*/
                    break;
                }
            }
            while(opcion !=48);
            break;

//////////////////////////////////////////////////////////////////////////

        ///MENU PERROS

        case 50:
            verPerros(*arbolUsuario); /*ver todos los perros, primero aparece el usuario y seguido sus perros*/
            break;

//////////////////////////////////////////////////////////////////////////

        ///MENU VETERINARIAS

        case 51:
            do
            {
                clear();



                color(12);
                gotoxy(44,7);
                printf("ADMINISTRAR VETERINARIAS\n");
                printf("\n");
                color(7);
                gotoxy(42,10);
                printf("1. Ver veterinarias\n");
                gotoxy(42,12);
                printf("2. Cargar Veterinaria\n");
                gotoxy(42,14);
                printf("3. Modificar veterinarias\n\n");

                gotoxy(42,16);
                color(12);
                printf("0. Atras");
                color(7);
                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {
                case 49:
                    clear();
                    printf("  VETERINARIAS DE MAR DEL PLATA\n\n");
                    recorrerYMostrarLDLBarrio(*LDLBarrio);/*recorrer la LDL y va mostrando*/
                    pause();
                    break;

                case 50:
                    agregarVeterinaria(LDLBarrio);/*agrega nueva vet */
                    break;

                case 51:
                    ModificarVeterinaria(LDLBarrio);
                    break;
                }
            }
            while(opcion !=48);


            break;

//////////////////////////////////////////////////////////////////////////

        ///Mi perfil

        case 52:
            do
            {
                clear();

                color(12);

                gotoxy(44,7);
                printf("CONFIGURACION DE LA CUENTA\n\n");
                color(7);
                gotoxy(42,10);
                printf("1. Modificar usuario\n");
                gotoxy(42,12);
                printf("2. Modificar perros\n");
                gotoxy(42,14);
                color(12);
                printf("0. Atras\n");
                color(7);
                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {
                case 49:
                    ModificarUsuario(usuarioIngresado);
                    break;

                case 50:
                    modificarPerros(usuarioIngresado);
                    break;
                }
            }
            while(opcion !=48);
            break;

//////////////////////////////////////////////////////////////////////////
        }
    }
    while (opcion != 27);

    clear();
    color(12);
    printf(" CERRANDO SESION...\n\n ");
    color(7);
    pause();
}
