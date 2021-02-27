#include "arbolUsuario.h"

void inicArbolUsuario(nodoArbolUsuario **arbolito)
{
    *arbolito=NULL;
}

nodoArbolUsuario* crearNodoArbolUsuario(stUsuario dato)
{
    nodoArbolUsuario *aux= (nodoArbolUsuario *) malloc(sizeof(nodoArbolUsuario));

    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;

    return aux;
}
/*inserta usuario en el arbol dependiendo de lo que haya leido en el arreglo de usaurios*/
nodoArbolUsuario* insertarArbolUsuario(nodoArbolUsuario *arbolito, stUsuario dato)
{
    if(!arbolito)
    {
        arbolito=crearNodoArbolUsuario(dato);
    }
    else
    {
        if(strcmp(dato.user, arbolito->dato.user)>0)
        {
            arbolito->der=insertarArbolUsuario(arbolito->der, dato);
        }
        else if(strcmp(dato.user, arbolito->dato.user)<0)
        {
            arbolito->izq=insertarArbolUsuario(arbolito->izq, dato);
        }
    }

    return arbolito;
}


void preorderUsuario(nodoArbolUsuario *arbolito)
{
    if(arbolito)
    {
        mostrarUsuario(arbolito->dato);
        preorderUsuario(arbolito->izq);
        preorderUsuario(arbolito->der);
    }

}

void preorderUsuarioFiltro(nodoArbolUsuario *arbolito, int alta)
{
    if(arbolito)
    {
        if(arbolito->dato.alta==alta)
        {
            mostrarUsuario(arbolito->dato);
        }

        preorderUsuarioFiltro(arbolito->izq, alta);
        preorderUsuarioFiltro(arbolito->der, alta);
    }
}
/*muestra a los perros o perdidos o con su duenio*/
void preorderUsuarioFiltroPerros(nodoArbolUsuario *arbolito, int perdido)
{
    int i=0;

    if(arbolito)
    {
        while(i<arbolito->dato.perrosValidos)
        {
            if(arbolito->dato.perro[i].perdido==perdido)
            {
                mostrarUsuarioSinPerro(arbolito->dato);
                mostrarPerro(arbolito->dato.perro[i]);
            }

            i++;
        }

        preorderUsuarioFiltroPerros(arbolito->izq, perdido);
        preorderUsuarioFiltroPerros(arbolito->der, perdido);
    }
}

void inorderUsuario(nodoArbolUsuario *arbolito)
{
    if(arbolito)
    {
        inorderUsuario(arbolito->izq);
        mostrarUsuario(arbolito->dato);
        inorderUsuario(arbolito->der);
    }
}

void postorderUsuario(nodoArbolUsuario *arbolito)
{
    if(arbolito)
    {
        postorderUsuario(arbolito->izq);
        postorderUsuario(arbolito->der);
        mostrarUsuario(arbolito->dato);
    }
}
/*buscar un usuario en el arbol inorden*/
nodoArbolUsuario *buscarArbolUsuario(nodoArbolUsuario *arbolito, char user[])
{
    nodoArbolUsuario *rta=NULL;

    if(arbolito)
    {
        if(strcmp(user,arbolito->dato.user)==0)/*primero comprueba la raiz- en caso de que el primer nodo sea el buscado*/
        {
            rta=arbolito;
        }
        else
        {
            if(strcmp(user,arbolito->dato.user)<0)/*si es menor va por izquierda*/
            {
                rta=buscarArbolUsuario(arbolito->izq, user);
            }
            else/*si es mayor por derecha*/
            {
                rta=buscarArbolUsuario(arbolito->der, user);
            }
        }
    }

    return rta;
}

/*busca uuser*/

nodoArbolUsuario *buscarArbolUsuarioConPass(nodoArbolUsuario *arbolito, char user[], char pass[])
{
    nodoArbolUsuario *rta=NULL;

    if(arbolito)
    {
        if(strcmp(user,arbolito->dato.user)==0 && strcmp(pass,arbolito->dato.pass)==0 && arbolito->dato.alta==1)/*comprueba usuario, passs y si esta de alta el usuario*/
            rta=arbolito;
        }
        else
        {
            if(strcmp(user,arbolito->dato.user)<0)/*si es menor a 0 se va por izquierda*/
            {
                rta=buscarArbolUsuarioConPass(arbolito->izq, user, pass);
            }
            else
            {
                rta=buscarArbolUsuarioConPass(arbolito->der, user, pass);
            }
        }
    }

    return rta;
}


