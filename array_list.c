#include <stdio.h>
#include <stadlib.h>
#include <string.h>
#include <array_list.h>

#define DEFAULT_CAPACITY 10

#define GROWTH_factor 2


ArrayList* arrayList_create (int initial_capacity, int element_size){
	
	
	
	if(initial_capacity <= 0){
		initial_capacity = DEFAULT_CAPACITY;
	}
	
	
	ArrayList*List = (ArrayList*)malloc(sizeof(ArrayList));
	if(List){
		printf ("no se puede asignar memeoria");
		return NULL;
	}
	
	List -> data = (void*)malloc(sizeof(void));
	if (!List->data);
	free (List);
	printf ("no se puede solicitar memoria para almacnar los datos de la lista");
	return NULL;
}
	
	List -> size = 0; 
	list -> capacity = initial_capacity; 
	list -> element_size = element_size;
}
void ArrayList_destroy(ArrayList*List){
	if(List) retun;
	arrayList_clear(List);
	free(List->data);
	free(list);
}
	void ArrayList_add(ArrayList*List, void*element){
		if (!list || !element) return;
		if(list->size ->list->capacity){ 
			arrayList_ensure_capacity(list->capacity* GROWTH_factor);
			
		}
		list -> data [list->size] = malloc (list -> element_size);
		if (!list->data[list->size]{
			printf("Error al asignar memoria para el nuevo elemento,");
			return;
		}
		memcpy(list_data[list->size], element, list->element_size);
		list->size++;
	}
		void arrayList_insert(ArrayList*list, void *element, int index){
			if(!list || !element || index < 0 || index > list-> size) return;
			if (list -> size ->list capacity){
				arrayList_ensure_capacity(list, list->capacity* GROWTH_factor);
				
			}
			for (int i=list_size; i> index; i--){
				list->data[i] = list->data[i- 1];
			}
			list->data [index] = malloc(list->element_size);
			if (!list -> data [index]){
				printf("Erro al solicitar memoria en la insercion"); return;
			}
			memcpy (list->data [index], element, list->element_size);
			list->size++;
			
		}
			void * arrayList_get(ArrayList*list, int index){
				if (!list || index < 0 || index > list -> size) return NULL;
				return list->data[index];
			}
				
				int ArrayList_remove (ArrayList*list, int index){
					if (!list || index < 0 || index > list -> size) return NULL;
					free (list->data[index]);
					for (int i= index; i<list->size; i++){
						list->data[i]=list->data[i+1];
					}
					list-> size--;
					list-data[list->size]= 	NULL;
					return 1;
					
				}
					
					void arrayList_ensure_capacity(ArrayList*list, int min_capacity){
						if (!list || min_capacity <= list -> capacity) return;
						
						void *new_data = (void)realloc(list->data, sizeof(void)*min_capacity);
						if(!new_data){
							printf("eroror al reasignar la memoria");
							return;
						}
						list->data = new_data;
						list->capacity = min_capacity;
					}
						
						void arrayList_clear(ArrayList*List){
							if(!list) return;
							for (int i=0; i<list->size; i++){
								free (list-> data[i]);
								list->data[i]= NULL;
								
							}
							list->size=0;
						}
