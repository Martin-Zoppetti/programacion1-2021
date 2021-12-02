#include <stdio.h>
#include <stdlib.h>
#include "libro.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaLibros LinkedList*
 * \return int
 *
 */

int parser_libroFromText(FILE* pFile , LinkedList* pListaLibros)
{
	int retorno = 0;
	int cantidad;
	char buffer1[1024];
	char buffer2[1024];
	char buffer3[1024];
	char buffer4[1024];
	char buffer5[1024];

	eLibro* nuevoLibro;

	if(pFile != NULL &&  pListaLibros != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4,buffer5);

		while(!feof(pFile)) //RECORRO HASTA QUE LEA CADA LINEA DEL ARCHIVO
		{

			cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4,buffer5);

			if( cantidad < 5){ //VERIFICO QUE HAYA PODIDO LEVANTAR CADA CAMPO
				retorno = 1;
				break;
			}
			nuevoLibro = libro_newParametros(buffer1,buffer2,buffer3,buffer4,buffer5);//CONSTRUYO UN NUEVO LIBRO
			if(nuevoLibro != NULL){
				ll_add(pListaLibros, nuevoLibro);//AGREGO AL LINKEDLIST
				retorno = 1;
			}
		}

	}
	return retorno;
}
