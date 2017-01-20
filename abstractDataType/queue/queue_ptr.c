/* Titouan Teyssier - 11/27/16 */

#include <stdlib.h>

typedef struct element {
	struct element * next;
	t_data data;
} t_element;

static t_element * gEntry;
static t_element * gExit;

void queuePtr_init (void) {
	gEntry = gExit = NULL;
}

int queuePtr_isEmpty (void) {
	return gExit == NULL;
}

void queuePtr_take (t_data * data) {
	t_element * tmp;
	if (gExit != NULL) {
		tmp = gExit;
		*data = gExit -> data;
		gExit = gExit -> next;
		free (tmp);
	}
}

void queuePtr_add (t_data data) {
	t_element  * new = malloc(sizeof(t_element));
	new -> data = data;
	new -> next = NULL;
	if (gExit == NULL) gExit = new;
	else gEntry -> next = new;
	gEntry = new;
}

void queuePtr_remove (void) {
	t_element * tmp;
	while (gExit != NULL) {
		tmp = gExit;
		gExit = gExit -> next;
		free(tmp);
	}
}