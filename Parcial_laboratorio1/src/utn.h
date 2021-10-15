/*
 * utn.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Eliana
 */

#ifndef UTN_H_
#define UTN_H_
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @fn int utn_getNumero(int*, char*, char*, int, int, int)
/// @brief Funcion para pedir un numero por consola
/// @param pResultado Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param minimo Valor mínimo admitido (inclusive)
/// @param maximo Valor máximo admitido (inclusive)
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 0 si salio todo ok, sino 1
int ObtenerEntero( int* pResultado,char mensaje[],char mensajeError[],int minimo,int maximo,int reintentos);

/// @fn int ObtenerDecimal(float*, char[], char[], float, float, int)
/// @brief Funcion para pedir un numero decimal por consola
/// @param pResultado Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param minimo Valor mínimo admitido
/// @param maximo Valor máximo admitido
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 0 si salio todo ok, sino 1
int ObtenerDecimal( float* pResultado,char mensaje[], char mensajeError[], float minimo, float maximo,int reintentos);

/// @fn int ObtenerCaracterDosOpciones(char*, char[], char[], char, char, int)
/// @brief Funcion que pedira el ingreso de un caracter
/// @param pResultado Puntero a variable donde se escribirá el valor del caracter ingresado en caso de ser correcto
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param mensajeError Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param opcion1 Un caracter opcional
/// @param opcion2 segundo caracter opcional
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 0 si salio todo ok, sino 1
int ObtenerCaracterDosOpciones( char* pResultado,char mensaje[], char mensajeError[], char opcion1, char opcion2, int reintentos);

/// @fn int ObtenerPalabras(char[], char[], char[], int)
/// @brief Funcion que pedira solo el ingreso de cadena de caracteres
/// @param texto Puntero a variable donde se escribirá el valor de la cadena de caracteres en caso de ser correcto
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 0 si salio todo ok, sino 1
int ObtenerPalabras(char texto[], char mensaje[], char mensajeError[], int reintentos);

/// @fn int FormatearCadena(char[])
/// @brief Funcion que se encargara de poner en minuscula toda la cadena de caracteres para luego poner en mayuscula el primer caracter y los que esten luego del espacio
/// @param cadena Puntero a cadena de caracteres que va a formatearse
/// @return Devuelve 1 si se realizo el formateo y 0 si no lo hizo
int FormatearCadena(char cadena[]);

/// @fn int ObtenerCuitCuil(char[], char[], char[], int)
/// @brief  Funcion que se encargara de copiar en la direccion de memoria de texto una vez que haya verificado la estructura de un cuit
/// @param texto puntero a direccion de memoria donde se guardara la cadena de caracteres ingresado
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 1 si se realizo el formateo y 0 si no lo hizo
int ObtenerCuitCuil(char texto[], char mensaje[], char mensajeError[], int reintentos);

/// @fn int ObtenerNumerosLetras(char[], char[], char[], int)
/// @brief Funcion que se encargara de permitir ingreso de una cadena de caracteres compuesta de letras y numeros
/// @param texto puntero a direccion de memoria donde se guardara la cadena de caracteres ingresado
/// @param mensaje Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
/// @param mensajeError Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param reintentos Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
/// @return Devuelve 1 si se realizo el formateo y 0 si no lo hizo
int ObtenerNumerosLetras(char texto[], char mensaje[], char mensajeError[], int reintentos);

/// @fn int FormatearCadenaConNumeros(char[])
/// @brief Funcion que se encargara de poner el mayuscula el primer caracter y el resto como minuscula aceptando numeros
/// @param cadena Puntero a cadena de caracteres que va a formatearse
/// @return Devuelve 1 si se realizo el formateo y 0 si no lo hizo
int FormatearCadenaConNumeros(char cadena[]);

#endif /* UTN_H_ */
