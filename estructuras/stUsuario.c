#include "stUsuario.h"


/*********************************************************//**
*
* \brief Carga usuario
* \param char usuario[] - trae ya el nombre del usuario
* \return user
*
***********************************************************/
stUsuario cargarUsuario(char usuario[])
{
    stUsuario user;

    strcpy(user.user,usuario);

    printf("\n---------------\n");
    printf("CONTRASEÑA: ");
    fflush(stdin);
    gets(user.pass);

    printf("NOMBRE: ");
    fflush(stdin);
    gets(user.nombre);

    printf("APELLIDO: ");
    fflush(stdin);
    gets(user.apellido);

    printf("EDAD: ");
    scanf("%d", &user.edad);

    printf("DNI: ");
    fflush(stdin);
    gets(user.DNI);

    printf("MAIL: ");
    fflush(stdin);
    gets(user.mail);

    printf("---------------\n");

    user.rol=1;
    user.alta=1;

    return user;
}
/*********************************************************//**
*
* \brief Carga perro
* \param stUsuario * user, - trae ya el nombre del usuario
* \return
*
***********************************************************/
void cargarPerro(stUsuario *user, int i)
{
    printf("\n-------------------------------\n");

    user->perro[i].id=rand() %1000000000+9999999999;

    printf("NOMBRE: ");
    fflush(stdin);
    gets(user->perro[i].nombrePerro);

    printf("RAZA: ");
    fflush(stdin);
    gets(user->perro[i].raza);

    printf("RAZGOS: ");
    fflush(stdin);
    gets(user->perro[i].descripcion);

    do
    {
        printf("Su perro esta peridido? [1-SI/0-NO]: ");
        scanf("%d", &user->perro[i].perdido);

        if(user->perro[i].perdido!=0 && user->perro[i].perdido!=1)
        {
            printf("Dato incorrecto, vuelva a ingresar el dato.\n");
        }
    }
    while(user->perro[i].perdido!=0 && user->perro[i].perdido!=1);

    printf("-------------------------------\n");
}
////////////////////////////////////////////////////////
/*********************************************************//**
*
* \brief mostrar usuario
* \param stUsuario dato - cargado
* \return
************************************************************/
void mostrarUsuario(stUsuario dato)
{
    int i=0;

    printf("\n-------------------------------\n");
    printf(" USUARIO:     %s\n", dato.user);
    printf(" NOMBRE:      %s\n", dato.nombre);
    printf(" APELLIDO:    %s\n", dato.apellido);
    printf(" EDAD:        %d\n", dato.edad);
    printf(" DNI:         %s\n", dato.DNI);
    printf(" MAIL:        %s\n", dato.mail);

    while(i < dato.perrosValidos)
    {
        mostrarPerro(dato.perro[i]);
        i++;
    }


}
/*********************************************************//**
*
* \brief muestra usuario
* \param stUsuario
* \return
*
***********************************************************/
void mostrarUsuarioSinPerro(stUsuario dato)
{
    printf("\n-------------------------------\n");
    printf(" USUARIO:     %s\n", dato.user);
    printf(" NOMBRE:      %s\n", dato.nombre);
    printf(" APELLIDO:    %s\n", dato.apellido);
    printf(" EDAD:        %d\n", dato.edad);
    printf(" DNI:         %s\n", dato.DNI);
    printf(" MAIL:        %s\n", dato.mail);
    printf("-------------------------------\n");


}

void mostrarPerro(stPerro perro)
{

    printf("\n");
    printf(" ID Perro:    %d\n", perro.id);
    printf(" Nombre:      %s\n", perro.nombrePerro);
    printf(" Raza:        %s\n", perro.raza);
    printf(" Descripcion: %s\n", perro.descripcion);

    if(perro.perdido)
    {
        printf(" ESTADO:      Perdido\n");
    }
    else
    {
        printf(" ESTADO:      Con su dueño\n");
    }
    printf("\n-------------------------------\n");
}

void arMostrarUsuarios(char fileName[])
{
    FILE *buffer=fopen(fileName, "rb");
    stUsuario aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(stUsuario), 1,buffer)>0)
        {
            mostrarUsuario(aux);
        }
        fclose(buffer);
    }
}
