#include "menuGeneral.h"

///Menu general
//////////////////////////////////////////////////////////////////////////////


void menuGeneral(nodoArbolUsuario **arbolUsuario, nodoLDLBarrio **LDLBarrio)
{
    ///Variables
    //////////////////////////////
    int cont=1;
    char opcion;
    int rol;
    int i=0;

    char user[20];
    char pass[20];
    char caracter;

    nodoArbolUsuario *usuarioIngresado=NULL;/*crea un nodoArbolUsuario para trabajar*/

    //////////////////////////////

    do
    {
        clear();


        tituloPrincipal();
 /*pide los datos al usuario*/
        color(7);
        gotoxy(48,13);
        printf(" MENU INICIO");
        gotoxy(39,16);
        color(3);
        printf("1. Ingresar con cuenta existente.\n");
        gotoxy(39,18);
        printf("2. Crear una cuenta nueva.\n");
        gotoxy(39,20) ;
        printf("ESC. Salir\n");

        fflush(stdin);
        opcion=getch();

        switch(opcion)
        {
        case 49:

            clear();
            cont=3;

            do
            {
                clear();

                gotoxy(35,6);
                color(3);
                printf("Ingrese usuario y contraseña" );
                gotoxy(64,6);
                color(12);
                printf("Le quedan %d intentos.", cont);

                gotoxy(35,8);
                color(3);
                printf("USUARIO: ");
                color(7);
                fflush(stdin);
                gets(user);

                gotoxy(35,10);
                color(3);
                printf("CONTRASEÑA: ");
                color(7);
                fflush(stdin);

                i=0;
                  /*con esto no aparecen las letrar al poner la contrasenia*/
                while ((caracter = getch()))
                {
                    if (caracter == 13)
                    {
                        pass[i] = '\0';
                        break;
                    }
                    else if (caracter == 8)
                    {
                        if (i > 0)
                        {
                            i--;
                            printf("\b \b");
                        }
                    }
                    else
                    {
                        if (i < 20)
                        {
                            printf("*");
                            pass[i] = caracter;
                            i++;
                        }
                    }
                }

                usuarioIngresado=buscarArbolUsuarioConPass(*arbolUsuario, user, pass);/*retorna los datos*/

                if(!usuarioIngresado)/*si no existe el user*/
                {
                    gotoxy(35,14);
                    color(12);
                    printf("EL USUARIO O LA CONTRASEÑA NO COINCIDEN");
                    gotoxy(35,16);
                    color(12);
                    printf("POR FAVOR VUELVA A INGRESAR LOS DATOS.");
                    gotoxy(35,22);
                    color(7);
                    pause();
                }

                cont--;
            }
            while(!usuarioIngresado && cont>0);

            if(usuarioIngresado)
            {
                rol=usuarioIngresado->dato.rol;/*se lee el rol y lo manda al menu correspondiente*/
            }

            switch(rol)
            {

            ///Usuario
            case 1:
                printf("usuario");
                menuUsuario(&usuarioIngresado, LDLBarrio);
                break;

            ///Administrador
            case 2:
                printf("admin");
                menuAdmin(&usuarioIngresado,arbolUsuario, LDLBarrio);
                break;

            default:
                clear();
                gotoxy(28,6);
                color(7);
                printf("HA ALCANZADO EL MAXIMO DE INTENTOS PERMITIDOS, VUELVA A INGRESAR. ");
                gotoxy(40,22);
                color(7);
                pause();
            }

            break;

        case 50:
            clear();


            gotoxy(35,4);
            color(7);
            printf("CREACION DE CUENTA\n\n");
            gotoxy(35,8);
            color(3);
            printf("Ingrese datos de su cuenta:\n\n");
            crearCuentaUsuario(arbolUsuario);/*crea una cuenta*/
            printf("\n\n");
            pause();
            break;
        }
    }
    while(opcion !=27);
}



