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
							value = strcmp(list[i].lastName, list[j].lastName);
						}
					}
				}

				else
				{
					if(list[i].typePassenger < list[j].typePassenger)
					{
						value = strcmp(list[j].lastName, list[i].lastName);
					}
				}


				if (value == 1)
				{
					value = 0;

					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;
					listAux.statusFlight = list[i].statusFlight;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;
					list[i].statusFlight = list[j].statusFlight;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;
					list[j].statusFlight = listAux.statusFlight;

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
							value = strcmp(list[i].flycode, list[j].flycode);
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
							value = strcmp(list[j].flycode, list[i].flycode);
						}
					}
				}


				if (value == 1)
				{
					value = 0;

					listAux.id = list[i].id;
					strcpy(listAux.name, list[i].name);
					strcpy(listAux.lastName, list[i].lastName);
					listAux.price = list[i].price;
					strcpy(listAux.flycode, list[i].flycode);
					listAux.typePassenger = list[i].typePassenger;
					listAux.statusFlight = list[i].statusFlight;

					list[i].id = list[j].id;
					strcpy(list[i].name, list[j].name);
					strcpy(list[i].lastName, list[j].lastName);
					list[i].price = list[j].price;
					strcpy(list[i].flycode, list[j].flycode);
					list[i].typePassenger = list[j].typePassenger;
					list[i].statusFlight = list[j].statusFlight;

					list[j].id = listAux.id;
					strcpy(list[j].name, listAux.name);
					strcpy(list[j].lastName, listAux.lastName);
					list[j].price = listAux.price;
					strcpy(list[j].flycode, listAux.flycode);
					list[j].typePassenger = listAux.typePassenger;
					list[j].statusFlight = listAux.statusFlight;

					j = i+1;
				}
			}
		}
	}
	return 0;
}


int printPassenger(Passenger* list, int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		if(list[i].isEmpty != -1)
		{
			printf("\n------------------\n");
			printf("%d", list[i].id);
			printf(" | ");
			printf(list[i].lastName);
			printf(" ");
			printf(list[i].name);
			printf(" | ");
			printf(list[i].flycode);
			printf(" | ");

			if(list[i].typePassenger == 1)
			{
				printf("Turista");
			}
			else
			{
				if(list[i].typePassenger == 2)
				{
					printf("Promocional");
				}
				else
				{
					printf("Ejecutivo");
				}
			}

			printf(" | ");
			printf("Costo: %.2f", list[i].price);
			printf(" | ");
			if(list[i].statusFlight == 1)
			{
				printf("ACTIVO");
			}
			else
			{

					printf("INACTIVO");
			}
			printf("\n------------------\n");
		}
	}

	return 0;
}

