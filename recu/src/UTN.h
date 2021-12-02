/*
 * UTN.h
 *
 *  Created on: 2 dic. 2021
 *      Author: MariaElena
 */

#ifndef SRC_UTN_H_
#define SRC_UTN_H_




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int menuDePunto5();
/// @brief imprime por pantalla una lista de opciones de informes, le pide al usuario que ingrese una opcion y la retorna
///
/// @return int retorna la opcion ingresada si puedo guardarla, devuelve -1 si no lo logro
//int menuOrdenamiento(void);
///////////////////////////////////////////////////////////////////////
//int menuOrder(void);
///////////////////////////////////////////////////////////////////////
/// @brief imprime por pantalla una lista de opciones, le pide al usuario que ingrese una opcion y la guarda en una variable
///
/// @param opcion int* direccion de memoria donde se guarda la opcion
/// @return int retorna 1 si pudo guardar la opcion y -1 si no lo logro
int menuOpciones();

/// @brief imprime por pantalla una lista de opciones de modificacion, le pide al usuario que ingrese una opcion y la retorna
///
/// @return int retorna la opcion ingresada si pudo guardarla, devuelve -1 si no lo logro
int menuModificaciones(void);


/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 1 si se obtuvo el numero o -1 si no
 *
 */
int UTN_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param minimo int El numero minimo a ser aceptado
/// @param maximo int El numero maximo a ser aceptado
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int UTN_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param opcion1 char primera opcion a ser aceptada
/// @param opcion2 char segunda opcion a ser aceptada
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int UTN_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos);

/// @brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
/// @param mensaje char* El mensaje a ser mostrado
/// @param mensajeError char* El mensaje de error a ser mostrado
/// @param sizeNombre int tamaño limite
/// @param reintentos int Cantidad de reintentos permitidos
/// @return int Retorna 1 si se obtuvo el numero o -1 si no
int UTN_getString(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);



#endif /* UTN_H_ */

