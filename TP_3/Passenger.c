/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "LinkedList.h"
#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;
	this->id = id;
	if(this->id != id)
	{
		printf("\n No id");
		retorno = 1;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;
	*id = this->id;
	if(*id != this->id)
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 1;
	if(nombre != NULL && this != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
		return retorno;

}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	strcpy(nombre, this->nombre);
	if(!(strcmp(nombre,this->nombre)))
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}

		return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	strcpy(apellido, this->apellido);
	if(!(strcmp(apellido,this->apellido)))
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}

		return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	strcpy(codigoVuelo, this->codigoVuelo);
	if(!(strcmp(codigoVuelo,this->codigoVuelo)))
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 1;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoDeVuelo, estadoVuelo);
		retorno = 0;
	}

		return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = 0;
	strcpy(estadoVuelo, this->estadoDeVuelo);
	if(!(strcmp(estadoVuelo,this->estadoDeVuelo)))
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = 0;
	this->tipoPasajero = tipoPasajero;
	if(this->tipoPasajero != tipoPasajero)
	{
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = 0;
	*tipoPasajero = this->tipoPasajero;
	if(*tipoPasajero != this->tipoPasajero)
	{
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = 0;
	this->precio = precio;
	if(this->precio != precio)
	{
		retorno = 1;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;
	*precio = this->precio;
	if(*precio != this->precio)
	{
		retorno = 1;
	}
	return retorno;
}

Passenger* Passenger_new()
{
	Passenger* nuevoPasajero = NULL;
    nuevoPasajero= (Passenger*) malloc(sizeof(Passenger));

    if(nuevoPasajero != NULL)
    {
    	nuevoPasajero->id=0;
        strcpy(nuevoPasajero->nombre, " ");
        strcpy(nuevoPasajero->apellido, " ");
        nuevoPasajero->tipoPasajero = 0;
        nuevoPasajero->precio = 0;
        strcpy(nuevoPasajero->codigoVuelo, " ");
    }

    return nuevoPasajero;

}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* tipoPasajeroStr, char* precioStr, char* flycodeStr, char* estadoStr)
{
	Passenger* nuevoPasajero = Passenger_new();
	int idAux;
	int tipoAux;
	float precioAux;

	idAux = atoi(idStr);
	tipoAux = strcmp(tipoPasajeroStr, "ExecutiveClass");
	//-1 para economica, 0 para ejecutiva, 1 para primera
	precioAux = atof(precioStr);


	int validacion = 0;

    if(nuevoPasajero != NULL)
    {
       if(Passenger_setId(nuevoPasajero,idAux) == 0)
       {
    	   validacion ++;
    	   if(Passenger_setNombre(nuevoPasajero,nombreStr) == 0)
    	   {
    		   validacion ++;
    		   if(Passenger_setApellido(nuevoPasajero,apellidoStr) == 0)
    		   {
    			   validacion ++;
    			   if(Passenger_setTipoPasajero(nuevoPasajero,tipoAux) == 0)
    			   {
    				   validacion ++;
    				   if(Passenger_setPrecio(nuevoPasajero, precioAux) == 0)
    				   {
    					   validacion ++;
    					   if(Passenger_setCodigoVuelo(nuevoPasajero, flycodeStr) == 0)
						   {
    						   validacion ++;
    						   if(Passenger_setEstadoVuelo(nuevoPasajero,estadoStr) == 0)
    						   {
    							   validacion++;
    						   }
						   }
    				   }
    			   }
    		   }
    	   }
       }

        if(validacion != 7){
            free(nuevoPasajero);
            nuevoPasajero=NULL;
        }
    }

    return nuevoPasajero;

}

//-----------------------------------------------------//
void Passenger_list(LinkedList* pArrayListPassenger)
{
	Node* indice = pArrayListPassenger->pFirstNode;
	Passenger* leer;

	printf("\nID  | Nombre y apellido |   Precio     |      Tipo      | Codigo\n");
	for(; indice != NULL; indice = indice->pNextNode)
	{
		leer = indice->pElement;
		Passenger_print(leer);
	}
}

void Passenger_print(Passenger* this)
{
	char tipoPasajeroAux[15];
	if(this != NULL)
	{
		switch(this->tipoPasajero)
		{
			case -1:
				strcpy(tipoPasajeroAux,"EconomyClass");
				break;
			case 0:
				strcpy(tipoPasajeroAux,"ExecutiveClass");
				break;
			case 1:
				strcpy(tipoPasajeroAux,"FirstClass");
				break;
		}

		printf("%d   |   ", this->id);
		printf(this->apellido);
		printf(" ");
		printf(this->nombre);
		printf("   |   ");
		printf("%.2f", this->precio);
		printf("   |   ");
		printf(tipoPasajeroAux);
		printf("   |   ");
		printf(this->codigoVuelo);
		printf("->");
		printf(this->estadoDeVuelo);
		printf("\n-------------------------------\n");
	}
}

int Passenger_idDisponible(LinkedList* pArrayListPassenger)
{
	return ll_len(pArrayListPassenger) +1;
}

void* Passenger_busqueda(LinkedList* pArrayListPassenger, int idABuscar)
{
	Node* indice = pArrayListPassenger->pFirstNode;

	Passenger* buscando;

	for(buscando = indice->pElement; buscando->id != idABuscar && buscando != NULL; indice = indice->pNextNode)
	{
		buscando = indice->pElement;
	}
	if(buscando->id != idABuscar)
	{
		buscando = NULL;
		printf("ERROR");
	}
	return buscando;
}



