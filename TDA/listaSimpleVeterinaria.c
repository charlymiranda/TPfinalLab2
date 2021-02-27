#include "listaSimpleVeterinaria.h"

///INICIALIZAR LA LISTA
////////////////////////////////////////////////////////
void inicListaVeterinaria(nodoListaVeterinaria **pLista)
{
    //Se asigna a la lista NULL porque no apunta a ningun nodoListaVeterinaria
    *pLista=NULL;
}

///CREAR UN nodoListaVeterinaria Y RETORNARLO
////////////////////////////////////////////////////////
nodoListaVeterinaria *crearNodoListaVeterinaria(stVeterinaria dato)
{
    //Crear un puntero de tipo nodoListaVeterinaria
    nodoListaVeterinaria *nuevo = (nodoListaVeterinaria*)malloc(sizeof(nodoListaVeterinaria));

    //Se le asigna el nuevo dato
    nuevo->dato = dato;

    //Y como es un unico nodoListaVeterinaria el siguiente es NULL
    nuevo->siguiente = NULL;

    //Se retorna
    return nuevo;
}

///AGREGAR nodoListaVeterinariaS AL PRINCIPIO
////////////////////////////////////////////////////////
void agregarPpioListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria)
{
    //Verificamos que la lista este vacia para agregar el nuevo nodoListaVeterinaria al principio
    if(*pLista == NULL)
    {
        *pLista = nuevonodoListaVeterinaria;
    }
    else
    {
        //Se enlaza por siguiente el nodoListaVeterinaria que estaba al principio
        nuevonodoListaVeterinaria->siguiente = *pLista;

        //Se le asigna a la lista el nuevo nodoListaVeterinaria para que se posicione al principio
        *pLista = nuevonodoListaVeterinaria;
    }
}

///MOSTRAR UN nodoListaVeterinaria
////////////////////////////////////////////////////////
void mostrarNodoListaVeterinaria(nodoListaVeterinaria *aux)
{
    //printf("\n%p ---> Siguiente: %p\n", aux, aux->siguiente);
    mostrarVeterinaria(aux->dato);
}

///MOSTRAR UNA LISTA
////////////////////////////////////////////////////////
void mostrarListaVeterinaria(nodoListaVeterinaria *pLista)
{
    nodoListaVeterinaria *seg = pLista;

    while(seg)
    {
        mostrarNodoListaVeterinaria(seg);
        seg=seg->siguiente;
    }
}

///BUSCAR ULTIMO
////////////////////////////////////////////////////////
nodoListaVeterinaria *buscarUltimoListaVeterinaria(nodoListaVeterinaria *pLista)
{
    //En caso de puntero doble se baja a otra variable para no modificar la lista
    nodoListaVeterinaria *seg=pLista;

    //Se trabaja si hay nodoListaVeterinarias en la lista
    if(seg!=NULL)
    {
        //se recorre la lista mientras que el nodoListaVeterinaria no apunte a NULL, cuando el nodoListaVeterinaria apunte a NULL corta porque es el ultimo nodoListaVeterinaria de la lista
        while(seg->siguiente !=NULL)
        {
            //Se recorre de esta manera
            seg=seg->siguiente;
        }
    }

    //Retornamos el ultimo nodoListaVeterinaria
    return seg;
}

///AGREGAR AL FINAL (UTILIZA BUSCAR ULTIMO)
////////////////////////////////////////////////////////
void agregarFinalListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria)
{
    //Si la lista esta vacia, el nodoListaVeterinaria se enlaza con la lista
    if(*pLista == NULL)
    {
        *pLista = nuevonodoListaVeterinaria;
    }
    else
    {
        //se busca al ultimo nodoListaVeterinaria
        nodoListaVeterinaria *ultimo=buscarUltimoListaVeterinaria(*pLista);

        //y se enlaza al ultimo nodoListaVeterinaria por siguiente al nuevo nodoListaVeterinaria.
        ultimo->siguiente=nuevonodoListaVeterinaria;
    }

}

