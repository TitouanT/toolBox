#include "tree.h"

tree_t * tree_create (
	tree_t * cL,
	tree_t * cR,
	void * data,
	void * (*cpy) (void *)
) {
	tree_t * t = malloc(sizeof(tree_t));
	t -> data = cpy (data);
	t -> childL = cL;
	t -> childR = cR;
	t -> parent = NULL;
	if (cL != NULL) cL -> parent = t;
	if (cR != NULL) cR -> parent = t;
}

void tree_delete (tree_t * t, void (*del) (void *)) {
	if (t -> parent != NULL) {
		if (t -> parent -> childL == t) t -> parent -> childL = NULL;
		else t -> parent -> childR = NULL;
	}


	if (t -> childL != NULL) {
		t -> childL -> parent = NULL;
		tree_delete (t -> childL);
	}
	if (t -> childR != NULL) {
		t -> childR -> parent = NULL;
		tree_delete (t -> childR);
	}
	del(t -> data);
	free (t);
}

void tree_appendLeft (tree_t * t, void * data) {
	tree_t * new = malloc (sizeof(tree_t));

	new -> parent = t;
	new -> childL = new -> childR = NULL;
	new -> data = data;

	t -> childL = new;
}

void tree_appendRight (tree_t * t, void * data) {
	tree_t * new = malloc (sizeof(tree_t));

	new -> parent = t;
	new -> childL = new -> childR = NULL;
	new -> data = data;

	t -> childL = new;
}

int tree_isEmpty (tree_t * t) {
	return t == NULL;
}

int tree_isLeaf (tree_t * t) {
	return t -> childL == NULL && t -> childR == NULL;
}

int tree_isRoot (tree_t * t) {
	return t -> parent == NULL;
}

tree_t * tree_parent (tree_t * t) {
	return t -> parent;
}

tree_t * tree_childLeft (tree_t * t) {
	return t -> childL;
}

tree_t * tree_childRight (tree_t * t) {
	return t -> childL;
}

void tree_prefix (tree_t * t, void (*func) (void *)) {
	func(t -> data);
	if (t -> childL != NULL) tree_prefix (t -> childL);
	if (t -> childR != NULL) tree_prefix (t -> childR);
}

void tree_infix (tree_t * t, void (*func) (void *)) {
	if (t -> childL != NULL) tree_infix (t -> childL);
	func(t -> data);
	if (t -> childR != NULL) tree_infix (t -> childR);
}

void tree_postfix (tree_t * t, void (*func) (void *)) {
	if (t -> childL != NULL) tree_postfix (t -> childL);
	if (t -> childR != NULL) tree_postfix (t -> childR);
	func(t -> data);
}

int tree_data (tree_t * t, void * data) {
	if (t != NULL && t -> data != NULL) {
		data = t -> data;
		return true;
	}
	else return false;
}

int tree_newData (tree_t * t, void * data, void * (*cpy) (void *)) {
	if (t != NULL) {
		t -> data = cpy(data);
		return true;
	}
	else return false;
}
