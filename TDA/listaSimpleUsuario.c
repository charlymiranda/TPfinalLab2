#include "listaSimpleUsuario.h"

///INICIALIZAR LA LISTA
////////////////////////////////////////////////////////
void inicListaListaUsuario(nodoListaUsuario **pLista)
{
    //Se asigna a la lista NULL porque no apunta a ningun nodoListaUsuario
    *pLista=NULL;
}

///CREAR UN nodoListaUsuario Y RETORNARLO
////////////////////////////////////////////////////////
nodoListaUsuario *crearNodoListaUsuario(stUsuario dato)
{
    //Crear un puntero de tipo nodoListaUsuario
    nodoListaUsuario *nuevo = (nodoListaUsuario*)malloc(sizeof(nodoListaUsuario));

    //Se le asigna el nuevo dato
    nuevo->dato = dato;

    //Y como es un unico nodoListaUsuario el siguiente es NULL
    nuevo->siguiente = NULL;

    //Se retorna
    return nuevo;
}

///AGREGAR nodoListaUsuarioS AL PRINCIPIO
////////////////////////////////////////////////////////
void agregarPpioListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario)
{
    //Verificamos que la lista este vacia para agregar el nuevo nodoListaUsuario al principio
    if(*pLista == NULL)
    {
        *pLista = nuevonodoListaUsuario;
    }
    else
    {
        //Se enlaza por siguiente el nodoListaUsuario que estaba al principio
        nuevonodoListaUsuario->siguiente = *pLista;

        //Se le asigna a la lista el nuevo nodoListaUsuario para que se posicione al principio
        *pLista = nuevonodoListaUsuario;
    }
}

///MOSTRAR UN nodoListaUsuario
////////////////////////////////////////////////////////
void mostrarNodoListaUsuario(nodoListaUsuario *aux)
{
    //printf("\n%p ---> Siguiente: %p\n", aux, aux->siguiente);
    mostrarUsuario(aux->dato);
}

///MOSTRAR UNA LISTA
////////////////////////////////////////////////////////
void mostrarListaUsuario(nodoListaUsuario **pLista)
{
    nodoListaUsuario *seg = *pLista;
    while(seg !=NULL)
    {
        mostrarNodoListaUsuario(seg);
        seg=seg->siguiente;
    }
}

///BUSCAR ULTIMO
////////////////////////////////////////////////////////
nodoListaUsuario *buscarUltimoListaUsuario(nodoListaUsuario *pLista)
{
    //En caso de puntero doble se baja a otra variable para no modificar la lista
    nodoListaUsuario *seg=pLista;

    //Se trabaja si hay nodoListaUsuarios en la lista
    if(seg!=NULL)
    {
        //se recorre la lista mientras que el nodoListaUsuario no apunte a NULL, cuando el nodoListaUsuario apunte a NULL corta porque es el ultimo nodoListaUsuario de la lista
        while(seg->siguiente !=NULL)
        {
            //Se recorre de esta manera
            seg=seg->siguiente;
        }
    }

    //Retornamos el ultimo nodoListaUsuario
    return seg;
}

///AGREGAR AL FINAL (UTILIZA BUSCAR ULTIMO)
////////////////////////////////////////////////////////
void agregarFinalListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario)
{
    //Si la lista esta vacia, el nodoListaUsuario se enlaza con la lista
    if(*pLista == NULL)
    {
        *pLista = nuevonodoListaUsuario;
    }
    else
    {
        //se busca al ultimo nodoListaUsuario
        nodoListaUsuario *ultimo=buscarUltimoListaUsuario(*pLista);

        //y se enlaza al ultimo nodoListaUsuario por siguiente al nuevo nodoListaUsuario.
        ultimo->siguiente=nuevonodoListaUsuario;
    }

}

///BUSCAR nodoListaUsuario
////////////////////////////////////////////////////////
nodoListaUsuario *buscarNodoListaUsuario(nodoListaUsuario **pLista, char nombre[])
{
    nodoListaUsuario *seg=*pLista;

    //Se recorre la lista mientras esta no este vacia, o el dato no coincida, cuando quede vacia o encontremos el dato, corta
    while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
    {
        seg=seg->siguiente;
    }

    //Retornamos el nodoListaUsuario buscado
    return seg;
}

///BORRAR nodoListaUsuario
////////////////////////////////////////////////////////
void borrarNodoListaUsuario(nodoListaUsuario **pLista, char nombre[])
{
    //Se trabaja si la lista no esta vacia.
    if(*pLista!=NULL)
    {
        ///1.SI EL nodoListaUsuario ES EL PRIMERO: Se compara con el primer nodoListaUsuario de la lista, si es igual al dato a borrar, lo borra y termina.
        if((strcmp(nombre, (*pLista)->dato.nombre)==0))
        {
            //Se baja el nodoListaUsuario a una variable para no perder la direccion de memoria y poder borrarlo
            nodoListaUsuario *aBorrar=*pLista;

            //Se saltea ese nodoListaUsuario, ahora lista apunta al siguiente nodoListaUsuario
            *pLista=(*pLista)->siguiente;

            //Borramos el nodoListaUsuario deseado
            free(aBorrar);
        }
        ///2.SI EL nodoListaUsuario ESTA EN EL MEDIO O ES EL ULTIMO
        else
        {
            //bajamos la lista a una variable para no modificarla
            nodoListaUsuario *seg=*pLista;
            nodoListaUsuario *ante;

            //recorremos la lista mientras que no este vacia y el dato sea dinstino al que queremos borrar
            while((seg !=NULL) && (strcmp(nombre, seg->dato.nombre) !=0))
            {
                //se le asigna a ante el nodoListaUsuario actual
                ante=seg;

                //seg avanza un nodoListaUsuario
                seg=seg->siguiente;
            }

            //verificamos si encontramos el dato
            if(seg!=NULL)
            {
                //ante es el anterior del que queiro borrar y lo apunto al siguiente del que quiero borrar
                //Salteo el nodoListaUsuario que quiero eliminar
                ante->siguiente=seg->siguiente;

                //eliminamos el nodoListaUsuario seg==aborrar
                free(seg);
            }
        }
    }
}

