/*
 * complementarTP.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luis
 */

#ifndef COMPLEMENTARTP_H_
#define COMPLEMENTARTP_H_

float totalDeArray(Passenger* valores, int longitud);

float promedioDeArray(Passenger* valores, int longitud, float total);

int contadorMayorAlPromedio(Passenger* valores, int longitud, float promedio);

void mostrarPasajero(Passenger* list, int len, int id);

#endif /* COMPLEMENTARTP_H_ */
