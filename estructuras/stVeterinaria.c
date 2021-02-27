#include "stVeterinaria.h"
/*********************************************************//**
*
* \brief Carga veterinaria
* \param
* \return la veterinaria cargada
*
***********************************************************/
stVeterinaria cargarVeterinaria()
{
    stVeterinaria vet;

    vet.id=rand() %1000000000+9999999999;

    printf("\n---------------\n");
    printf(" NOMBRE: ");
    fflush(stdin);
    gets(vet.nombre);
    printf(" DIRRECION: ");
    fflush(stdin);
    gets(vet.direccion);
    printf(" TELEFONO:");
    fflush(stdin);
    gets(vet.telefono);
    printf("---------------\n");

    return vet;
}

////////////////////////////////////////////////////////

void mostrarVeterinaria(stVeterinaria vet)
{
    printf("\n---------------\n");
    printf(" NOMBRE:     %s\n", vet.nombre);
    printf(" DIRECCION:  %s\n", vet.direccion);
    printf(" TELEFONO:   %s", vet.telefono);
    printf("\n---------------\n");
}
