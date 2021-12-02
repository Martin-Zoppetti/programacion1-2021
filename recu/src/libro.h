#ifndef libro_H_INCLUDED
#define libro_H_INCLUDED
typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int precio;
    char editorial[128];
}eLibro;

//CONSTRUCTORES
eLibro* libro_new();
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr,char* editorialStr);


int calcularDescuento(void* this);
int mostrarUnLibro(eLibro* libro, int indice);
int libro_delete(eLibro* this);
//COMPARADOR
int libro_compareByAutor(void* book1, void* book2);

//SETTERS Y GETTERS
int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char*  titulo);

int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);

int libro_setPrecio(eLibro* this,int precio);
int libro_getPrecio(eLibro* this,int* precio);

int libro_setEditorial(eLibro* this,char* editorial);
int libro_getEditorial(eLibro* this,char* editorial);

int filtroEitorial (void* element);
int filtroAutor(void* element);


#endif // libro_H_INCLUDED
