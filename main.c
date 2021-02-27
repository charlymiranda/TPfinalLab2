#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "portada/Portada.h"
#include "menu/menuGeneral.h"

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "spanish");
    hidecursor(0);

    ///Variables

    nodoArbolUsuario *arbolUsuario;
    inicArbolUsuario(&arbolUsuario);

    nodoListaUsuario *listaUsuario;
    inicListaListaUsuario(&listaUsuario);

    nodoLDLBarrio *LDLBarrio;
    inicLDLBarrio(&LDLBarrio);

    ///Pasar datos a memoria principial
    /////////////////////////////////////////////////////////////

    ///Usuarios
    pasarDeArchivoToMemoriaUsuario(&arbolUsuario);

    ///Veterinarias
    pasarDeArchivoToLDLVeterinaria(&LDLBarrio);

    ///Menu
    /////////////////////////////////////////////////////////////

    portada();
    Sleep(2000);

    menuGeneral(&arbolUsuario, &LDLBarrio);

    ///Pasar datos al archivo
    /////////////////////////////////////////////////////////////

    ///Usuarios
    pasardeArbolUsuarioToListaUsuario(arbolUsuario, &listaUsuario);
    pasarDeListaUsuarioToArchivoUsuario(listaUsuario);

    ///Veterinarias
    pasarDeLDLToArchivoVeterinaria(LDLBarrio);

    clear();
    portada();
    printf("\n\t\t\t                           Saliendo del sistema... ");
    Sleep(2000);
    return 0;
}
