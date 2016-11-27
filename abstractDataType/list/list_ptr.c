/* Titouan Teyssier - 11/27/16 */

#include <stdlib.h>
#include "list_ptr.h"

/***** You have to code this function () *******/

int areEqual (t_data d1, t_data d2) {
	return d1 == d2; // this doesn't work for struct
}

/********************************************/

typedef struct element {
	struct element * next;
	struct element * prev;
	t_data data;
} t_element;

t_element * gFlag;
t_element * gCurrElt;
int gNbElt;

void listPtr_init (void) {
	gFlag = malloc (sizeof(t_element));
	gFlag -> next = gFlag -> prev = gCurrElt = gFlag;
	gNbElt = 0;
}

int  listPtr_isEmpty (void) {
	return gFlag -> next == gFlag;
}

int  listPtr_isOut (void) {
	return gCurrElt == gFlag;
}

void listPtr_move2end (void) {
	ec = gFlag -> prev;
}

void listPtr_move2head (void) {
	ec = gFlag -> next;
}

void listPtr_readData (t_data * data) {
	if (gCurrElt != gFlag) {// not out of list
		*data = gCurrElt -> data;
	}
}

void listPtr_removeElt (void) {
	t_element * tmp;
	if (gCurrElt != gFlag) {// not out of list
		tmp = gCurrElt;
		// redo the chain
		gCurrElt -> next -> prev = gCurrElt -> prev;
		gCurrElt -> prev -> next = gCurrElt -> next;
		// put the current element on the left
		gCurrElt = gCurrElt -> prev;
		
		free(tmp);
	}
}

void listPtr_removeList (void) {
	listPtr_move2end();
	while (gCurrElt != gFlag) listPtr_removeElt();
}

void listPtr_next (void) {
	if (gCurrElt != gFlag) gCurrElt = gCurrElt -> next;
}

void listPtr_prev (void) {
	if (gCurrElt != gFlag) gCurrElt = gCurrElt -> prev;
}

void listPtr_appendLeft (t_data data) {
	t_element * tmp = malloc (sizeof (t_element));
	tmp -> data = data;
	// i dont use the fact that if the list is empty then gFlag = gCurrElt because it's clearer that way.
	if (listPtr_isEmpty()) {
		tmp -> next = gFlag;
		tmp -> prev = gFlag;
		gFlag -> next = tmp;
		gFlag -> prev = tmp;
		gCurrElt = tmp;
	}
	else if (!listPtr_isOut()) {
		tmp -> prev = gCurrElt -> prev;
		tmp -> next = gCurrElt;
		gCurrElt -> prev -> next = tmp;
		gCurrElt -> prev = tmp;
		gCurrElt = tmp;
	}
	else free (tmp);
}

void listPtr_appendRight (t_data data) {
	t_element * tmp = malloc (sizeof (t_element));
	tmp -> data = data;
	// i dont use the fact that if the list is empty then gFlag = gCurrElt because it's clearer that way.
	if (listPtr_isEmpty()) {
		tmp -> next = gFlag;
		tmp -> prev = gFlag;
		gFlag -> next = tmp;
		gFlag -> prev = tmp;
		gCurrElt = tmp;
	}
	else if (!listPtr_isOut()) {
		tmp -> prev = gCurrElt;
		tmp -> next = gCurrElt -> next;
		gCurrElt -> next -> prev = tmp;
		gCurrElt -> next = tmp;
		gCurrElt = tmp;
	}
	else free (tmp);
}

void listPtr_appendEnd (t_data data) {
	listPtr_move2end();
	listPtr_appendRight();
}

void listPtr_appendHead (t_data data) {
	listPtr_move2head();
	listPtr_appendLeft();
}

int listPtr_isInList (t_data data) {
	t_data cmp;
	listPtr_move2head();
	while (!listPtr_isOut()) {
		listPtr_readData(&cmp);
		if (areEqual(cmp, data)) return 1;
		listPtr_next();
	}
	return 0;
}