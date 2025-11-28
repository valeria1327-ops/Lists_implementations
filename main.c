#include <stdio.h>
#include "array_list.h"

int main() {
	
	// 3.1 Crear la lista con capacidad mínima de 3 elementos tipo int
	ArrayList* myArrayList = arrayList_create(3, sizeof(int));
	if (myArrayList == NULL) {
		printf("Error al crear la lista.\n");
		return 1;
	}
	
	// Elementos de ejemplo
	int a = 10, b = 20, c = 30, d = 40, e = 99;
	
	// 3.2 Agregar 4 elementos
	arrayList_add(myArrayList, &a);
	arrayList_add(myArrayList, &b);
	arrayList_add(myArrayList, &c);
	arrayList_add(myArrayList, &d);
	
	// Insertar 1 elemento (en posición 1)
	arrayList_insert(myArrayList, &e, 1);
	
	// 3.3 Obtener un elemento con get (posición 2)
	int value = (int) arrayList_get(myArrayList, 2);
	if (value != NULL) {
		printf("Elemento en la posición 2: %d\n", *value);
	}
	
	// 3.4 Remover 2 elementos
	arrayList_remove(myArrayList, 0);   // elimina el primero
	arrayList_remove(myArrayList, 1);   // elimina otro
	
	// 3.5 Destruir la lista
	arrayList_destroy(myArrayList);
	
	return 0;
}
