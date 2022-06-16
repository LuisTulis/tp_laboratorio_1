#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#include "parser.h"
#include "ctype.h"
#include "string.h"
#include "utn.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int validarParseo = 0;

	pFile = fopen(path, "r");
	if(pFile != NULL)
	{
		validarParseo = parser_PassengerFromText(pFile, pArrayListPassenger);
	}
	fclose(pFile);

    return validarParseo;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int validarParseo = 0;

	pFile = fopen(path, "rb");
	if(pFile != NULL)
	{
		validarParseo = parser_PassengerFromBinary(pFile, pArrayListPassenger);
	}
	fclose(pFile);

	return validarParseo;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* nuevo;

	int idAux;
	char idStr[15];
	char nombreStr[15];
	char apellidoStr[15];
	int precioAux;
	char precioStr[15];
	int tipoAux;
	char tipoStr[15];
	char codigoStr[15];
	char estadoStr[15];

	idAux = Passenger_idDisponible(pArrayListPassenger);
	itoa(idAux, idStr, 10);

	utn_getCadena(nombreStr, "Ingrese el nombre del pasajero.");
	utn_getCadena(apellidoStr, "Ingrese el apellido del pasajero.");

	utn_getNumeroEntero(&precioAux,"Ingrese el precio del vuelo.", "\nError, ingrese un numero valido.\n", 1, 50000, 3);
	itoa(precioAux, precioStr, 10);

	utn_getNumeroEntero(&tipoAux,"Ingrese el tipo de pasajero\n"
	    							    "\n1- Clase economica."
	    								"\n2. Clase ejecutiva."
	    								"\n3. Primera clase.", "\nError, ingrese una opcion valida.\n", 1, 3, 3);
	fflush(stdin);
	switch(tipoAux)
	{
		case 1:
			strcpy(tipoStr,"EconomyClass");
			break;
		case 2:
			strcpy(tipoStr,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipoStr,"FirstClass");
			break;
	}

	utn_getCadena(codigoStr,"Ingrese el codigo de vuelo.");

	utn_getCadena(estadoStr,"Ingrese el estado de vuelo.");

	nuevo = Passenger_newParametros(idStr,nombreStr,apellidoStr,tipoStr,precioStr,codigoStr,estadoStr);
	if(nuevo != NULL)
	{
			printf("\nPasajero cargado correctamente.\nEl id correspondiente es %d\n", nuevo->id);
			retorno = 1;
			ll_add(pArrayListPassenger, nuevo);
	}


    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* aModificar;
	int idABuscar = -1;
	int index;
	int opcionMenu;

	char nombreModificar[15];
	char apellidoModificar[15];
	float precioModificar;
	int tipoModificar;
	char codigoModificar[15];

	utn_getNumeroEntero(&idABuscar,"Ingrese el id del pasajero\n", "\nId no encontrado\n", 1, ll_len(pArrayListPassenger), 1);
	if(idABuscar != -1)
	{

		aModificar = Passenger_busqueda(pArrayListPassenger, idABuscar);

		index = ll_indexOf(pArrayListPassenger, aModificar);
		aModificar = ll_get(pArrayListPassenger, index);

		printf("El usuario con ese ID es:\n");
		Passenger_print(aModificar);


		do{
			utn_getNumeroEntero(&opcionMenu,"Que desea modificar?\n"
											"\n1. Nombre"
											"\n2. Apellido"
											"\n3. Precio"
											"\n4. Tipo de pasajero"
											"\n5. Codigo de vuelo"
											"\n6. Salir", "\nError, ingrese un numero.\n", 1, 6, 3);
			fflush(stdin);
			switch(opcionMenu)
			{
				case 1:
					utn_getCadena(nombreModificar, "Ingrese el nombre del pasajero.");
					Passenger_setNombre(aModificar,nombreModificar);
					printf("Nombre modificado con exito");
					break;
				case 2:
					utn_getCadena(apellidoModificar, "Ingrese el apellido del pasajero.");
					Passenger_setApellido(aModificar,apellidoModificar);
					printf("Apellido modificado con exito");
					break;
				case 3:
					utn_getNumeroFlotante(&precioModificar,"Ingrese el precio del vuelo.", "\nError, ingrese un numero valido.\n", 1, 50000, 3);
					Passenger_setPrecio(aModificar,precioModificar);
					printf("Precio modificado con exito");
					break;
				case 4:
					utn_getNumeroEntero(&tipoModificar,"Ingrese el tipo de pasajero\n"
															"\n1- Clase economica."
															"\n2. Clase ejecutiva."
															"\n3. Primera clase.", "\nError, ingrese una opcion valida.\n", 1, 3, 3);
					Passenger_setTipoPasajero(aModificar,tipoModificar);
					printf("Tipo modificado con exito");
					break;
				case 5:
					utn_getCadena(codigoModificar, "Ingrese el codigo de vuelo.");
					Passenger_setCodigoVuelo(aModificar,codigoModificar);
					printf("Codigo de vuelo modificado con exito");
					break;
				case 6:
					printf("Saliendo al menu");
					break;
			}
		}while(opcionMenu != 6);
	}
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int idABuscar;
	Passenger* aEliminar;
	Passenger* Confirmacion;
	int index;
	int respuesta;
	utn_getNumeroEntero(&idABuscar,"Ingrese el id del pasajero\n", "\nId no encontrado\n", 1, ll_len(pArrayListPassenger), 1);
	if(idABuscar != -1)
	{

		aEliminar = Passenger_busqueda(pArrayListPassenger, idABuscar);

		index = ll_indexOf(pArrayListPassenger, aEliminar);
		aEliminar = ll_get(pArrayListPassenger, index);

		printf("El usuario con ese ID es:\n");
		Passenger_print(aEliminar);
		utn_getNumeroEntero(&respuesta,"Seguro que desea eliminarlo?\n 1- Si \n 2- No", "\nOpcion no valida\n", 1, 2, 3);

		if(respuesta == 1)
		{
			Confirmacion = ll_pop(pArrayListPassenger, index);
			retorno = 1;
			printf("\nEl usuario ha sido eliminado.\n");
			utn_getNumeroEntero(&respuesta,"Los datos se perderan para siempre, ¿está seguro de querer eliminarlo?\n 1- Si \n 2- No", "\nOpcion no valida\n", 1, 2, 3);

			if(respuesta == 2)
			{
				ll_push(pArrayListPassenger, index, Confirmacion);
				retorno = 0;
			}

		}


	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger != NULL)
	{
		Passenger_list(pArrayListPassenger);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;

	ll_sort(pArrayListPassenger, ordenamientoId, 1);

    return retorno;
}



