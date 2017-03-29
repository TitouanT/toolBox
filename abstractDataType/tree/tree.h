#ifndef TREE_H
#define TREE_H

enum {false, true};

typedef struct tree {
	struct tree * parent;
	struct tree * childL;
	struct tree * childR;
	void * data;
} tree_t;


/* creation and addition */
tree_t * tree_create (
	tree_t * cL,
	tree_t * cR,
	void * data,
	void * (*cpy) (void *)
);
void tree_delete (tree_t * t, void (*del) (void *));
void tree_appendLeft (tree_t * t, void * data);
void tree_appendRight (tree_t * t, void * data);

/* boolean test */
int tree_isEmpty (tree_t * t);
int tree_isLeaf (tree_t * t);
int tree_isRoot (tree_t * t);

/* subtree */
tree_t * tree_parent (tree_t * t);
tree_t * tree_childLeft (tree_t * t);
tree_t * tree_childRight (tree_t * t);

/* traveling */
void tree_prefix (tree_t * t, void (*func) (void *));
void tree_infix (tree_t * t, void (*func) (void *));
void tree_postfix (tree_t * t, void (*func) (void *));

/* lookup */
int tree_data (tree_t * t, void * data);
int tree_newData (tree_t * t, void * data, void * (*cpy) (void *));
#endif /* end of include guard: TREE_H */
