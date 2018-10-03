#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define TAM 2

int main()
{

    char seguir='s';

    Employee empleado[TAM];
     eSector sectores[]=
    {
        {1,"RRHH"},
        {2,"Ventas"},
        {3,"Compras"},
        {4,"Contable"},
        {5,"Sistema"}
    };
    initEmployees(empleado,TAM);

    do
    {

        switch(menu())
        {
        case 1:

                    addEmployee(empleado,TAM,sectores,5);
                    system("pause");
                    break;
        case 2:
                    mostrarEmpleados(empleado,TAM,sectores,5);
                    system("pause");
                    break;
        case 5:
                seguir='n';
                break;

        }
    }while(seguir=='s');

    return 0;
}
