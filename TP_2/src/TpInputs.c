/*
 * TpInputs.c
 *
 *  Created on: 11 may. 2022
 *      Author: Luis
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>


void rellenarInt(int* variableRecibida, char textoAMostrar[], char textoError[])
{
	*variableRecibida = 0;
	printf(textoAMostrar);
	scanf("%d", variableRecibida);
	fflush(stdin);

	while(*variableRecibida == 0)
	{
		printf(textoError);
		scanf("%d", variableRecibida);
		fflush(stdin);
	}

}


void rellenarFloat(float* variableRecibida, char textoAMostrar[], char textoError[])
{
	printf(textoAMostrar);
	scanf("%f", variableRecibida);
	fflush(stdin);

	while(*variableRecibida == 0)
		{
			printf(textoError);
			scanf("%f", variableRecibida);
			fflush(stdin);
		}

}

void rellenarArray(char arrayRecibido[], char textoAMostrar[])
{
	printf(textoAMostrar);
	gets(arrayRecibido);
	fflush(stdin);
}
