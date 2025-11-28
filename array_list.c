#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

#define DEFAULT_CAPACITY 10
#define GROWTH_FACTOR 2

ArrayList* arrayList_create(int initial_capacity, int element_size) {
	if (initial_capacity <= 0) {
		initial_capacity = DEFAULT_CAPACITY;
	}
	
	ArrayList list = (ArrayList) malloc(sizeof(ArrayList));
	if (!list) {
		printf("No se pudo asignar memoria para la lista\n");
		return NULL;
	}
	
	list->data = (void*) malloc(sizeof(void) * initial_capacity);
	if (!list->data) {
		free(list);
		printf("No se pudo asignar memoria para los datos\n");
		return NULL;
	}
	
	list->size = 0;
	list->capacity = initial_capacity;
	list->element_size = element_size;
	
	return list;
}

void arrayList_destroy(ArrayList *list) {
	if (!list) return;
	
	arrayList_clear(list);
	free(list->data);
	free(list);
}

void arrayList_add(ArrayList *list, void *element) {
	if (!list || !element) return;
	
	if (list->size >= list->capacity) {
		arrayList_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
	}
	
	list->data[list->size] = malloc(list->element_size);
	if (!list->data[list->size]) {
		printf("Error al asignar memoria para el nuevo elemento\n");
		return;
	}
	
	memcpy(list->data[list->size], element, list->element_size);
	list->size++;
}

void arrayList_insert(ArrayList *list, void *element, int index) {
	if (!list || !element || index < 0 || index > list->size) return;
	
	if (list->size >= list->capacity) {
		arrayList_ensure_capacity(list, list->capacity * GROWTH_FACTOR);
	}
	
	for (int i = list->size; i > index; i--) {
		list->data[i] = list->data[i - 1];
	}
	
	list->data[index] = malloc(list->element_size);
	if (!list->data[index]) {
		printf("Error al asignar memoria para la inserción\n");
		return;
	}
	
	memcpy(list->data[index], element, list->element_size);
	list->size++;
}

void* arrayList_get(ArrayList *list, int index) {
	if (!list || index < 0 || index >= list->size) return NULL;
	return list->data[index];
}

void arrayList_remove(ArrayList *list, int index) {
	if (!list || index < 0 || index >= list->size) return;
	
	free(list->data[index]);
	
	for (int i = index; i < list->size - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	
	list->size--;
}

void arrayList_ensure_capacity(ArrayList *list, int min_capacity) {
	if (!list || min_capacity <= list->capacity) return;
	
	void *new_data = realloc(list->data, sizeof(void) * min_capacity);
	if (!new_data) {
		printf("Error al reasignar la memoria\n");
		return;
	}
	
	list->data = new_data;
	list->capacity = min_capacity;
}

void arrayList_clear(ArrayList *list) {
	if (!list) return;
	
	for (int i = 0; i < list->size; i++) {
		free(list->data[i]);
		list->data[i] = NULL;
	}
	
	list->size = 0;
}