/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	int retorno;
	pFile = fopen(path, "w");
	if(pFile == NULL)
	{
		printf("\nNo se puedo abrir el archivo.\n");
		retorno = 0;
	}

	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char flycode[8];
	char tipoPasajeroAux[15];
	int tipoPasajero;
	char statusFlight[15];

	Node* indice = pArrayListPassenger->pFirstNode;

	fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s\n", "id", "name", "lastname", "price", "flycode", "typePassenger", "statusFlight");
	for(; indice != NULL; indice = indice->pNextNode)
	{
		Passenger_getId(indice->pElement, &id);
		Passenger_getNombre(indice->pElement, nombre);
		Passenger_getApellido(indice->pElement, apellido);
		Passenger_getPrecio(indice->pElement, &precio);
		Passenger_getCodigoVuelo(indice->pElement, flycode);
		Passenger_getTipoPasajero(indice->pElement, &tipoPasajero);
		Passenger_getEstadoVuelo(indice->pElement, statusFlight);

		switch(tipoPasajero)
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


		fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n", id, nombre, apellido, precio, flycode, tipoPasajeroAux, statusFlight);

	}
	fclose(pFile);

	return retorno;


    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int retorno;
	pFile = fopen(path, "wb");
	if(pFile == NULL)
	{
		printf("\nNo se puedo abrir el archivo.\n");
		retorno = 0;
	}

	Node* indice = pArrayListPassenger->pFirstNode;

	for(; indice != NULL; indice = indice->pNextNode)
	{
		fwrite(indice->pElement,sizeof(Passenger),1,pFile);
	}
	fclose(pFile);

	return retorno;

}



/** \brief Lee la lista y corrige los IDs cargados manualmente.
 *
 * \param pArrayListPassenger LinkedList*
 * \path int contador
 * \
 * \return int
 *
 */
int controller_CorregirIds(LinkedList* pArrayListPassenger, int contador)
{
	int retorno = 0;
	int i;
	Passenger* aux;
	int ultimaId = Passenger_idDisponible(pArrayListPassenger);

	if(contador == 0)
	{
		retorno = 1;
	}
	else
	{
		for(i = 0; i < contador; i++)
		{
			aux = ll_get(pArrayListPassenger, i);
			Passenger_setId(aux,(ultimaId+i-contador));
			ll_set(pArrayListPassenger, i, aux);
		}
	}

	return retorno;
}

