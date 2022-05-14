/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 *  (!) El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP2 de la materia, el mismo deberá de ser realizado utilizando Eclipse. Recuerden que tiene que encontrarse en el mismo repositorio reportado, no en uno nuevo.
 *	(!) Si no cuenta con los archivos .cproject y .project el TP no se corregirá.
 *	(!) El TP debe contar, al menos, con la biblioteca correspondiente a la entidad y otra donde se encuentren los inputs.
 *	(!) Recuerden que si el TP no compila o rompe al momento de hacer alguna prueba se encuentra desaprobado.
 *	(!) No se deben modificar los prototipos de las funciones dadas en el enunciado
 *
 *  Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe que
 *	no puede tener más de 2000 pasajeros.
 *	Datos:
 *
 *	El sistema deberá tener el siguiente menú de opciones:
 *	1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el
 *	número de Id. El resto de los campos se le pedirá al usuario.
 *
 *	2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 *	o Precio o Tipo de pasajero o Código de vuelo
 *	3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 *	4. INFORMAR:
 * 	1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 * 	2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
 *	promedio.
 *	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 *	1-NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 *	Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 *	carga de algún pasajero.
 *	2-NOTA: Es deseable generar una segunda entidad y utilizarla en el programa.
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"
#include "TpInputs.h"
#include "complementarTP.h"

