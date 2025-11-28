#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct{
	void **data; //aqui se almacenan los elementos genericos
	int size; //numero de elementos que tiene la lista almacenados
	int capacity; //capacidad maxima de objetos que puede almacenar la lista
	int element_size; //tamaño con byts de cada elemento
} ArrayList;

//constrtuctor y destructor
//constructor -> inicializar variables en sus valores por defecto y pide memoria para almacenarse
//destructor -> realiza las liberaciones de memoria para el 05 pueda volver a usarla

ArrayList* arrayList_create(int initial_capacity, int element_size);
void arrayList_destroy(ArrayList *list);

//operationes basicas que toda lista debe llevar
void arrayList_add(ArrayList *list, void *element); //agrega un elemneto al final de la lista
void arrayList_insert(ArrayList *list, void *element, int index); //agrega un elemneto a la posicion
void *arrayList_get(ArrayList *list, int index); //obtenemos el elemneto en la posicion index de la lista
void arrayList_remove(ArrayList *list, int index);
void arrayList_clear(ArrayList * list);

void arrayList_ensure_capasity(ArrayList * list, int min_capacity);
void arrayList_trim_to_size(ArrayList * list);
ArrayList* arrayList_clone(ArrayList * list);



#endif
