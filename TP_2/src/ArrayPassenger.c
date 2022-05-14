/*
 * ArrayPassenger.c
 *
 *  Created on: 11 may. 2022
 *      Author: Luis
 */

#include "ArrayPassenger.h"

#include <stdio.h>

int initPassengers(Passenger *list, int len)
{
	int i = 0;

	if(list == NULL)
	{
		return -1;
	}
	for (; i < len; i++) {
		list[i].isEmpty = VACIO;
	}

	return 0;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]) {
	int i = 0;
	int retorno;
	if(list == NULL)
	{
		return -1;
	}

	for (; i < len; i++)
	{
		if (list[i].isEmpty == VACIO)
		{
			list[i].isEmpty = 0;
			list[i].statusFlight = 1;
			list[i].id = id;
			list[i].price = price;
			list[i].typePassenger = typePassenger;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			strcpy(list[i].flycode, flycode);

			printf("\nEl id del pasajero es %d", id);

			retorno = 0;
			break;
		}
		else
		{
			retorno = -1;
		}

	}
	return retorno;
}

int findPassengerById(Passenger *list, int len, int id) {
	int i;
	int posicionADevolver;

	if(list == NULL)
	{
		return -1;
	}
	for (i = 0; i < len; i++)
	{
		if (list[i].id == id)
		{
			posicionADevolver = i;
			i = len + 1;
		}
		else
		{
			return -1;
		}
	}

	return posicionADevolver;
}

int removePassenger(Passenger *list, int len, int id) {
	int posicionAVaciar = -1;
	int retorno = 0;
	posicionAVaciar = findPassengerById(list, len, id);

	if(list == NULL)
	{
		return -1;
	}

	if (posicionAVaciar == -1)
	{
		retorno = -1;
	}

	list[posicionAVaciar].isEmpty = -1;
	list[posicionAVaciar].id = -1;

	return retorno;
}

int sortPassengers(Passenger *list, int len, int order)
{
	int i;
	int j;
	int value = 0;

	Passenger listAux;

	if(list == NULL)
	{
		return -1;
	}
	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{
				if (order == 1)
				{
					if(list[i].typePassenger > list[j].typePassenger)
					{
						value = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							value = strcmp(list[j].lastName, list[i].lastName);
						}
					}
				}

				else
				{
					if(list[i].typePassenger < list[j].typePassenger)
					{
						value = 1;
					}
					else
					{
						if(list[i].typePassenger == list[j].typePassenger)
						{
							value = strcmp(list[i].lastName, list[j].lastName);
						}
					}
				}


				if (value == 1)
				{
					value = 0;

					listAux = list[i];
					list[i] = list[j];
					list[j] = listAux;

					j = i+1;
				}
			}
		}
	}
	return 0;
}

int sortPassengersByCode(Passenger *list, int len, int order)
{
	int i;
	int j;
	int value = 0;

	Passenger listAux;
	if(list == NULL)
	{
		return -1;
	}
	for(i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (list[j].isEmpty != -1)
			{

				if (order == 1)
				{
					if(list[i].statusFlight > list[j].statusFlight)
					{
						value = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							value = strcmp(list[j].flycode, list[i].flycode);
						}
					}
				}

				else
				{
					if(list[i].statusFlight < list[j].statusFlight)
					{
						value = 1;
					}
					else
					{
						if(list[i].statusFlight == list[j].statusFlight)
						{
							value = strcmp(list[i].flycode, list[j].flycode);
						}
					}
				}


				if (value == 1)
				{
					value = 0;

					listAux = list[i];
					list[i] = list[j];
					list[j] = listAux;

					j = i+1;
				}
			}
		}
	}
	return 0;
}


int printPassenger(Passenger* list, int length)
{
	char tipoPasajero[20];
	char estadoDeVuelo[20];
	int i;
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty != -1)
		{

			if(list[i].typePassenger == 1)
			{
				strcpy(tipoPasajero, "Turista");
			}
			else
			{
				if(list[i].typePassenger == 2)
				{
					strcpy(tipoPasajero,"Promocional");
				}
				else
				{
					strcpy(tipoPasajero,"Ejecutivo");
				}
			}

			if(list[i].statusFlight == 1)
			{
				strcpy(estadoDeVuelo,"ACTIVO");
			}
			else
			{

				strcpy(estadoDeVuelo,"INACTIVO");
			}

			printf("\n------------------"
				   "\n %d | %s %s | %s | %s | Costo: $%.f | %s "
				   "\n------------------\n", list[i].id, list[i].lastName, list[i].name, list[i].flycode, tipoPasajero, list[i].price, estadoDeVuelo);
		}
	}

	return 0;
}

