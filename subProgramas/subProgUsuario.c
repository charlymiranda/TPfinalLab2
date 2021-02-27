#include "subProgUsuario.h"

///Pasar del archivo a la memoria principal (Usuario)
//////////////////////////////////////////////////////////////////////////////////////////

void pasarDeArchivoToMemoriaUsuario(nodoArbolUsuario **arbolUsuario)
{
    int cant=0;

    FILE *bufferUsuario = fopen(arUsuarios, "rb");

    if(bufferUsuario)
    {
        cant=ContarRegistrosUsuario(bufferUsuario, sizeof(stUsuario));/*cuenta los registros del archivo*/

        stUsuario arregloUsuario[cant];

        pasarDeArchivoToArregloUsuario(arregloUsuario, bufferUsuario);/*pasa del archivo a un arreglo*/

        *arbolUsuario=pasarDeArregloToArbolUsuario(*arbolUsuario, arregloUsuario, 0, cant-1);/*pasa del arreglo al arbol*/

        fclose(bufferUsuario);
    }
}

nodoArbolUsuario* pasarDeArregloToArbolUsuario(nodoArbolUsuario *arbolUsuario, stUsuario arregloUsuario[], int ini, int fin)
{
    int medio;

    if(ini <= fin)
    {
        medio=(ini+fin)/2;/*divide siempre el arreglo a la mitad*/

        arbolUsuario=insertarArbolUsuario(arbolUsuario, arregloUsuario[medio]);/*inserta en el arbol */

        arbolUsuario=pasarDeArregloToArbolUsuario(arbolUsuario, arregloUsuario, ini, medio-1); /*se mueve y descuenta uno a la mitad del arreglo */
        arbolUsuario=pasarDeArregloToArbolUsuario(arbolUsuario, arregloUsuario, medio+1, fin);/*suma uno a la mitad*/
    }

    return arbolUsuario;
}
/*aca lo pasamos al arreglo para despues pasarlo al arbol*/
void pasarDeArchivoToArregloUsuario(stUsuario arregloUsuario[], FILE *Buffer)
{
    int i=0;
    stUsuario user;

    while(fread(&user, sizeof(stUsuario), 1, Buffer)>0)
    {
        arregloUsuario[i]=user;
        i++;
    }
}

int ContarRegistrosUsuario(FILE *Buffer, int tstruct)
{
    fseek(Buffer,0,SEEK_END);

    int cant=ftell(Buffer);

    int cantregistros=cant/tstruct;

    fseek(Buffer,0,SEEK_SET);

    return cantregistros;
}


///Administrar Usuarios
//////////////////////////////////////////////////////////////////////////////////////////

///Crear cuenta de usuario
void crearCuentaUsuario(nodoArbolUsuario **arbolUsuario)
{
    stUsuario nuevoUsuario;
    nodoArbolUsuario *buscado=NULL;
    char com='s';

    do
    {
        gotoxy(35,10);
        printf("USUARIO: ");
        fflush(stdin);
        gets(nuevoUsuario.user);

        buscado=buscarArbolUsuario(*arbolUsuario, nuevoUsuario.user);/*lo busca para coomprobar que no haya usuario repetidos*/

        if(buscado)
        {
            printf("El usuario ya existe, ingrese otro usuario. ");
            pause();
        }
    }
    while(buscado);

    nuevoUsuario=cargarUsuario(nuevoUsuario.user);/*si no existe se le pide el resto de los datos y se agrega*/

    printf("Desea cargar un perro? [s/n]: ");
    fflush(stdin);
    scanf("%c", &com);

    int i=0;

    if(com=='s')
    {
        while(com=='s')
        {
            cargarPerro(&nuevoUsuario, i); /*aca se cargan los perros, maximo 20*/
            i++;
            printf("Desea cargar otro perro? [s/n]: ");
            fflush(stdin);
            scanf("%c", &com);
        }

        nuevoUsuario.perrosValidos=i;/*suma los validos del arreglo de perross*/
    }

    *arbolUsuario=insertarArbolUsuario(*arbolUsuario, nuevoUsuario);
}

///Agregar un perro
void agregarPerro(nodoArbolUsuario **usuarioIngresado)
{
    char com='s';


    while(com=='s')
    {
        clear();
        color(7);printf("\n  NUEVO PERRO\n\n");
        color(3);cargarPerro(&(*usuarioIngresado)->dato, (*usuarioIngresado)->dato.perrosValidos);/* recibe el dato del usuaior y los validos(cantidad de perros)*/
        (*usuarioIngresado)->dato.perrosValidos++;
        printf("\n Desea cargar otro perro? [s/n]: ");
        com=getch();
    }
}