nodoArbolUsuario *buscarNombreArbolUsuario(nodoArbolUsuario *arbolito, char nombre[])
{
    nodoArbolUsuario *buscado=NULL;

    if(arbolito)
    {
        if(strcmp(nombre, arbolito->dato.nombre)==0) //proceso raiz
        {
            buscado=arbolito;
        }
        else
        {
            buscado=buscarNombreArbolUsuario(arbolito->izq, nombre); //me voy por izquierda

            if(!buscado) //si no lo encontre por izquierda...
            {
                buscado=buscarNombreArbolUsuario(arbolito->der, nombre); //me voy por derecha
            }
        }
    }

    return buscado;
}

int mayorArbolUsuario(int izquierdo, int derecho)
{
    int rta =0;
    if (izquierdo>derecho)
    {
        rta = izquierdo;
    }
    else
    {
        rta=derecho;
    }
    return rta;
}

int alturaDelArbolUsuario(nodoArbolUsuario *arbolito)
{
    int resp;
    if(arbolito==NULL)
    {
        resp=0;
    }
    else
    {
        if(!arbolito->izq && !arbolito->der)
        {
            resp=1;
        }
        else
        {
            resp=1 + mayorArbolUsuario( alturaDelArbolUsuario(arbolito->izq), alturaDelArbolUsuario(arbolito->der));
        }
    }
    return resp;
}

int cantidadDeNodosArbolUsuario(nodoArbolUsuario *arbolito)
{
    int cant;

    if(!arbolito)
    {
        cant=0;
    }
    else
    {
        cant= 1 + cantidadDeNodosArbolUsuario(arbolito->izq) + cantidadDeNodosArbolUsuario(arbolito->der);
    }

    return cant;
}

int cantidadDeNodosFiltradoArbolUsuario(nodoArbolUsuario *arbolito)
{
    int cant;

    if(!arbolito)
    {
        cant=0;
    }
    else
    {
        if(arbolito->dato.edad > 18)
        {
            cant= 1 + cantidadDeNodosFiltradoArbolUsuario(arbolito->izq) + cantidadDeNodosFiltradoArbolUsuario(arbolito->der);
        }
        else
        {
            cant= cantidadDeNodosFiltradoArbolUsuario(arbolito->izq) + cantidadDeNodosFiltradoArbolUsuario(arbolito->der);
        }
    }

    return cant;
}

int cuentaHojasUsuario(nodoArbolUsuario *arbolito)
{
    int rta;

    if(!arbolito)
    {
        rta=0;
    }
    else
    {
        if(!arbolito->izq && !arbolito->der)
        {
            rta=1;
        }
        else
        {
            rta=cuentaHojasUsuario(arbolito->izq) + cuentaHojasUsuario(arbolito->der);
        }
    }

    return rta;
}


////////////////////////////////////////////////


int sumaRecursivaArbolUsuario(nodoArbolUsuario *arbolito)
{
    int suma;

    if(!arbolito)
    {
        suma=0;
    }
    else
    {
        if(!arbolito->izq && !arbolito->der)
        {
            suma=arbolito->dato.edad;
        }
        else
        {
            suma=arbolito->dato.edad + sumaRecursivaArbolUsuario(arbolito->izq) + sumaRecursivaArbolUsuario(arbolito->der);
        }
    }

    return suma;
}
/*
int sumaRecursivaArbolParesUsuario(nodoArbolUsuario *arbolito)
{
    int suma;

    if(!arbolito)
    {
        suma=0;
    }
    else
    {
        if(arbolito->dato.edad%2 == 0)
        {
            suma=arbolito->dato.edad + sumaRecursivaArbolParesUsuario(arbolito->izq) + sumaRecursivaArbolParesUsuario(arbolito->der);
        }
        else
        {
            suma=sumaRecursivaArbolParesUsuario(arbolito->izq) + sumaRecursivaArbolParesUsuario(arbolito->der);
        }
    }

    return suma;
}
*/
