/*
 * aerolinea.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Tulis Curra Luis, DIV D
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_


///@fn opcion2(char, float, float)
///@brief Permite al usuario decidir que a que aerolinea ingresarle el precio del vuelo
///
///@param respuestaOpcion2, precioLatam, precioAerolineas

void opcion2(char respuestaOpcion2, float* precioLatam, float* precioAerolineas);

///@fn opcion3(float, float, float, float, float, float, float, float, float, float, float, float)
///@brief Realiza los calculos utilizando las variables kilometros, precioLatam y precioAerolineas
///
///@param kilometros, precioLatam, precioAerolineas, precioDebitoLatam, precioDebitoAerolineas, precioCreditoLatam, precioCreditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioUnitarioLatam, precioUnitarioAerolineas, diferenciaPrecios

void opcion3(float kilometros, float precioLatam, float precioAerolineas, float* precioDebitoLatam, float* precioDebitoAerolineas, float* precioCreditoLatam, float* precioCreditoAerolineas, float* precioBitcoinLatam, float* precioBitcoinAerolineas, float* precioUnitarioLatam, float* precioUnitarioAerolineas, float* diferenciaPrecios);

///@fn opcion4(float, float, float, float, float, float, float, float, float, float)
///@brief Muestra los datos recibidos de la opcion3
///
///@param kilometros, precioDebitoLatam, precioDebitoAerolineas, precioCreditoLatam, precioCreditoAerolineas, precioBitcoinLatam, precioBitcoinAerolineas, precioUnitarioLatam, precioUnitarioAerolineas, diferenciaPrecios

void opcion4(float kilometros, float precioDebitoLatam, float precioDebitoAerolineas, float precioCreditoLatam, float precioCreditoAerolineas, float precioBitcoinLatam, float precioBitcoinAerolineas, float precioUnitarioLatam, float precioUnitarioAerolineas, float diferenciaPrecios);





#endif /* AEROLINEA_H_ */