///MODIFICAR USUARIO. LO USA TANTO ADMIN COMO USER
void ModificarUsuario(nodoArbolUsuario **usuarioIngresado)
{
    char opcion;

    do
    {
        system("cls");

        color(7);printf("\n  MODIFICAR USUARIO\n\n");

        mostrarUsuarioSinPerro((*usuarioIngresado)->dato);
        color(3);
        printf("\n1. USUARIO");
        printf("\n2. CONTRASEÑA");
        printf("\n3. NOMBRE");
        printf("\n4. APELLIDO");
        printf("\n5. EDAD");
        printf("\n6. DNI");
        printf("\n7. MAIL\n");

        printf("\n0. TERMINAR\n\n");

        opcion=getch();

        switch (opcion)
        {
        case 49:
            printf(" Ingrese nuevo usuario: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.user);
            break;

        case 50:
            printf(" Ingrese nueva contraseña: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.pass);
            break;

        case 51:
            printf(" Ingrese nuevo nombre: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.nombre);
            break;

        case 52:
            printf(" Ingrese nuevo apellido: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.apellido);
            break;

        case 53:
            printf(" Ingrese nueva edad: ");
            scanf("%d", &(*usuarioIngresado)->dato.edad);
            break;

        case 54:
            printf(" Ingrese nuevo dni: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.DNI);
            break;

        case 55:
            printf(" Ingrese nuevo mail: ");
            fflush(stdin);
            gets((*usuarioIngresado)->dato.mail);
            break;
        }

    }
    while(opcion!=48);
}

void modificarPerros(nodoArbolUsuario **usuarioIngresado)/*MODIFICAR LOS DATOS DE UN PERRO*/
{
    char opcion;
    char nombrePerro[20];
    int pos;

    do
    {
        system("cls");

        color(7);printf("\n MODIFICAR PERROS\n\n");
        color(3);
        mostrarPerrosUsuario((*usuarioIngresado)->dato.perro, (*usuarioIngresado)->dato.perrosValidos);

        printf("\n Ingrese el nombre del perro que desea modificar: ");
        fflush(stdin);
        gets(nombrePerro);

        pos=buscarPosPerro((*usuarioIngresado)->dato.perro, nombrePerro, (*usuarioIngresado)->dato.perrosValidos);/*busca la posicion de un perro en el arreglo del usuario*/

        if(pos!=-1)
        {
            do
            {
                clear();
                color(7);
                printf("\n MODIFICAR PERROS\n\n");
                color(3);
                mostrarPerro((*usuarioIngresado)->dato.perro[pos]);

                printf("\n1. NOMBRE");
                printf("\n2. RAZA");
                printf("\n3. DESCRIPCION");
                printf("\n4. PERDIDO");

                printf("\n0. TERMINAR\n\n");

                opcion=getch();

                switch (opcion)
                {
                case 49:
                    printf(" Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets((*usuarioIngresado)->dato.perro[pos].nombrePerro);
                    break;

                case 50:
                    printf(" Ingrese nueva raza: ");
                    fflush(stdin);
                    gets((*usuarioIngresado)->dato.perro[pos].raza);
                    break;

                case 51:
                    printf(" Ingrese nueva descripcion: ");
                    fflush(stdin);
                    gets((*usuarioIngresado)->dato.perro[pos].descripcion);
                    break;

                case 52:
                    printf(" Cambiar estado del perro [1-Perdido/0-Encontrado]: ");
                    fflush(stdin);
                    scanf("%d",&(*usuarioIngresado)->dato.perro[pos].perdido);
                    break;
                }

            }
            while(opcion!=48);

        }
        else
        {
           color(12); printf("\n No se encontro el perro. \n\n\n");
          color(7); pause();
        }

      color(3);  printf("\n\n Desea modificar otro perro? [s/n]: ");
        fflush(stdin);
        opcion=getch();

    }
    while(opcion=='s');

}

int buscarPosPerro(stPerro perros[],char nombrePerro[], int perrosValidos)/*busca la posicion del perro en el arreglo del usaurio*/
    int pos=-1;
    int i=0;

    while(i<perrosValidos && pos==-1)
    {
        if(strcmpi(perros[i].nombrePerro, nombrePerro)==0)
        {
            pos=i;
        }
        i++;
    }

    return pos;
}

int darseDeBaja(nodoArbolUsuario **usuarioIngresado)/*el usuario puede darsede baja*/
{
    char baja;
    char aux;
    int flag=0;

    color(12);printf("\n MENU DE BAJA\n\n\n");

    color(3);printf("\n ¿Desea darse de baja? [s/n]: ");
    fflush(stdin);
    scanf("%c", &aux);

    if(aux=='s')
    {
        color(12);printf("\n\n ¿Esta seguro? Los pequeños cuadrupedos perdidos lo lamentaran. [s/n]: ");/*confimarcion*/
        fflush(stdin);
        scanf("%c", &baja);
    }

    if(baja=='s')
    {
        flag=1;
        (*usuarioIngresado)->dato.alta=0;
    }

    return flag;
}

///Consulta de datos
//////////////////////////////////////////////////////////////////////////////////////////

void mostrarPerrosUsuario(stPerro arregloPerros[], int perrosValidos)
{
    int i=0;

    while(i<perrosValidos)
    {
        mostrarPerro(arregloPerros[i]);
        i++;
    }
}


///Pasar al archivo
//////////////////////////////////////////////////////////////////////////////////////////
void pasardeArbolUsuarioToListaUsuario(nodoArbolUsuario *arbolUsuario, nodoListaUsuario **listaUsuario)
{
    if(arbolUsuario)
    {
        agregarEnOrdenListaUsuario(listaUsuario, crearNodoListaUsuario(arbolUsuario->dato));

        pasardeArbolUsuarioToListaUsuario(arbolUsuario->izq, listaUsuario);

        pasardeArbolUsuarioToListaUsuario(arbolUsuario->der, listaUsuario);
    }
}

void pasarDeListaUsuarioToArchivoUsuario(nodoListaUsuario *listaUsuario)
{
    FILE *bufferUsuario = fopen(arUsuarios, "wb");

    if(bufferUsuario)
    {
        while(listaUsuario)
        {
            fwrite(&listaUsuario->dato, sizeof(stUsuario),1,bufferUsuario);

            listaUsuario=listaUsuario->siguiente;
        }

        fclose(bufferUsuario);
    }
}
