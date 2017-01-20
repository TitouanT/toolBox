/* Titouan Teyssier - 11/27/16 */

#ifndef LIST_PTR_H
#define LIST_PTR_H


typedef struct {
	int a;
	float x;
} t_data;

//or

/*
typedef enum {some, name, in, your, enum} t_data;
*/

//or

/*
typedef <existingtype> t_data;
*/

void listPtr_appendEnd (t_data data);
void listPtr_appendHead (t_data data);
void listPtr_appendLeft (t_data data);
void listPtr_appendRight (t_data data);
void listPtr_init (void);
int  listPtr_isEmpty (void);
int  listPtr_isInList (t_data data);    // !ok, you have to code it !
int  listPtr_isOut (void);
void listPtr_move2end (void);
void listPtr_move2head (void);
void listPtr_next (void);
void listPtr_prev (void);
void listPtr_readData (t_data * data);
void listPtr_removeElt (void);
void listPtr_removeList (void);

#endif /* end of include guard: LIST_PTR_H */
