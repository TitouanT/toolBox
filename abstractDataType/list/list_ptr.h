/* Titouan Teyssier - 11/27/16 */

#ifndef LIST_PTR_H
#define LIST_PTR_H

/*
typedef struct {
	<data_to_store>
} t_data;
*/

//or

/*
typedef enum {some, name, in, your, enum} t_data;
*/

//or

/*
typedef <existingtype> t_data;
*/

void listPtr_appendEnd (t_data data);	//ok
void listPtr_appendHead (t_data data);	//ok
void listPtr_appendLeft (t_data data);	//ok
void listPtr_appendRight (t_data data);	//ok
void listPtr_init (void);				//ok
int  listPtr_isEmpty (void);			//ok
int  listPtr_isInList (t_data data);    // !ok, you have to code it !
int  listPtr_isOut (void);				//ok
void listPtr_move2end (void);			//ok
void listPtr_move2head (void);			//ok
void listPtr_next (void);				//ok
void listPtr_prev (void);				//ok
void listPtr_readData (t_data * data);	//ok
void listPtr_removeElt (void); 			//ok
void listPtr_removeList (void); 		//ok

#endif /* end of include guard: LIST_PTR_H */
