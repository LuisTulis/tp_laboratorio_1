/*
 * aerolinea.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Luis
 */


#include <stdio.h>

void opcion2(char respuestaOpcion2, float* precioLatam, float* precioAerolineas)
{
	setbuf(stdout, NULL);
	float datoLatam;
	float datoAerolineas;
		do
		{
			printf("¿Que aerolinea se va a utilizar? \n y- Latam \n z- Aerolineas \n x- Salir");
			fflush(stdin);
			scanf("%c", &respuestaOpcion2);

		switch(respuestaOpcion2)
		{
			case 'y':
				printf("\nIngrese el precio de Latam.");
				fflush(stdin);
				scanf("%f", &datoLatam);
				*precioLatam = datoLatam;
				break;
			case 'z':
				printf("\nIngrese el precio de Aerolineas.");
				fflush(stdin);
				scanf("%f", &datoAerolineas);
				*precioAerolineas = datoAerolineas;
				break;
			default:
				printf("\nSaliendo. . . ");
		}



		}while(respuestaOpcion2 == 'y' || respuestaOpcion2 == 'z');



	}


void opcion3(float kilometros, float precioLatam, float precioAerolineas, float* precioDebitoLatam, float* precioDebitoAerolineas, float* precioCreditoLatam, float* precioCreditoAerolineas, float* precioBitcoinLatam, float* precioBitcoinAerolineas, float* precioUnitarioLatam, float* precioUnitarioAerolineas, float* diferenciaPrecios)
{
	float bitcoin = 4606954.55;
	float descuento = 0.9;
	float aumento = 1.25;


	if(precioLatam>precioAerolineas)
	{
		*diferenciaPrecios = precioLatam - precioAerolineas;
	}
	else
	{
		*diferenciaPrecios = precioAerolineas-precioLatam;
	}

		*precioDebitoLatam = precioLatam * descuento;
		*precioCreditoLatam = precioLatam * aumento;
		*precioBitcoinLatam = precioLatam / bitcoin;

		*precioDebitoAerolineas = precioAerolineas * descuento;
		*precioCreditoAerolineas = precioAerolineas * aumento;
		*precioBitcoinAerolineas = precioAerolineas/bitcoin;

		*precioUnitarioLatam = precioLatam/kilometros;
		*precioUnitarioAerolineas = precioAerolineas/kilometros;
}

void opcion4(float precioDebitoLatam, float precioDebitoAerolineas, float precioCreditoLatam, float precioCreditoAerolineas, float precioBitcoinLatam, float precioBitcoinAerolineas, float precioUnitarioLatam, float precioUnitarioAerolineas, float diferenciaPrecios)
{
	if(precioUnitarioLatam > 1 && precioUnitarioAerolineas > 1)
	{
		printf(		"\nLatam: \nPrecio con tarjeta de debito: $ %.2f"
					"\nPrecio con tarjeta de credito: $ %.2f"
					"\nPrecio pagando con bitcoin : BTC %f"
					"\nPrecio unitario: $ %.2f"

					"\n\nAerolineas:"
					"\nPrecio con tarjeta de debito: $ %.2f "
					"\nPrecio con tarjeta de credito: $ %.2f"
					"\nPrecio pagando con bitcoin : BTC %f"
					"\nPrecio unitario: $ %.2f"

					"\n\nLa diferencia de precio es : $ %.2f \n", precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam, precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas, diferenciaPrecios);

	}
	else
	{

			printf("Error, calculos o datos no ingresados.");
	}
}