int main(void)
{
	setbuf(stdout, NULL);

	int idAux = 0;
	char nameAux[51];
	char lastNameAux[51];
	float priceAux;
	char flycodeAux[10];
	int typePassengerAux;

	int idABuscar;
	int posicionDada;
	int respuestaSubMenu;
	int confirmarAccion;

	int ordenDeOrdenamiento;
	int tipoDeOrdenamiento;

	float total;
	float promedio;
	int cantidadMasPromedio;

	int respuesta;
	int largo = 2000;
	Passenger pasajeros[largo];
	int validacionInit = initPassengers(pasajeros, largo);
	if(validacionInit == -1)
	{
		printf("Error en la inicializacion del sistema, puede provocar errores.");
	}

	int flagPasajeroIngresado = 0;

	do
	{
		printf(	"\n1- Ingresar pasajero.\n"
				"2- Modificar pasajero.\n"
				"3- Eliminar pasajero.\n"
				"4- Informar pasajeros.\n"
				"5- Ingreso forzado de pasajeros.\n"
				"6- Salir.\n"
				"\nIngrese la opcion deseada.");
		scanf("%d", &respuesta);
		fflush(stdin);

		switch(respuesta)
		{
			case 1:
			{
				idAux ++;

				rellenarArray(nameAux, "\nIngrese el nombre del pasajero");

				rellenarArray(lastNameAux, "\nIngrese el apellido del pasajero.");

				rellenarFloat(&priceAux, "\nIngrese el precio del vuelo.", "\nError, ingrese un numero.\n");

				rellenarArray(flycodeAux, "\nIngrese el codigo de vuelo");

				rellenarInt(&typePassengerAux, "\nIngrese el tipo de pasajero (1-Turista, 2-Promocional, Otro-Ejecutivo).", "\nError, ingrese un numero.\n");

				int validacionAdd = addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				if(validacionAdd == -1)
				{
					printf("Error al ingresar el pasajero. Lista llena o error en el sistema.");
				}
				flagPasajeroIngresado = 1;
				break;
			}
			case 2:
			{
				if(flagPasajeroIngresado == 0)
				{
					printf("No hay pasajeros ingresados");
					break;
				}
				rellenarInt(&idABuscar, "\nIngrese el id a modifcar.\n", "\nError, ingrese un numero.\n");

				posicionDada = findPassengerById(pasajeros, largo, idABuscar);
				if(posicionDada == -1)
				{
					printf("Id no encontrado.");
					break;
				}

				mostrarPasajero(pasajeros, largo, idABuscar);

				rellenarInt(&confirmarAccion, "Es el pasajero con dicha id, ¿seguro que quiere modificarlo? \n1-Si \n2-No\n" ,"\nError, ingrese un numero.\n");
				if(confirmarAccion == 1)
				{
					do
					{
						printf(	"\n1- Modificar nombre.\n"
								"2- Modificar apellido.\n"
								"3- Modificar precio.\n"
								"4- Modificar codigo de vuelo.\n"
								"5- Modificar tipo de pasajero.\n"
								"6- Modificar estado de vuelo.\n"
								"7- Salir.\n"
								"\nIngrese la opcion deseada.");
						scanf("%d", &respuestaSubMenu);
						fflush(stdin);

						switch(respuestaSubMenu)
						{
							case 1:
							{
								rellenarArray(pasajeros[posicionDada].name, "\nIngrese el nombre modificado\n");
								break;
							}
							case 2:
							{
								rellenarArray(pasajeros[posicionDada].lastName, "\nIngrese el apellido modificado\n");
								break;
							}
							case 3:
							{
								rellenarFloat(&pasajeros[posicionDada].price, "\nIngrese el precio modificado.\n", "\nError, ingrese un numero.\n");
								break;
							}
							case 4:
							{
								rellenarArray(pasajeros[posicionDada].flycode, "\nIngrese el codigo de vuelo modificado.\n");
								break;
							}
							case 5:
							{
								rellenarInt(&pasajeros[posicionDada].typePassenger, "\nIngrese el tipo de pasajero modificado(1-Turista, 2-Promocional, Otro-Ejecutivo).\n", "\nError, ingrese un numero.\n");
								break;
							}
							case 6:
							{
								rellenarInt(&pasajeros[posicionDada].statusFlight, "\nIngrese el estado del vuelo (1-Activo, Otro-Inactivo)\n", "\nError, ingrese un numero.\n");
								break;
							}
							case 7:
							{
								printf("\nSaliendo al menu\n");
								break;
							}
							default:
							{
								printf("\nOpcion no valida.");
							}
						}
					}while(respuestaSubMenu != 7);
				}
				else
				{
					break;
				}
				break;
			}
			case 3:
			{
				if(flagPasajeroIngresado == 0)
				{
					printf("No hay pasajeros ingresados");
					break;
				}
				rellenarInt(&idABuscar, "\nIngrese el id a borrar.\n", "\nError, ingrese un numero.\n");

				mostrarPasajero(pasajeros, largo, idABuscar);

				rellenarInt(&confirmarAccion, "Es el pasajero con dicha id, ¿seguro que quiere eliminarlo? \n1-Si \n2-No\n" ,"\nError, ingrese un numero.\n");

				if(confirmarAccion == 1)
				{
					int validacionRemove = removePassenger(pasajeros, largo, idABuscar);
					if(validacionRemove == -1)
					{
						printf("Error al eliminar al pasajero.");
					}
				}

				break;
			}
			case 4:
			{
				if(flagPasajeroIngresado == 0)
				{
					printf("No hay pasajeros ingresados");
					break;
				}
				rellenarInt(&tipoDeOrdenamiento,"\n1- Ordenar por apellido y tipo de pasajero.\n"
												"2- Ordenar por codigo y estado de vuelo.\n", "\nError, ingrese un numero.\n");
				rellenarInt(&ordenDeOrdenamiento,"\n1- Ordenar de manera decreciente.\n"
												"2- Ordenar de manera creciente.\n", "\nError, ingrese un numero.\n");

				int validacionSort;
				if(tipoDeOrdenamiento == 1)
				{
					validacionSort = sortPassengers(pasajeros, largo, ordenDeOrdenamiento);
					if(validacionSort == -1)
					{
						printf("Error al ordenar.");
					}
				}
				else
				{
					validacionSort = sortPassengersByCode(pasajeros, largo, ordenDeOrdenamiento);
					if(validacionSort == -1)
					{
						printf("Error al ordenar.");
					}
				}

				printPassenger(pasajeros, largo);

				total = totalDeArray(pasajeros, largo);
				promedio = promedioDeArray(pasajeros, largo, total);
				cantidadMasPromedio = contadorMayorAlPromedio(pasajeros, largo, promedio);

				printf("La suma de todos los precios da %.2f y el promedio es %.2f, %d pasajeros superan ese promedio", total, promedio, cantidadMasPromedio);

				break;
			}
			case 5:
			{
				flagPasajeroIngresado = 1;
				idAux ++;
				strcpy(nameAux, "Mario");
				strcpy(lastNameAux, "Perez");
				priceAux = 2000;
				typePassengerAux = 1;
				strcpy(flycodeAux, "RGT-201");
				addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

				idAux ++;
				strcpy(nameAux, "Jose");
				strcpy(lastNameAux, "Garcia");
				priceAux = 3000;
				typePassengerAux = 2;
				strcpy(flycodeAux, "NHS-736");
				addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				idAux ++;
				strcpy(nameAux, "Ana");
				strcpy(lastNameAux, "Garcia");
				priceAux = 2;
				typePassengerAux = 3;
				strcpy(flycodeAux, "HG-111");
				addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);
				idAux ++;
				strcpy(nameAux, "Maria");
				strcpy(lastNameAux, "Von freshmint");
				priceAux = 330;
				typePassengerAux = 1;
				strcpy(flycodeAux, "VFT-431");
				addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

				idAux ++;
				strcpy(nameAux, "Benjamin");
				strcpy(lastNameAux, "Pintos");
				priceAux = 2000;
				typePassengerAux = 1;
				strcpy(flycodeAux, "OPT-201");
				addPassenger(pasajeros, largo, idAux, nameAux, lastNameAux, priceAux, typePassengerAux, flycodeAux);

				break;
			}
			case 6:
			{
				printf("Saliendo del sistema.");
				break;
			}
			default:
			{

				printf("\nOpcion no valida.\n");

				break;
			}
		}

	}while(respuesta != 6);

	return 0;
}
