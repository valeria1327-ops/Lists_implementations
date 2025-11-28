#include <stdio.h>
#include "array_list.h"

int main() {
	
	ArrayList* myArrayList = arrayList_create(3, sizeof(int));
	
	int a = 8, b = 99, c = 15, d = 30, e = 44;
	
	arrayList_add(myArrayList, &a);
	arrayList_add(myArrayList, &b);
	arrayList_add(myArrayList, &c);
	arrayList_add(myArrayList, &d);
	
	arrayList_insert(myArrayList, &e, 1);
	
	int *v = (int*) arrayList_get(myArrayList, 4);
	printf("Valor en posicion 3: %d\n", *v);
	
	arrayList_remove(myArrayList, 0);
	arrayList_remove(myArrayList, 1);
	
	arrayList_destroy(myArrayList);
	
	return 0;
}
