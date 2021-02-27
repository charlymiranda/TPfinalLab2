#include "subProgVeterinaria.h"

void agregarVeterinaria(nodoLDLBarrio **lDLBarrios)
{
    char barrio[20];
    char com='s';

    while(com=='s')
    {
        clear();
        color(12);printf("\n  CARGA DE VETERINARIAS\n\n");

        color(7);printf("  Ingrese barrio: ");
        fflush(stdin);
        gets(barrio);

        printf("\n  Ingrese datos de la veterinaria: \n");

        altaLDLBarrio(lDLBarrios, crearNodoListaVeterinaria(cargarVeterinaria()), barrio);

        printf("\n  Desea ingresar otra veterinaria? [s/n]");
        fflush(stdin);
        com=getch();
    }
}
/*pasa veterinarias al LDLlistaVeterinaria*/
void pasarDeArchivoToLDLVeterinaria(nodoLDLBarrio **LDLBarrio)
{
    FILE *buffer = fopen(arVeterinarias, "rb");
    registroVeterinaria aux;/*registro del archivo*/
    stVeterinaria nuevaVeterinaria;/*structura de la lista simple veterinaria*/

    if(buffer)
    {
        while(fread(&aux, sizeof(registroVeterinaria),1,buffer)>0)/*mientras haya registros en el archivo copia los datos a la estructura correspondiente*/
        {
            nuevaVeterinaria.id=aux.id;
            strcpy(nuevaVeterinaria.direccion, aux.direccion);/**/
            strcpy(nuevaVeterinaria.nombre, aux.nombre);
            strcpy(nuevaVeterinaria.telefono, aux.telefono);

            altaLDLBarrio(LDLBarrio, crearNodoListaVeterinaria(nuevaVeterinaria), aux.barrio);
        }

        fclose(buffer);
    }
}
/*pasar las vet al archivo*/
void pasarDeLDLToArchivoVeterinaria(nodoLDLBarrio *LDLBarrio)
{
    FILE *buffer = fopen(arVeterinarias, "wb");
    nodoLDLBarrio *segBarrios=LDLBarrio;
    nodoListaVeterinaria *segLista=NULL;

    registroVeterinaria aux;

    if(buffer)
    {
        while(segBarrios)
        {
            segLista=segBarrios->listaVeterinaria;

            strcpy(aux.barrio,segBarrios->barrio);

            while(segLista)
            {
                strcpy(aux.direccion, segLista->dato.direccion);
                strcpy(aux.telefono, segLista->dato.telefono);
                strcpy(aux.nombre, segLista->dato.nombre);

                fwrite(&aux, sizeof(registroVeterinaria), 1, buffer);

                segLista=segLista->siguiente;
            }

            segBarrios=segBarrios->siguiente;
        }

        fclose(buffer);
    }
}
/*buscar vet en la LDLListaBarrio*/
nodoListaVeterinaria *buscarVeterinaria(nodoLDLBarrio *LDLBarrio, char nombreVet[])
{
    nodoListaVeterinaria *seg;
    nodoListaVeterinaria *buscada=NULL;

    while(LDLBarrio)
    {
        seg=LDLBarrio->listaVeterinaria;

        while(seg)
        {
            if(strcmpi(seg->dato.nombre, nombreVet)==0)
            {
                buscada=seg;
            }

            seg=seg->siguiente;
        }

        LDLBarrio=LDLBarrio->siguiente;
    }

    return buscada;
}

void ModificarVeterinaria(nodoLDLBarrio **LDLBarrio)
{
    char opcion;
    char com;
    char nombreVet[50];

    do
    {
        clear();

        color(12);printf("\n  MODIFICAR VETERINARIAS\n\n");

        color(7); printf(" Ingrese el nombre de la veterinaria: ");
        fflush(stdin);
        gets(nombreVet);

        nodoListaVeterinaria *vetBuscada=buscarVeterinaria(*LDLBarrio,nombreVet);

        if(vetBuscada)
        {
            do
            {
                clear();

                color(12);printf("MODIFICAR VETERINARIA\n");
            color(7);
                mostrarVeterinaria(vetBuscada->dato);

              color(7);  printf("\n1. NOMBRE");
                printf("\n2. TELEFONO");

                printf("\n0. TERMINAR\n\n");

                opcion=getch();

                switch (opcion)
                {
                case 49:
                    printf(" Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(vetBuscada->dato.nombre);
                    break;

                case 50:
                    printf(" Ingrese nuevo telefono: ");
                    fflush(stdin);
                    gets(vetBuscada->dato.telefono);
                    break;
                }
            }
            while(opcion!=48);
        }
        else
        {
       color(12);    printf("\n La veterinaria no existe. ");
            pause();
        }

        color(7);printf("\n\n  Desea modificar otra veterinaria? [s/n]: ");
        com=getch();
    }
    while(com=='s');
}

void buscarVeterinariaPorNombre(nodoLDLBarrio *LDLBarrio)
{
    char nombreVet[50];
    char opcion;

    do
    {
        clear();
         color(7);printf("\n    VETERINARIAS POR NOMBRE\n\n");
       color(3); printf("    Ingrese el nombre de la veterinaria: ");
        fflush(stdin);
        gets(nombreVet);
        nodoListaVeterinaria *vetBuscada=buscarVeterinaria(LDLBarrio,nombreVet);
        if(vetBuscada)
        {
            mostrarVeterinaria(vetBuscada->dato);
            printf("\n");
          gotoxy(38,11);   color(7);  pause();
        }
        else
        {
           color(12); printf("\n    La veterinaria no existe. ");
           gotoxy(38,7);   color(7); pause();
        }

        color(3); printf("\n\n    Desea buscar otra veterinaria? [s/n] ");

        fflush(stdin);
        opcion=getch();

    }
    while(opcion=='s');
}

void buscarVeterinariaPorBarrio(nodoLDLBarrio *LDLBarrio)
{
    char barrio[50];
    char opcion;

    do
    {
        clear();
        color(7);printf("\n    VETERINARIAS POR BARRIO\n\n");
        color(3);printf("    Ingrese el barrio: ");
        fflush(stdin);
        gets(barrio);
        nodoLDLBarrio *barrioBuscado=buscarLDLBarrio(LDLBarrio, barrio);
        if(barrioBuscado)
        {
            mostrarListaVeterinaria(barrioBuscado->listaVeterinaria);

        }
        else
        {
            color(12);printf("\n    El barrio no contiene veterinarias. ");
          gotoxy(38,7);   color(7);pause("\t");


        }
        color(3);printf("\n\n    Desea buscar otro barrio? [s/n] ");

        fflush(stdin);
        opcion=getch();

    }
    while(opcion=='s');
}
