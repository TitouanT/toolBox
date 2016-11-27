#ifndef STACK_PTR_H
#define STACK_PTR_H

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

void stackPtr_init (void);
int  stackPtr_isEmpty (void);
void stackPtr_pop (t_data * data);
void stackPtr_look (t_data * data);
void stackPtr_push (t_data data);
void stackPtr_remove (void);

#endif /* end of include guard: STACK_PTR_H */
