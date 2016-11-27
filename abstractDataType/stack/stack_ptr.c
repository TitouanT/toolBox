#include <stdlib.h>
#include "stack_ptr.h"

typedef struct element {
	struct element * next;
	t_data data;
} t_element;

t_element * gTop;

void stackPtr_init (void) {
	gTop = NULL;
}

int stackPtr_isEmpty (void) {
	return gTop == NULL;
}

void stackPtr_pop (t_data * data) {
	t_element * tmp;
	if (gTop != NULL) {
		tmp = gTop;
		*data = gTop -> data;
		gTop = gTop -> next;
		free (tmp);
	}
}

void stackPtr_look (t_data * data) {
	if (gTop != NULL) *data = gTop -> data;
}

void stackPtr_push (t_data data) {
	t_element  * new = malloc(sizeof(t_element));
	new -> data = data;
	new -> next = gTop;
	gTop = new;
}

void stackPtr_remove (void) {
	t_element * tmp;
	while (gTop != NULL) {
		tmp = gTop;
		gTop = gTop -> next;
		free(tmp);
	}
}