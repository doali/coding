#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Cell Cell;
typedef Cell* List;

struct Cell {
	int val;
	Cell *next;
};

List list_add(List list, Cell *cell) {
	List it = list;

	if (it == NULL) { 
		it = cell;
		return it;
	}

	while (it->next != NULL) it = it->next;

	it->next = cell;

	return list;
}

void list_print(List list) {
	List it = list;

	printf("[");
	while (it != NULL) { 
		printf(" %d ", it->val);
		it = it->next;
	}
	printf("]\n");
}

int f(int a) { return a; }
const char* g(const char* msg) { return msg; }

int main() {
	List list = NULL;

	Cell cell0 = { 0, NULL };
	Cell cell1 = { 1, NULL };
	Cell cell2 = { 2, NULL };
	Cell cell3 = { 3, NULL };
	Cell cell4 = { 4, NULL };
	Cell cell5 = { 5, NULL };

	list = list_add(list, &cell0);
	list = list_add(list, &cell1);
	list = list_add(list, &cell2);
	list = list_add(list, &cell3);
	list = list_add(list, &cell4);
	list = list_add(list, &cell5);

	list_print(list);

	void*(*p_f)(void*);
	p_f = (void*(*)(void*))&f;

	int a = (int*)(p_f((int*)(4)));
	printf("res=%d\n", a);

	const char* msg = "ceci est un message";
	p_f = (void*(*)(void*))&g;
	printf("%s\n", (const char*)(p_f((char*)(msg))));

	return 0;
}
