#include "menuUsuario.h"
/*********************************************************//**
*
* \brief menu para el usuario
* \param puntero doble del arbol / puntero doble del LDLBario
* \return user
*
***********************************************************/
void menuUsuario(nodoArbolUsuario **usuarioIngresado, nodoLDLBarrio **LDLBarrio)

{
    char opcion;
    char opcion2;
    int flag;

    do
    {
        system("cls");

        tituloGeneral();

        color(7);

        color(7);
        gotoxy(48,7);
        printf(" MENU USUARIOS");
        color(3);

        gotoxy(33,10);
        printf("    1. Perridos");

        gotoxy(33,12);
        printf("    2. Veterinarias");

        gotoxy(33,14);
        printf("    3. Configuracion de la cuenta");

        gotoxy(33,16);
        printf("    ESC. Cerrar sesion");

        fflush(stdin);
        opcion2=getch();

        switch (opcion2)
        {

//////////////////////////////////////////////////////////////////////////

        ///MENU PERRIDOS

        case 49 :

            do
            {
                clear();

                tituloGeneral();
                color(7);

                gotoxy(48,7);
                printf("MENU PERRIDOS\n");
                color(3);
                gotoxy(48,10);
                printf("1. Escanear\n");
                gotoxy(48,12);
                printf("2. Mis Perros\n");
                gotoxy(48,14);
                printf("3. Nuevo perro\n\n");

                gotoxy(48,16);
                printf("0. Volver");

                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {
                case 49:
                    system("cls");

                    escaner();

                    gotoxy(35,25);
                    color(7);
                    pause();

                    break;

                case 50:
                    clear();
                    color(7);printf("\t   MIS PERROS\n\n");
                    color(3);mostrarPerrosUsuario((*usuarioIngresado)->dato.perro, (*usuarioIngresado)->dato.perrosValidos);
                    color(7);/*muestra los perros solo del usuario que esta logueado*/
                    pause();
                    break;

                case 51:

                    agregarPerro(usuarioIngresado);/*genera un nuevo perro*/
                    break;
                }
            }
            while(opcion !=48);

            break;

//////////////////////////////////////////////////////////////////////////

        ///MENU VETERINARIA

        case 50:
            do
            {
                clear();

                tituloGeneral();
                color(7);

                gotoxy(46,7);
                printf("MENU VETERINARIAS\n\n");
                color(3);
                gotoxy(38,10);
                printf("1. Ver todas las veterinarias\n");
                gotoxy(38,12);
                printf("2. Buscar veterinarias por barrio\n");
                gotoxy(38,14);
                printf("3. Buscar veterinarias por nombre\n\n");

                gotoxy(38,16);
                printf("0. Volver");

                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {

                case 49:
                    clear();
                    color(7);printf("\t    VETERINARIAS DE MAR DEL PLATA\n\n");
                    color(3);recorrerYMostrarLDLBarrio(*LDLBarrio);/*recorre la lista de lista y va mostrando las veterinarias*/
                    color(7);pause();
                    break;

                case 50:
                    buscarVeterinariaPorBarrio(*LDLBarrio);/*busca las vet por barrio y las muestra*/
                    break;

                case 51:
                    buscarVeterinariaPorNombre(*LDLBarrio);/*busca vet por nombre*/
                    break;
                }
            }
            while(opcion !=48);
            break;

//////////////////////////////////////////////////////////////////////////

        ///MENU CONFIGURACION

        case 51:
            do
            {
                clear();


                tituloGeneral();
                color(7);

                gotoxy(43,7);
                printf("CONFIGURACION DE LA CUENTA\n\n");
                color(3);
                gotoxy(42,10);
                printf("1. Modificar usuario\n");
                gotoxy(42,12);
                printf("2. Modificar perros\n");
                gotoxy(42,14);
                printf("3. Darse de baja\n\n");

                gotoxy(42,16);
                printf("0. Atras\n");

                fflush(stdin);
                opcion=getch();

                switch(opcion)
                {
                case 49:
                    ModificarUsuario(usuarioIngresado);/*modifica sus datos*/
                    break;

                case 50:
                    modificarPerros(usuarioIngresado);/*modifica sus perros*/
                    break;

                case 51:
                    clear();
                    flag=darseDeBaja(usuarioIngresado);

                    if(flag)
                    {
                        opcion=48;
                        opcion2=27;
                    }
                    break;
                }
            }
            while(opcion !=48);

            break;

//////////////////////////////////////////////////////////////////////////
        }
    }
    while (opcion2 != 27);

    clear();
    printf("\n CERRANDO SESION... \n\n");
   color(7); pause();

}