///AGREGAR EN ORDEN
////////////////////////////////////////////////////////
void agregarEnOrdenListaUsuario(nodoListaUsuario **pLista, nodoListaUsuario *nuevonodoListaUsuario)
{
    //Si la lista esta vacia, el nodoListaUsuario se agrega al principio
    if(*pLista==NULL)
    {
        *pLista = nuevonodoListaUsuario;
    }
    else
    {
        //si el nodoListaUsuario que queremos agregar es menor al primer nodoListaUsuario, lo agregamos al principio
        if(strcmp(nuevonodoListaUsuario->dato.user, (*pLista)->dato.user)<0)
        {
            agregarPpioListaUsuario(pLista, nuevonodoListaUsuario);
        }
        else
        {
            nodoListaUsuario *seg = (*pLista)->siguiente;
            nodoListaUsuario *ante = *pLista;

            //buscamos el lugar del dato que queremos insertar, se recorre la lista mientras esta no este vacia yy el dato a insertar sea mayor
            while(seg!=NULL && strcmp(nuevonodoListaUsuario->dato.user, seg->dato.user)>0)
            {
                //guardamos el actual en una varaible
                ante=seg;

                //avanzamos en la lista
                seg=seg->siguiente;
            }

            //insertamos el nuevo nodoListaUsuario en el lugar indicado

            //el anterior apunta al nuevo nodoListaUsuario
            ante->siguiente = nuevonodoListaUsuario;

            //el nuevo nodoListaUsuario apunta al siguiente
            nuevonodoListaUsuario->siguiente = seg;
        }
    }
}

///BORRAR TODA LA LISTA
////////////////////////////////////////////////////////
void borrarTodaLaListaUsuario(nodoListaUsuario **pLista)
{
    nodoListaUsuario *aux;

    //Se va recorriendo y borrando mientras que la lista no este vacia
    while(*pLista!=NULL)
    {
        //guardo el nodoListaUsuario siguiente al que se va a borrar
        aux = (*pLista)->siguiente;

        //borro el nodoListaUsuario
        free(*pLista);

        //actualizo la lista con el siguiente
        *pLista=aux;
    }
}

///BORRAR PRIMER nodoListaUsuario
////////////////////////////////////////////////////////
void borrarPrimernodoListaUsuario(nodoListaUsuario **pLista)
{
    nodoListaUsuario *aBorrar;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //guardamos el primer nodoListaUsuario en una variable
        aBorrar=*pLista;

        //salteamos el primer nodoListaUsuario
        *pLista=(*pLista)->siguiente;

        //lo borramos
        free(aBorrar);
    }
}

///BORRAR ULTIMO nodoListaUsuario
////////////////////////////////////////////////////////
void borrarUltimonodoListaUsuario(nodoListaUsuario **pLista)
{
    nodoListaUsuario *ante=*pLista;
    nodoListaUsuario *seg=*pLista;

    //verificamos que la lista no este vacia
    if(*pLista!=NULL)
    {
        //Verificamos que el primer nodoListaUsuario sea el ultimo
        if(seg->siguiente==NULL)
        {
            //le asignamos null a la lista porque ahora no apunta a nada
            *pLista=NULL;

            //borramos el primer nodoListaUsuario
            free(seg);
        }
        //si el ultimo nodoListaUsuario no es el primero
        else
        {
            //recorremos la lista hasta encontrar el ultimo nodoListaUsuario
            while(seg->siguiente != NULL)
            {
                //guardamos el nodoListaUsuario actual en una variable
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

///DESVINCULAR PRIMER nodoListaUsuario
////////////////////////////////////////////////////////
nodoListaUsuario *desvincularPrimernodoListaUsuario(nodoListaUsuario **pLista)
{
    nodoListaUsuario *aDesvincular=*pLista;

    if(*pLista)
    {
        *pLista=(*pLista)->siguiente;

        aDesvincular->siguiente=NULL;
    }

    return aDesvincular;
}

///DESVINCULAR UN nodoListaUsuario POR PARAMETRO
////////////////////////////////////////////////////////
nodoListaUsuario *desvincularnodoListaUsuario(nodoListaUsuario **pLista, char nombre[])
{
    nodoListaUsuario *aDesvincular=NULL;

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
            nodoListaUsuario *seg=*pLista;
            nodoListaUsuario *ante;

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
