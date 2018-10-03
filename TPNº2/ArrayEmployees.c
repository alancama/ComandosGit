#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int initEmployees(Employee list[], int len)
{

    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=0;
        list[i].id=0;
    }

    return  0;
}

void addEmployee(Employee list[],int len,eSector sectores[],int tamSector)
{

    Employee aux;

    int index=obtenerEspacioLibre(list,len);

    if(index==-1)
    {
        printf("No hay Lugar\n\n");
    }
    else
    {

        {

            aux.id=siguienteID(list,len);

            printf("Ingrese nombre:");
            fflush(stdin);
            gets(aux.name);

            printf("\nIngrese Apellido:");
            fflush(stdin);
            gets(aux.lastName);

            printf("\nIngrese sueldo:");
            fflush(stdin);
            scanf("%f", &aux.salary);

            aux.idSector=elegirSector(sectores,5);

            aux.isEmpty = 1;

            list[index] = aux;

        }
    }


}

int obtenerEspacioLibre(Employee list[], int len)
{
    int i;
    int retorno = -1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int menu()

{
    int opcion;

    printf("\n1-ALTA\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-Salir\n");

    scanf("%d",&opcion);

    return opcion;
}
int buscarEmpleado(Employee list [], int tam, int id )
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarDescripcion(eSector sectores [],int tamSector,int idSector,char cadena[])
{
    for(int i=0; i<tamSector; i++)
    {
        if(sectores[i].id==idSector)
        {
            strcpy(cadena,sectores[i].descripcion);
            break;
        }
    }
}

void mostrarEmpleado(Employee list,eSector sectores[],int tamSector)
{
    char descripcion[30];
    cargarDescripcion(sectores,tamSector,list.idSector,descripcion);
    printf("%d %s %s %.2f  %s \n\n", list.id, list.name, list.lastName, list.salary,descripcion);

}

int elegirSector(eSector sectores[],int tam)
{
    int idSector;
    printf("\n SECTORES\n\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d %s\n",sectores[i].id,sectores[i].descripcion);
    }
    printf("ingrese un sector:");
    scanf("%d",&idSector);

    while(idSector>5 || idSector<1)
    {
        printf("ingrese opcion correcta:");
        scanf("%d",&idSector);
    }

    return idSector;
}

void mostrarEmpleados(Employee list[], int tam,eSector sectores[],int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( list[i].isEmpty == 1)
        {
            mostrarEmpleado(list[i],sectores,tamSector);
        }
    }
}

int siguienteID(Employee list[],int len)
{
    int retorno = 0;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            if(list[i].id>retorno)
            {
                retorno=list[i].id;
            }

        }
    }

    return retorno+1;
}

void modificarEmpleado(Employee list [],int tam,eSector sectores[],int tamSector)
{
    int id;
    char modificar[];
    int indice;
    int opcion;

    mostrarEmpleados(list,tam,sectores,tamSector);
    printf("Ingrese id del empleado a modificar:");
    scanf("id",&id);

    indice=buscarEmpleado(list,tam,id);
    if( indice == -1)
    {
        printf("No hay ningun empleado con el id %d\n",id);
    }else
    {
        mostrarEmpleado(list[indice],sectores,tamSector);
        printf("***Que Desea Modificar?***");

        switch(opcion)
        {

        }
    }
