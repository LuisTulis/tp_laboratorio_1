/*
 * complementarTP.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luis
 */

#ifndef COMPLEMENTARTP_H_
#define COMPLEMENTARTP_H_

/** \brief  * Recorre todas las posiciones del array, tomando los valores y sumandolos
 * siempre y cuando su flag isEmpty no esté en -1
* \param valores Passenger* Lista de donde toma los valores
* \param longitud int Array length
* \return float Return devuelve el valor acumulado
*
*/
float totalDeArray(Passenger* valores, int longitud);

/** \brief  * Recorre todas las posiciones del array, aumentando un contador
 * siempre y cuando su flag isEmpty no esté en -1, para luego dividir el total por
 * el valor obtenido en el contador
* \param valores Passenger* Lista de donde toma los valores
* \param longitud int Array length
* \param total float total al cual dividir por el contador
* \return float Return devuelve el promedio conseguido
*
*/
float promedioDeArray(Passenger* valores, int longitud, float total);
/** \brief  * Recorre todas las posiciones del array, aumentando un contador
 * siempre y cuando su flag isEmpty no esté en -1 y el valor sea mayor al promedio
 * recibido
* \param valores Passenger* Lista de donde toma los valores
* \param longitud int Array length
* \param promedio float promedio con el cual comparar los valores
* \return float Return devuelve el precio acumulado
*
*/
int contadorMayorAlPromedio(Passenger* valores, int longitud, float promedio);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \param id int
* \return void
*
*/
void mostrarPasajero(Passenger* list, int len, int id);

#endif /* COMPLEMENTARTP_H_ */
