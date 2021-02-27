#include "otrasFunciones.h"

///Otras
//////////////////////////////////////////////////////////////////////////////
///Esconder cursor
void hidecursor(int ver)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = ver;
    SetConsoleCursorInfo(consoleHandle, &info);
}

///Pausa
void pause()
{
    printf("Presione una tecla para continuar...");
    system("pause > NULL");
}

///Limpiar Consola
void clear()
{
    system("cls");
}

void color(int x)                                                               /// Cambia la combinacion de color de fondo y frente
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y)                                                        /// Cambia las coordenadas del cursor
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=X;
    dwPos.Y=Y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int whereX()                                                                      /// Devuelve la posicion de X
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY()                                                                    /// Devuelve la posicion de Y
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void tituloPrincipal()
{

    gotoxy(20,2);
    color(12);
    printf("///******************************************************************\\\\\\ ");
    gotoxy(36,3);

    color(7 );
    printf("   PROJECTO DE LABORATORIO 2 COMISION 8 ");
    gotoxy(37,5);
    color(3);
    printf("  PERRIDOS  ");
    color(7);
    gotoxy(47,5);
    printf(" \"Una APP para encontrarse\" ");
    gotoxy(43,7);
    color(7);
    printf(" Profesor Sonvico, Gustavo");
    gotoxy(27,9);
    printf("    LOS EMULADORES |  Fabrizio - Jaime - Miranda - Suarez ");
    gotoxy(20,10);
    color(12);
    printf("\\\\\\******************************************************************///");
    color(3);
}


void tituloGeneral()
{

    gotoxy(20,2);
    color(12);
    printf("///******************************************************************\\\\\\ ");

    gotoxy(37,3);
    color(3);
    printf("  PERRIDOS  ");
    color(7);
    gotoxy(47,3);
    printf(" \"Una APP para encontrarse\" ");


    gotoxy(20,4);
    color(12);
    printf("\\\\\\******************************************************************///");
    color(3);
}


void escaner()
{
    color(3);



    bli0();
    color(7);
    bli1();
    bli2();
    bli3();

    bli4();
    bli5();
    bli6();

    bli7();
    bli8();



    usuario();

    datos();

    color(3);

}




void bli0 ()
{
    int j;
    color(3);
    gotoxy(54,1);
    char sign[]="ESCANEANDO ";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(45);
        printf("%c", sign[j]);
    }

}


void bli1 ()
{
    int j;
    color(7);
    gotoxy(54,3);
    char sign[]="@@@@@@@@@ ";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(45);
        printf("%c", sign[j]);
    }

}

void bli2 ()
{
    int j;
    color(7);
    gotoxy(51,4);
    char sign[]="@@@@@@@@@@@@@@@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(40);
        printf("%c", sign[j]);
    }

}

void bli3 ()
{
    int j;
    color(7);
    gotoxy(50,5);
    char sign[]="@@@  @@@@@@@  @@@ ";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(30);
        printf("%c", sign[j]);
    }

}

void bli4 ()
{
    int j;
    color(7);
    gotoxy(50,6);
    char sign[]="@@    @@@@@    @@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(30);
        printf("%c", sign[j]);
    }

}

void bli5 ()
{
    int j;
    color(7);
    gotoxy(55,7);
    char sign[]="@@@@@@@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(25);
        printf("%c", sign[j]);
    }

}

void bli6 ()
{
    int j;
    color(7);
    gotoxy(50,8);
    char sign[]=" @@@@@@@ @@@@@@@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(25);
        printf("%c", sign[j]);
    }

}

void bli7 ()
{
    int j;
    color(7);
    gotoxy(53,9);
    char sign[]="@@@@@ @@@@@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(20);
        printf("%c", sign[j]);
    }

}

void bli8 ()
{
    int j;
    color(7);
    gotoxy(56,10);
    char sign[]="@@ @@";


    for(j=0; j<=strlen(sign); j++)
    {
        Sleep(20);
        printf("%c", sign[j]);
    }

}




void usuario()
{

    color(12);
    gotoxy(45,12);
    printf(" USUARIO: \n");
    color(12);
    gotoxy(44,13);
    printf("  NOMBRE: \n");
    color(12);
    gotoxy(46,14);
    printf("APELLIDO: \n");
    color(12);
    gotoxy(42,15);
    printf("    EDAD: \n");
    color(12);
    gotoxy(41,16);
    printf("     DNI: \n");
    color(12);
    gotoxy(42,17);
    printf("    MAIL: \n");
    color(12);
    gotoxy(50,18);
    printf("---------------");
    color(12);
    gotoxy(50,19);
    printf("ID Perro: \n");
    color(12);
    gotoxy(50,20);
    printf("Nombre: \n");
    color(12);
    gotoxy(50,21);
    printf("Raza: \n");
    color(12);
    gotoxy(50,22);
    printf("Descripcion: \n");




}


void datos()
{



    color(3);
    gotoxy(55,12);
    printf(" GSonvico \n");

    color(3);
    gotoxy(54,13);
    printf("  Gustavo ");
    color(3);
    gotoxy(56,14);
    printf("Sonvico \n");
    color(3);
    gotoxy(52,15);
    printf("    35 \n");
    color(3);
    gotoxy(51,16);
    printf("     31852963 \n");
    color(3);
    gotoxy(52,17);
    printf("    Gsonvico@gmail.com \n");
    color(3);
    gotoxy(50,18);
    printf("---------------");
    color(3);
    gotoxy(62,19);
    printf(" 1913216548");
    color(3);
    gotoxy(63,20);
    printf("El Enzo");
    color(3);
    gotoxy(63,21);
    printf("Mestizo \n");
    color(3);
    gotoxy(62,22);
    printf(" le dicen El Principe \n");





}





