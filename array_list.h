#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct {
	void **data;
	int size;
	int capacity;
	int element_size;
} ArrayList;

ArrayList* arrayList_create(int initial_capacity, int element_size);
void arrayList_destroy(ArrayList *list);

void arrayList_add(ArrayList *list, void *element);
void arrayList_insert(ArrayList *list, void *element, int index);
void* arrayList_get(ArrayList *list, int index);
void arrayList_remove(ArrayList *list, int index);
void arrayList_clear(ArrayList * list);

void arrayList_ensure_capacity(ArrayList * list, int min_capacity);
void arrayList_trim_to_size(ArrayList * list);
ArrayList* arrayList_clone(ArrayList * list);

#endif
