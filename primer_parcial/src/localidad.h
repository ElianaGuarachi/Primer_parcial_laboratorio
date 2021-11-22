/*
 * localidad.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Eliana
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int idLocalidad;
	char nombreLocalidad[51];
	int isEmpty;

}eLocalidad;

/// @fn int InicializarListaLocalidades(eLocalidad[], int)
/// @brief Funcion que pone en estado libre a la estructura de localidades
/// @param localidades Puntero a estructura de localidades
/// @param cantidad tamanio del array de localidades
/// @return Devuelve -1 si es NULL o 1 si inicializo el array
int InicializarListaLocalidades(eLocalidad localidades[], int cantidad);

/// @fn int VerificarIdLocalidadIngresado(eLocalidad[], int, int)
/// @brief Funcion que verifica que el id ingresado este en la estructura de localidades
/// @param localidades Puntero a estructura de localidades
/// @param cantidad tamanio del array de localidades
/// @param id Copia del id ingresado para buscar
/// @return Devuelve -1 si es NULL o 1 si encontro el id que buscaba en la lista
int VerificarIdLocalidadIngresado(eLocalidad localidades[], int cantidad, int id);

/// @fn int MostrarListaDeLocalidades(eLocalidad[], int)
/// @brief Funcion que muestra la lista de localidades
/// @param localidades Puntero a estructura de localidades
/// @param cantidad tamanio del array de localidades
/// @return Devuelve -1 si es NULL o 0 si es ok
int MostrarListaDeLocalidades(eLocalidad localidades[], int cantidad);

/// @fn void MostrarInfoUnaLocalidad(eLocalidad)
/// @brief Funcion que muestra la informacion de una estructura de localidad
/// @param localidad estructura de localidad
void MostrarInfoUnaLocalidad(eLocalidad localidad);

/// @fn int BuscarLocalidadPorId(eLocalidad[], int, int)
/// @brief Funcion una localidad por el id
/// @param localidades Puntero a estructura de localidades
/// @param cantidad tamanio del array de localidades
/// @param id Pasaje por valor del id que se busca
/// @return Devuelve -1 si es NULL o el index del id
int BuscarLocalidadPorId(eLocalidad localidades[], int cantidad, int id);

#endif /* LOCALIDAD_H_ */