///BUSCAR nodoListaVeterinaria
////////////////////////////////////////////////////////
nodoListaVeterinaria *buscarNodoListaVeterinaria(nodoListaVeterinaria **pLista, char nombre[])
{
    nodoListaVeterinaria *seg=*pLista;

    //Se recorre la lista mientras esta no este vacia, o el dato no coincida, cuando quede vacia o encontremos el dato, corta
    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }

    //Retornamos el nodoListaVeterinaria buscado
    return seg;
}

///BORRAR nodoListaVeterinaria
////////////////////////////////////////////////////////
void borrarNodoListaVeterinaria(nodoListaVeterinaria **pLista, char nombre[])
{
    //Se trabaja si la lista no esta vacia.
    if(*pLista!=NULL)
    {
        ///1.SI EL nodoListaVeterinaria ES EL PRIMERO: Se compara con el primer nodoListaVeterinaria de la lista, si es igual al dato a borrar, lo borra y termina.
        if((strcmp(nombre, (*pLista)->dato.nombre)==0))
        {
            //Se baja el nodoListaVeterinaria a una variable para no perder la direccion de memoria y poder borrarlo
            nodoListaVeterinaria *aBorrar=*pLista;

            //Se saltea ese nodoListaVeterinaria, ahora lista apunta al siguiente nodoListaVeterinaria
            *pLista=(*pLista)->siguiente;

            //Borramos el nodoListaVeterinaria deseado
            free(aBorrar);
        }
        ///2.SI EL nodoListaVeterinaria ESTA EN EL MEDIO O ES EL ULTIMO
        else
        {
            //bajamos la lista a una variable para no modificarla
            nodoListaVeterinaria *seg=*pLista;
            nodoListaVeterinaria *ante;

            //recorremos la lista mientras que no este vacia y el dato sea dinstino al que queremos borrar
            while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
            {
                //se le asigna a ante el nodoListaVeterinaria actual
                ante=seg;

                //seg avanza un nodoListaVeterinaria
                seg=seg->siguiente;
            }

            //verificamos si encontramos el dato
            if(seg!=NULL)
            {
                //ante es el anterior del que queiro borrar y lo apunto al siguiente del que quiero borrar
                //Salteo el nodoListaVeterinaria que quiero eliminar
                ante->siguiente=seg->siguiente;

                //eliminamos el nodoListaVeterinaria seg==aborrar
                free(seg);
            }
        }
    }
}

///AGREGAR EN ORDEN
////////////////////////////////////////////////////////
void agregarEnOrdenListaVeterinaria(nodoListaVeterinaria **pLista, nodoListaVeterinaria *nuevonodoListaVeterinaria)
{
    //Si la lista esta vacia, el nodoListaVeterinaria se agrega al principio
    if(*pLista==NULL)
    {
        *pLista = nuevonodoListaVeterinaria;
    }
    else
    {
        //si el nodoListaVeterinaria que queremos agregar es menor al primer nodoListaVeterinaria, lo agregamos al principio
        if(nuevonodoListaVeterinaria->dato.id < (*pLista)->dato.id)
        {
            agregarPpioListaVeterinaria(pLista, nuevonodoListaVeterinaria);
        }
        else
        {
            nodoListaVeterinaria *seg = (*pLista)->siguiente;
            nodoListaVeterinaria *ante = *pLista;

            //buscamos el lugar del dato que queremos insertar, se recorre la lista mientras esta no este vacia yy el dato a insertar sea mayor
            while(seg!=NULL && nuevonodoListaVeterinaria->dato.id > seg->dato.id)
            {
                //guardamos el actual en una varaible
                ante=seg;

                //avanzamos en la lista
                seg=seg->siguiente;
            }

            //insertamos el nuevo nodoListaVeterinaria en el lugar indicado

            //el anterior apunta al nuevo nodoListaVeterinaria
            ante->siguiente = nuevonodoListaVeterinaria;

            //el nuevo nodoListaVeterinaria apunta al siguiente
            nuevonodoListaVeterinaria->siguiente = seg;
        }
    }
}

