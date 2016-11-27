/* Titouan Teyssier - 11/27/16 */

#ifndef QUEUE_PTR_H
#define QUEUE_PTR_H

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

void queuePtr_init (void);
int  queuePtr_isEmpty (void);
void queuePtr_take (t_data * data);
void queuePtr_put (t_data data);
void queuePtr_remove (void);


#endif /* end of include guard: QUEUE_PTR_H */
