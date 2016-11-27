/* Titouan Teyssier - 11/27/16 */
/*
Here it is a pointer implementation of queues statically stored.
*/

#include <stdlib.h>
#include <stdio.h>

#define NB_QUEUES_MAX 20
 
typedef struct element {
	struct element * next;
	t_data data;
} t_element;

typedef struct {
	t_element qEntry;
	t_element qExit;
} t_queue;

t_queue gQueues[NB_QUEUES_MAX];

void warning() {
	fprintf(stderr, "WARNING: only %d queues are available\n", NB_QUEUES_MAX);
}

int queuesPtr_init (int queue) {
	if (queue >= NB_QUEUES_MAX) warning(), return 0;
	gQueues[queue].qEntry = gQueues[queue].qExit = NULL;
}

int queuesPtr_isEmpty (int queue) {
	if (queue >= NB_QUEUES_MAX) warning(), return 1; // if it doesn't exist, it's empty right ? 
	return gQueues[queue].qExit == NULL;
}

int queuesPtr_take (int queue, t_data * data) {
	if (queue >= NB_QUEUES_MAX) warning(), return 0;
	t_element * tmp;
	if (gQueues[queue].qExit != NULL) {
		tmp = gQueues[queue].qExit;
		*data = tmp -> data;
		gQueues[queue].qExit = tmp -> next;
		free (tmp);
	}
}

int queuesPtr_add (int queue, t_data data) {
	if (queue >= NB_QUEUES_MAX) warning(), return 0;
	t_element  * new = malloc(sizeof(t_element));
	new -> data = data;
	new -> next = NULL;
	if (gQueues[queue].qExit == NULL) gQueues[queue].qExit = new;
	else gQueues[queue].qEntry -> next = new;
	gQueues[queue].qEntry = new;
}

int queuesPtr_remove (int queue) {
	if (queue >= NB_QUEUES_MAX) warning(), return 0;
	t_element * tmp;
	while (gQueues[queue].qExit != NULL) {
		tmp = gQueues[queue].qExit;
		gExit = tmp -> next;
		free(tmp);
	}
}