///BORRAR TODA LA LISTA
////////////////////////////////////////////////////////
void borrarTodaLaListaVeterinaria(nodoListaVeterinaria **pLista)
{
    nodoListaVeterinaria *aux;

    //Se va recorriendo y borrando mientras que la lista no este vacia
    while(*pLista!=NULL)
    {
        //guardo el nodoListaVeterinaria siguiente al que se va a borrar
        aux = (*pLista)->siguiente;

        //borro el nodoListaVeterinaria
        free(*pLista);

        //actualizo la lista con el siguiente
        *pLista=aux;
    }
}

///BORRAR PRIMER nodoListaVeterinaria
////////////////////////////////////////////////////////
void borrarPrimernodoListaVeterinaria(nodoListaVeterinaria **pLista)
{
    nodoListaVeterinaria *aBorrar;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //guardamos el primer nodoListaVeterinaria en una variable
        aBorrar=*pLista;

        //salteamos el primer nodoListaVeterinaria
        *pLista=(*pLista)->siguiente;

        //lo borramos
        free(aBorrar);
    }
}

///BORRAR ULTIMO nodoListaVeterinaria
////////////////////////////////////////////////////////
void borrarUltimonodoListaVeterinaria(nodoListaVeterinaria **pLista)
{
    nodoListaVeterinaria *ante=*pLista;
    nodoListaVeterinaria *seg=*pLista;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //Verificamos que el primer nodoListaVeterinaria sea el ultimo
        if(seg->siguiente==NULL)
        {
            //le asignamos null a la lista porque ahora no apunta a nada
            *pLista=NULL;

            //borramos el primer nodoListaVeterinaria
            free(seg);
        }
        //si el ultimo nodoListaVeterinaria no es el primero
        else
        {
            //recorremos la lista hasta encontrar el ultimo nodoListaVeterinaria
            while(seg->siguiente != NULL)
            {
                //guardamos el nodoListaVeterinaria actual en una variable
                ante=seg;

                //avanzamos en la lista
                seg=seg->siguiente;

            }

            //el anterior al ultimo, no apunta a nada
            ante->siguiente=NULL;

            //borramos el ultimo
            free(seg);
        }
    }
}

///DESVINCULAR PRIMER nodoListaVeterinaria
////////////////////////////////////////////////////////
nodoListaVeterinaria *desvincularPrimernodoListaVeterinaria(nodoListaVeterinaria **pLista)
{
    nodoListaVeterinaria *aDesvincular=*pLista;

    if(*pLista)
    {
        *pLista=(*pLista)->siguiente;

        aDesvincular->siguiente=NULL;
    }

    return aDesvincular;
}

///DESVINCULAR UN nodoListaVeterinaria POR PARAMETRO
////////////////////////////////////////////////////////
nodoListaVeterinaria *desvincularnodoListaVeterinaria(nodoListaVeterinaria **pLista, char nombre[])
{
    nodoListaVeterinaria *aDesvincular=NULL;

    if(*pLista!=NULL)
    {
        if((strcmp(nombre, (*pLista)->dato.nombre)==0))
        {
            aDesvincular=*pLista;

            *pLista=(*pLista)->siguiente;

            aDesvincular->siguiente=NULL;
        }
        else
        {
            nodoListaVeterinaria *seg=*pLista;
            nodoListaVeterinaria *ante;

            while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
            {
                ante=seg;

                seg=seg->siguiente;
            }


            if(seg!=NULL)
            {
                aDesvincular=seg;

                ante->siguiente=seg->siguiente;

                aDesvincular->siguiente=NULL;
            }
        }
    }

    return aDesvincular;
}
