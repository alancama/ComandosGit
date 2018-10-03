#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int idSector;
 int isEmpty;
}typedef Employee;

struct
{
    int id;
    char descripcion[50];
}typedef eSector;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len);
int obtenerEspacioLibre(Employee list[], int len);
void addEmployee(Employee list[],int len,eSector sectores[],int tamSector);
int elegirSector(eSector sectores[],int tam);
int buscarEmpleado(Employee list [], int tam, int legajo);
void mostrarEmpleado(Employee list,eSector sectores[],int tamSector);
void mostrarEmpleados(Employee list[], int tam,eSector sectores[],int tamSector);
void cargarDescripcion(eSector sectores [],int tamSector ,int idSector ,char cadena[]);
int siguienteID(Employee list[],int len);
void modificarEmpleado(Employee list [],int tam,eSector sectores[],int tamSector);
int menu();




#endif // ARRAYEMPLOYEES_H_INCLUDED
