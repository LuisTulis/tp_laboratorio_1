/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoDeVuelo[15];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* flycodeStr, char* estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoDeVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoDeVuelo);

//------------------------------------------------------------------//

void Passenger_list(LinkedList* pArrayListPassenger);

void Passenger_print(Passenger* this);

int Passenger_idDisponible(LinkedList* pArrayListPassenger);

void* Passenger_busqueda(LinkedList* pArrayListPassenger, int idABuscar);

int Passenger_sort(LinkedList* pArrayListPassenger, int *indexUno, int *indexDos);

#endif /* PASSENGER_H_ */
