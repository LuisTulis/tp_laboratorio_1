#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	int option = 0;
	int flagGuardado = 1;
	int salir = 0;
	int contadorManual = 0;

	int flagDatosCargados = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{

    	utn_getNumeroEntero(&option,"\nQue opcion desea realizar?\n"
    							    "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
    								"\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
    								"\n3. Alta de pasajero"
    								"\n4. Modificar datos de pasajero"
    								"\n5. Baja de pasajero"
    								"\n6. Listar pasajeros"
    								"\n7. Ordenar pasajeros"
    								"\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
    								"\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
    								"\n10. Salir", "\nError, ingrese un numero.\n", 1, 10, 3);

    	fflush(stdin);

        switch(option)
        {
            case 1:
            	if(flagDatosCargados == 0)
            	{
            		flagDatosCargados = 1;
            		if(controller_loadFromText("data.csv",listaPasajeros)==1)
            		{
            			printf("\nSe cargaron los datos correctamente.\n");
						if(controller_CorregirIds(listaPasajeros, contadorManual)==0)
						{
							printf("Se modificaron los ID de los pasajeros cargados anteriormente");
						}
            		}
            		else
            		{
            			printf("\nHubo un error al abrir el archivo.\n");
            		}
            	}
            	else
            	{
            		printf("\nLa lista ya ha sido cargada anteriormente.\n");
            	}
            	flagGuardado = 0;
                break;
            case 2:
            	if(flagDatosCargados == 0)
				{
					flagDatosCargados = 1;
					if(controller_loadFromBinary("data.bin",listaPasajeros)==0)
					{
						printf("\nSe cargaron los datos correctamente.\n");
						if(controller_CorregirIds(listaPasajeros, contadorManual)==0)
						{
							printf("Se modificaron los ID de los pasajeros cargados anteriormente");
						}
					}
					else
					{
						printf("\nHubo un error al abrir el archivo.\n");
					}
				}
				else
				{
					printf("\nLa lista ya ha sido cargada anteriormente.\n");
				}
            	break;
            case 3:
            	if(controller_addPassenger(listaPasajeros)!=1)
            	{
            		printf("\nHubo un error al cargar el pasajero\n");
            	}
            	else
            	{
            		contadorManual++;
            	}
            	flagGuardado = 0;
            	break;
            case 4:
            	controller_editPassenger(listaPasajeros);
            	flagGuardado = 0;
            	break;
            case 5:
            	if(controller_removePassenger(listaPasajeros) == 0)
            	{
            		printf("\nNo se elimino al eliminar el pasajero.\n");
            	}
            	else
            	{
            		printf("\nPasajero eliminado correctamente.\n");
            		contadorManual--;
            	}
            	flagGuardado = 0;
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	break;
            case 7:
            	//Ordena las IDs, (en caso de que se hayan agregado pasajeros manualmente
            	//Antes de leer el archivo.
            	printf("Ordenando pasajeros, puede demorar unos segundos.");
            	if(controller_sortPassenger(listaPasajeros) == 0)
            	{
            		printf("\nLa lista ya estaba ordenada.\n");
            	}
            	else
            	{
            		printf("\nLista ordenada.\n");
            	}
            	flagGuardado = 0;
            	break;
            case 8:
            	// GUARDO LOS DATOS EN UN ARCHIVO DIFERNTE PARA NO MODIFICAR EL DADO EN EL TP
            	controller_saveAsText("data2.csv", listaPasajeros);
            	printf("\nDatos guardados\n");
            	flagGuardado = 1;
            	break;
            case 9:
            	controller_saveAsBinary("data.bin" , listaPasajeros);
            	printf("\nDatos guardados\n");
            	flagGuardado = 1;
            	break;
            case 10:
            	if(flagGuardado == 1)
            	{
            		printf("Saliendo del menu.");
            		ll_deleteLinkedList(listaPasajeros);
            		salir = 1;
            	}
            	else
            	{
            		printf("\nGuarde los datos antes de salir.\n");
            	}
            	break;
        }
    }while(salir != 1);



    return 0;
}

