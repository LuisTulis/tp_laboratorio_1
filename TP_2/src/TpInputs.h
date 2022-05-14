/*
 * TpInputs.h
 *
 *  Created on: 11 may. 2022
 *      Author: Luis
 */

#ifndef TPINPUTS_H_
#define TPINPUTS_H_
/** \brief  *Recibe una variable y permite al usuario rellenarla
* \param variableRecibida int* Variable a rellenar
* \param textoAMostrar[] char texto inicial
* \return float Return devuelve el promedio conseguido
*
*/
void rellenarArray(char arrayRecibido[], char textoAMostrar[]);
/** \brief  *Recibe una variable y permite al usuario rellenarla
* \param variableRecibida int* Variable a rellenar
* \param textoAMostrar[] char texto inicial
* \param textoError[] char texto en caso de ingresar un valor no numerico
* \return float Return devuelve el promedio conseguido
*
*/
void rellenarInt(int* variableRecibida, char textoAMostrar[], char textoError[]);
/** \brief  *Recibe una variable y permite al usuario rellenarla
* \param variableRecibida float* Variable a rellenar
* \param textoAMostrar[] char texto inicial
* \param textoError[] char texto en caso de ingresar un valor no numerico
* \return float Return devuelve el promedio conseguido
*
*/
void rellenarFloat(float* variableRecibida, char textoAMostrar[], char textoError[]);

#endif /* TPINPUTS_H_ */
