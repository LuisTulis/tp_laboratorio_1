#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

#include "string.h"
#include "ctype.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{

	Passenger* nuevo;

	char idAux[50];
	char nombreAux[50];
	char apellidoAux[50];
	char precioAux[50];

	char flycodeAux[50];
	char tipoAux[50];

	char estadoAux[50];

	//char validacionApellido[50]; //Esta variable va en conjunto con la validacion de abajo
	// 							   descomentar en caso de utilizarla



	int r;
	int flagDatos = 0;

	if(pFile == NULL)
	{
		printf("El archivo no existe");
		exit(EXIT_FAILURE);
	}
	do
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,apellidoAux,precioAux,flycodeAux,tipoAux,estadoAux);
		if(r==7)
		{

			//      ESTA VALIDACION VA EN CASO DE ELIMINAR LOS CARACTERES ESPECIALES EN LOS APELLIDOS
			//sscanf(apellidoAux, "%[a-zA-Z ]", validacionApellido);
			//if(strcmp(apellidoAux,validacionApellido) == 0)
			{
				if(flagDatos != 0)
				{
						nuevo = Passenger_newParametros(idAux, nombreAux, apellidoAux, tipoAux, precioAux, flycodeAux, estadoAux);

						if(nuevo != NULL)
						{
							ll_add(pArrayListPassenger, nuevo);
						}
				}
			}
			flagDatos = 1;
		}

	}while(!feof(pFile));

	fclose(pFile);



    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int retorno = 1;
	Passenger* nuevo;// = Passenger_new();
	int cant;

	while(!feof(pFile))
	{
		retorno = 0;
		nuevo = Passenger_new();
		//Leo en binario y pongo los datos en lectura
		cant=fread(nuevo,sizeof(Passenger),1,pFile);
		if(cant!=1)
		{
			if(feof(pFile))
			{
				break;
			}
			else
			{
				printf("No leyo el ultimo registro");
				break;
			}
		}
		else
		{
			if(nuevo != NULL)
			{
				ll_add(pArrayListPassenger, nuevo);
			}
		}
	}


    return retorno;
}
