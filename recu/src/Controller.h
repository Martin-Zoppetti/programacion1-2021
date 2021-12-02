int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);

int controller_sortlibro(LinkedList* pListaLibros);

int buscarEmpleadoId(int* idABuscar, LinkedList* pArrayListEmployee,int tam);
LinkedList* controller_ll_map( LinkedList* pListaLibros);
int controller_generadorDeArchivos(char* path , LinkedList* listaMapeada);
int controller_Listlibro(LinkedList* pListaLibros);
int setNombre(char* nombre, int opcion);
int controller_imprimirAutorSinRepetir(LinkedList* pLinkedListElementos);
LinkedList* controller_ll_filterAutor( LinkedList* pListaLibros);
LinkedList* controller_ll_filter( LinkedList* pListaLibros);
int seleccionarAutor(LinkedList* pLinkedListElementos);
