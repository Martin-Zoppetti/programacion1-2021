#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"
#include "parser.h"
#include "UTN.h"

/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param this eLibro*
 * \return int retorna 1 si pudo y 0 si no lo logro
 *
 */
int libro_delete(eLibro* this)
{
	int retorno=0;
	if(this!=NULL)
	{
		free(this);
		retorno=1;
	}
	return retorno;
}

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo eLibro y deja todos sus campos inicializados
 *
 * \return eLibro* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
eLibro* libro_new(){
	eLibro* nuevoLibro = NULL;
	nuevoLibro = (eLibro*)malloc(sizeof(eLibro));
	if(nuevoLibro != NULL){
		libro_setId(nuevoLibro, 0);
		libro_setTitulo(nuevoLibro," ");
		libro_setAutor(nuevoLibro," ");
		libro_setPrecio(nuevoLibro,0);
		libro_setEditorial(nuevoLibro," ");
	}

	return nuevoLibro;
}

/** \brief reserva espacio de memoria dinamica para un elemento de tipo eLibro cargando en todos sus campos los datos pasados como parametros en formato de cadena de caracteres
 *
 * \param idStr char*
 * \param tituloStr char*
 * \param autorStr char*
 * \param precio char*
 * \param editorial char*
 * \return eLibro* retorna un puntero al lugar de la memoria asignado o devuelve NULL si no lo logro
 *
 */
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* editorialStr){
	eLibro* nuevoLibro = NULL;
	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL){

		nuevoLibro = libro_new();

		if(nuevoLibro != NULL){
			if(!libro_setId(nuevoLibro, atoi(idStr))||
					!libro_setTitulo(nuevoLibro,tituloStr)||
					!libro_setAutor(nuevoLibro,autorStr)||
					!libro_setPrecio(nuevoLibro,atoi(precioStr))||
					!libro_setEditorial(nuevoLibro,editorialStr)){
				libro_delete(nuevoLibro);
				nuevoLibro = NULL;

			}

		}
	}
	return nuevoLibro;
}

//COMPARACION

/** \brief Compara a los libros del LinkedList por su autor
 *
 * \param libro1 void*
 * \param libro2 void*
 * \return int retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int libro_compareByAutor(void* libro1, void* libro2)
{
	int retorno;
	char autor1[128];
	char autor2[128];
	if(libro1 != NULL && libro2 != NULL){
		libro_getAutor((eLibro*)libro1,autor1);
		libro_getAutor((eLibro*)libro2,autor2);
		if(strcmp(autor1,autor2)>0){
			retorno = -1;
		}
		else if(strcmp(autor1,autor2)<0){
			retorno = 1;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
//MAP
//* Planeta: 20% (si el monto es mayor o igual a $300)
//* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)

/** \brief calcula y aplica un descuento a los precios de los libros en base a su editorial
 *
 * \param void* this
 * \return int retorna 1 si pudo y -1 si no lo logro
 */
int calcularDescuento(void* this)
{

	int retorno = -1;
	char editorial[128];
	int precio;
	if(this != NULL){
		libro_getEditorial((eLibro*)this,editorial);
		libro_getPrecio((eLibro*)this,&precio);

		if(strcmp(editorial,"Planeta") == 0)
		{
			if(precio >= 300){
				precio = (precio * 0.8);
				libro_setPrecio(this,precio);
			}

		}
		else if(strcmp(editorial,"SIGLO XXI EDITORES") == 0)
		{
			if(precio <= 200){
				precio = (precio * 0.9);
				libro_setPrecio(this,precio);
			}
		}
	 retorno = 1;
	}
	return retorno;
}
/*
 * static int filterMultiplayer(void* this)
{
	int status = FALSE;
	Arcade* aux = (Arcade*) this;
	int playerAux;

	if(aux != NULL)
	{
		arc_getPlayers(aux, &playerAux);
		if(playerAux > 1)
		{
			status = TRUE;
		}
	}

	return status;
}
 *
 *
 *
 */


int filtroEitorial (void* element){
	int retorno=0;


	char auxiliar[128];
	char editorialAux[128]="Minotauro";
	if(element!=NULL){
		eLibro* aux=(eLibro*) element;


		libro_getEditorial(element, auxiliar);
		if(strcmp(auxiliar,editorialAux)==0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int filtroAutor(void* element){
	int retorno=0;


	char auxiliar[128];
	char AutorAux[128];
	if(element!=NULL){
		eLibro* aux=(eLibro*) element;

		setNombre(AutorAux, 2);
		libro_getEditorial(element, auxiliar);
		if(strcmp(auxiliar,AutorAux)==0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

//MOSTRAR

/** \brief Imprime por pantalla un unico libro
 *
 * \param this eLibro*
 * \return int retorna 1 si pudo y 0 si no lo logro
 *
 */
int mostrarUnLibro(eLibro* libro, int indice){
	int retorno = 0;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	char editorial[128];

	if(libro != NULL && indice >=0){
		libro_getId(libro,&id);
		libro_getTitulo(libro,titulo);
		libro_getAutor(libro,autor);
		libro_getPrecio(libro,&precio);
		libro_getEditorial(libro,editorial);
		printf("%-10d  %-50s                  %-20s         %-5d        %-5s \n",id,titulo,autor,precio,editorial);
		retorno = 1;
	}
	return retorno;
}

//SETTERS Y GETTERS
int libro_setId(eLibro* this, int id)
{
	int retorno=0;
	if(this!=NULL && id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int libro_getId(eLibro* this, int* id)
{
	int retorno=0;
	if(this!=NULL)
	{
		*id = this->id;
		retorno=1;
	}
	return retorno;
}

int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno=0;
	if(this!=NULL && titulo!=NULL && strlen(titulo)>1 && strlen(titulo)<128)
	{
		strcpy(this->titulo,titulo);

		retorno=1;
	}
	return retorno;
}
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno=0;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		retorno=1;
	}
	return retorno;
}

int libro_setAutor(eLibro* this,char* autor)
{
	int retorno=0;
	if(this!=NULL &&  autor!=NULL && strlen( autor)>1 && strlen( autor)<30)
	{
		strcpy(this->autor, autor);

		retorno=1;
	}
	return retorno;
}
int libro_getAutor(eLibro* this,char*  autor)
{
	int retorno=0;
	if(this!=NULL &&  autor!=NULL)
	{
		strcpy( autor,this-> autor);
		retorno=1;
	}
	return retorno;
}

int libro_setPrecio(eLibro* this, int precio)
{
	int retorno=0;
	if(this!=NULL && precio>0)
	{
		this->precio=precio;
		retorno=1;
	}
	return retorno;
}

int libro_getPrecio(eLibro* this, int* precio)
{
	int retorno=0;
	if(this!=NULL)
	{
		*precio = this->precio;
		retorno=1;
	}
	return retorno;
}

int libro_setEditorial(eLibro* this,char* editorial)
{
	int retorno=0;
	if(this!=NULL &&  editorial!=NULL && strlen( editorial)>1 && strlen( editorial)<30)
	{
		strcpy(this->editorial, editorial);

		retorno=1;
	}
	return retorno;
}
int libro_getEditorial(eLibro* this,char*  editorial)
{
	int retorno=0;
	if(this!=NULL &&  editorial!=NULL)
	{
		strcpy(editorial,this-> editorial);
		retorno=1;
	}
	return retorno;
}
