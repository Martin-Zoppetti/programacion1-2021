#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "UTN.h"
#include "libro.h"

int main()
{
	setbuf(stdout,NULL);

	int option = 0;
	int cargaDeAchivoDatos=0;

	char confirmar;
	char sobreescribir;
	LinkedList* listalibrosEditoriales;
	LinkedList* listalibrosMapeados;
	LinkedList* listalibrosAutor;
	LinkedList* listalibros = ll_newLinkedList();
	do{
		switch(menuOpciones())
		{
		case 1:
			if (!ll_isEmpty(listalibros))
			{
				UTN_getCaracter(&sobreescribir,"Ya tiene una lista cargada, al continuar sobreescribira la lista.\n Desea continuar? (s/n): ","ERROR!!! \n", 'n', 's', 5);
				if (sobreescribir == 's')
				{
					ll_clear(listalibros);
				}
				else{
					break;
				}

			}
			if (controller_loadFromText("Datos.csv", listalibros))
			{
				cargaDeAchivoDatos = 1;
				printf("Se cargaron los datos de los libros con exito!!! \n");

			} else
			{
				printf("No se puedieron cargar los datos de los libros... \n");
			}
			//getchar();
			break;
		case 2:	if(!ll_isEmpty(listalibros)){
			controller_sortlibro(listalibros);
		}
		else{
			printf("Debe tener a los libros cargados para poder ordenarlos, esto es posible en la opcion 1 del menu.\n");
		}
		//getchar();

			break;
		case 3:
			if(!ll_isEmpty(listalibros)){
				controller_Listlibro(listalibros);
			}
			else{
				printf("Debe tener a los libros cargados para poder listarlos, esto es posible en la opcion 1 del menu.\n");
			}
		//	getchar();
			break;
		case 4:
			if(cargaDeAchivoDatos)
			{
				listalibrosMapeados=controller_ll_map(listalibros);

				if(listalibrosMapeados!=NULL){
						printf("Descuentos aplicados con exito!!!\n");
					cargaDeAchivoDatos = 0;
				}
				else{
					printf("No se pudieron aplicar los descuentos.\n");
				}
			}
			else
			{
				printf("No es posible realizar la operacion, para aplicar los descuentos tiene que tener cargada la lista sin descuentos primero, esto es posible en la opcion 1 del menu.\n");
			}

			break;
		case 5:

			if(controller_generadorDeArchivos("mapeado.csv", listalibrosMapeados)==1){

				controller_Listlibro(listalibrosMapeados);

printf("Seleccione un autor:\n");
				seleccionarAutor(listalibrosMapeados);
				listalibrosAutor=controller_ll_filterAutor(listalibrosMapeados);
				controller_generadorDeArchivos("Autores.csv", listalibrosAutor);
				controller_Listlibro(listalibrosAutor);
				listalibrosEditoriales=controller_ll_filter(listalibrosAutor);
				controller_generadorDeArchivos("minotauroLibros.csv", listalibrosEditoriales);

				controller_Listlibro(listalibrosEditoriales);


			}
			/*
			 * 5) Generar el archivo de salida: mapeado.csv
			 *  ACLARACION: Se deberá poder filtrar la lista por el autor.
			 *  1) Desarrollar la función ll_filter en la biblioteca linkedList, la cual recibirá la lista y una función. Esta deberá filtrar la lista por la editorial MINOTAURO.
			 *  2) Generar el archivo de salida: minotauroLibros.csv
			 */


			break;
		case 6:
			UTN_getCaracter(&confirmar,"Esta seguro que quiere salir del programa? (s/n): ","ERROR!!! \n",'n','s',5);
			if(confirmar == 's'){
				option = 6;
			}
			break;
		}
	}while(option != 6);
	ll_deleteLinkedList(listalibros);
	printf("Se cierra el menu.\n");
	return 0;
}
