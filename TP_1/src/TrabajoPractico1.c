/*
 ============================================================================
 Name        : TP1.c
 Author      : Tulis Curra Luis, DIV D
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

	int flagCargaKM = 0;
	int flagCargaPrecio = 0;
	int flagCalculo = 0;


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
			flagCargaKM = 1;
			break;
		case 2:
			flagCargaPrecio = 1;
			opcion2(respuestaOpcion2, &precioLatam, &precioAerolineas);
			break;
		case 3:
			if(flagCargaKM == 1 && flagCargaPrecio == 1)
			{
				flagCalculo = 1;
				printf("\nCalculando precios. . . \n");
				opcion3(kilometros, precioLatam, precioAerolineas, &precioDebitoLatam, &precioDebitoAerolineas, &precioCreditoLatam, &precioCreditoAerolineas, &precioBitcoinLatam, &precioBitcoinAerolineas, &precioUnitarioLatam, &precioUnitarioAerolineas, &diferenciaPrecios);
			}
			else
			{
				printf("Ingrese los datos antes de calcular.");
			}
			break;
		case 4:
			if(flagCalculo == 1)
			{
				opcion4(kilometros, precioDebitoLatam, precioDebitoAerolineas, precioCreditoLatam, precioCreditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioUnitarioLatam, precioUnitarioAerolineas, diferenciaPrecios);
			}
			else
			{
				printf("Los precios no han sido calculados.");
			}
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
