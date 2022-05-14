/*
 * complementarTP.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luis
 */

#include "ArrayPassenger.h"
#include "stdio.h"

float totalDeArray(Passenger* valores, int longitud)
{
	int i;
	float acumulador = 0;
	for(i = 0; i < longitud; i++)
	{
		if(valores[i].isEmpty != -1)
		{
			acumulador = acumulador + valores[i].price;
		}
	}
	return acumulador;
}

float promedioDeArray(Passenger* valores, int longitud, float total)
{
	int i;
	float promedio = 0;
	int contador;
		for(i = 0; i < longitud; i++)
		{
			if(valores[i].isEmpty != -1)
			{
				contador ++;
			}
		}

		promedio = total/contador;

	return promedio;
}

int contadorMayorAlPromedio(Passenger* valores, int longitud, float promedio)
{
	int i;
	int contador = 0;

	for(i = 0; i < longitud; i++)
	{
		if(valores[i].isEmpty != -1)
		{
			if(valores[i].price > promedio)
			{
				contador ++;
			}
		}
	}
	return contador;
}

void mostrarPasajero(Passenger* list, int len, int id)
{
	int i;
	for(i = 0; i<len; i++)
	{
		if(list[i].id == id)
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
			break;
		}
	}
}




