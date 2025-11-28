#include <stdio.h>
#include "array_list.h"

int main() {
	
	ArrayList* myArrayList = arrayList_create(3, sizeof(int));
	
	int a = 10, b = 20, c = 30, d = 40, e = 99;
	
	arrayList_add(myArrayList, &a);
	arrayList_add(myArrayList, &b);
	arrayList_add(myArrayList, &c);
	arrayList_add(myArrayList, &d);
	
	arrayList_insert(myArrayList, &e, 1);
	
	int *v = (int*) arrayList_get(myArrayList, 2);
	printf("Valor en pos 2: %d\n", *v);
	
	arrayList_remove(myArrayList, 0);
	arrayList_remove(myArrayList, 1);
	
	arrayList_destroy(myArrayList);
	
	return 0;
}
