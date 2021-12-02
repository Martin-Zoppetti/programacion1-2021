#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "UTN.h"
#include "libro.h"

/** \brief Carga los datos de los libros desde un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */

int seleccionarAutor(LinkedList* pLinkedListElementos){
	int estado;
	int retorno=-1;
	if(controller_imprimirAutorSinRepetir(pLinkedListElementos)==0){
	if(UTN_getNumero(&estado, "\nIngrese el Numero de autor: ","\n Dato erroneo", 1, 9, 5)==0){
	char auxAutor[128];

		switch (estado)
		{
			case 1:
				strncpy(auxAutor,"Pigna",sizeof(auxAutor));
				break;
			case 2:
				strncpy(auxAutor,"Paenza",sizeof(auxAutor));

				break;
			case 3:
				strncpy(auxAutor,"Deitel & Deitel",sizeof(auxAutor));
				break;
			case 4:
				strncpy(auxAutor,"Tolkien",sizeof(auxAutor));
				break;
			case 5:
				strncpy(auxAutor,"Rowling",sizeof(auxAutor));
				break;
			case 6:
				strncpy(auxAutor,"Collodi Carlo",sizeof(auxAutor));
				break;
			case 7:
				strncpy(auxAutor,"Baum Frank",sizeof(auxAutor));
				break;
			case 8:
				strncpy(auxAutor,"Swift Jonathan",sizeof(auxAutor));
				break;
			case 9:
				strncpy(auxAutor,"Carroll Lewis",sizeof(auxAutor));
				break;

		}

		setNombre(auxAutor, 1);

		retorno=0;
	}
	}

return retorno;
}



int setNombre(char* nombre, int opcion){
	static char nombreaux[50]="";
	int retorno=0;

	if(nombre!=NULL && (opcion==1 || opcion==2) ){
	switch (opcion) {
		case 1:
			strcpy(nombreaux,nombre);
			retorno=1;
			break;
		case 2:
			strcpy(nombre,nombreaux);
			retorno=1;
			break;
	}
	}
	return retorno;
}

int controller_imprimirAutorSinRepetir(LinkedList* pLinkedListElementos)
{
	int i;
	int j;
	int banderaHayIgualdad;
	eLibro* pAutorUNO;
	eLibro* pAutorDos;
	char nombreAutorUno[128];
	char nombreAutorDos[128];
	int retorno = -1;
	if(pLinkedListElementos != NULL)
	{
		retorno = 0;
		for(i = 0; i < ll_len(pLinkedListElementos); i++)
		{
			pAutorUNO = (eLibro*)ll_get(pLinkedListElementos, i);
			if(pAutorUNO != NULL)
			{
				if( libro_getAutor(pAutorUNO, nombreAutorUno))
				{
					banderaHayIgualdad = 0;
					for(j = 0; j < i ; j++)
					{
						pAutorDos = (eLibro*)ll_get(pLinkedListElementos, j);
						if(pAutorDos != NULL)
						{
							if( libro_getAutor( pAutorDos, nombreAutorDos))
							{
								if(strncmp(nombreAutorUno, nombreAutorDos, sizeof(nombreAutorUno)) == 0)
								{
									banderaHayIgualdad = 1;
									break;
								}
							}
						}
					}
					if(banderaHayIgualdad == 0)
					{
						printf("\n%s", nombreAutorUno);
					}
				}
			}
		}
	}
	return retorno;
}




int controller_loadFromText(char* path , LinkedList* pListaLibros)
{
	int retorno = 0;
	FILE* auxP;
	if(path != NULL && pListaLibros != NULL){
		auxP = fopen(path,"r");//LO LEO
		if(auxP != NULL){

			parser_libroFromText(auxP ,pListaLibros);
			retorno = 1;
		}
		else{

			printf("No se pudo leer el archivo");
		}
		fclose(auxP);
	}

	return retorno;
}

/** \brief Listar libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */
int controller_Listlibro(LinkedList* pListaLibros)
{
	int retorno = 0;
	eLibro* libro;
	if(pListaLibros != NULL){
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("                       LISTA DE LIBROS                                                                                                      \n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID          TITULO                                                              AUTOR                        PRECIO       EDITORIAL         \n");
		for(int i= 0; i<ll_len(pListaLibros);i++){
			libro = (eLibro*)ll_get(pListaLibros,i);
			mostrarUnLibro(libro, i);
		}
		retorno = 1;
	}
	return retorno;
}

/** \brief Ordenar libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */

int controller_sortlibro(LinkedList* pListaLibros)
{
	int retorno = -1;
	int order=0;
	if(pListaLibros != NULL){
		if(!ll_sort(pListaLibros,libro_compareByAutor,order)){
			retorno = 0;
			printf("------Lista ordenada------\n");
		}
		else{
			printf("Hubo algun problema al ordenar la lista\n");
		}


	}
	return retorno;
}

/** \brief Mapear Libros
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */
LinkedList* controller_ll_map( LinkedList* pListaLibros){
	LinkedList* retorno = NULL;

	LinkedList* listaMapeada=NULL;
	if(pListaLibros != NULL)
	{
		listaMapeada = ll_map(pListaLibros,calcularDescuento);
if(listaMapeada!=NULL){
	retorno=listaMapeada;
}
	}

	return retorno;
}


int controller_generadorDeArchivos(char* path , LinkedList* listaMapeada){
	int retorno = 0;
	int id;
	char titulo[128];
	char autor[128];
	int precio;
	char editorial[128];

	FILE* pFile;
	eLibro* auxLibro;

		if(listaMapeada != NULL && path!=NULL){
			pFile  = fopen(path,"w");
			if(pFile != NULL)
			{
				fprintf(pFile,"id,Titulo,Autor,Precio,Editorial\n");

				for(int i = 0;i<ll_len(listaMapeada);i++)
				{
					auxLibro = (eLibro*) ll_get(listaMapeada,i);
					if(auxLibro != NULL)
					{
						if( libro_getId(auxLibro,&id) &&
							libro_getTitulo(auxLibro,titulo)&&
							libro_getAutor(auxLibro,autor)&&
							libro_getPrecio(auxLibro,&precio) &&
							libro_getEditorial(auxLibro,editorial))
						{
							fprintf(pFile,"%d,%s,%s,%d,%s\n",id,titulo,autor,precio,editorial);
							retorno = 1;
						}
					}
				}
					fclose(pFile);
			}
			else
			{
				printf("No se pudo escribir en el archivo \n");
			}
		}


	return retorno;
}

LinkedList* controller_ll_filter( LinkedList* pListaLibros){
	LinkedList* retorno = NULL;

	LinkedList* listaFiltrada=NULL;
	if(pListaLibros != NULL)
	{
		listaFiltrada = ll_filter(pListaLibros, filtroEitorial);
		if(listaFiltrada!=NULL){
			retorno=listaFiltrada;
		}
	}

	return retorno;
}


LinkedList* controller_ll_filterAutor( LinkedList* pListaLibros){
	LinkedList* retorno = NULL;

	LinkedList* listaFiltrada=NULL;
	if(pListaLibros != NULL)
	{
		listaFiltrada = ll_filter(pListaLibros, filtroAutor);
		if(listaFiltrada!=NULL){
			retorno=listaFiltrada;
		}
	}

	return retorno;
}

