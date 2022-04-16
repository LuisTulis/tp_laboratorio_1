/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "aerolinea.h"


int main(void)
{
	setbuf(stdout, NULL);
	int respuesta;
	char respuestaOpcion2 = 'a';
	float kilometros;
	float precioLatam = 0;
	float precioAerolineas = 0;
	float precioDebitoLatam = 0;
	float precioDebitoAerolineas = 0;
	float precioCreditoLatam;
	float precioCreditoAerolineas;
	float precioBitcoinLatam;
	float precioBitcoinAerolineas;
	float precioUnitarioLatam;
	float precioUnitarioAerolineas;
	float diferenciaPrecios;

	do
	{

		printf(		"\n1- Ingresar Kilometros. \n"
					"2- Ingresar Precio de Vuelos. \n"
					"3- Calcular todos los costos. \n"
					"4- Informar Resultados. \n"
					"5- Carga forzada de datos. \n"
					"6- Salir. \n"
					"\n Ingrese la opcion deseada.");
		scanf("%d", &respuesta);



		if(!(respuesta > 1 && respuesta <1))
		{
			fflush(stdin);
		}



		switch(respuesta)
		{
		case 1:
			printf("\n\n Ingrese la cantidad de kilometros del viaje.");
			scanf("%f", &kilometros);
			break;
		case 2:
			opcion2(respuestaOpcion2, &precioLatam, &precioAerolineas);
			break;
		case 3:
			printf("\nCalculando precios. . . \n");
			opcion3(kilometros, precioLatam, precioAerolineas, &precioDebitoLatam, &precioDebitoAerolineas, &precioCreditoLatam, &precioCreditoAerolineas, &precioBitcoinLatam, &precioBitcoinAerolineas, &precioUnitarioLatam, &precioUnitarioAerolineas, &diferenciaPrecios);
			break;
		case 4:
			opcion4(kilometros, precioDebitoLatam, precioDebitoAerolineas, precioCreditoLatam, precioCreditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioUnitarioLatam, precioUnitarioAerolineas, diferenciaPrecios);
			break;
		case 5:
			kilometros = 7090.0;
			precioAerolineas = 162965.00;
			precioLatam = 159339.0;
			opcion3(kilometros, precioLatam, precioAerolineas, &precioDebitoLatam, &precioDebitoAerolineas, &precioCreditoLatam, &precioCreditoAerolineas, &precioBitcoinLatam, &precioBitcoinAerolineas, &precioUnitarioLatam, &precioUnitarioAerolineas, &diferenciaPrecios);
			opcion4(kilometros, precioDebitoLatam, precioDebitoAerolineas, precioCreditoLatam, precioCreditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioUnitarioLatam, precioUnitarioAerolineas, diferenciaPrecios);
			break;
		case 6:
			printf("\nSaliendo del sistema. . .");
			break;
		default:
			printf("\nOpcion invalida.\n");
		}



	}
	while(respuesta!=6);

	return EXIT_SUCCESS;
}
