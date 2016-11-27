#ifndef QUEUES_PTR_H
#define QUEUES_PTR_H

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

int queuesPtr_init (int queue);
int queuesPtr_isEmpty (int queue);
int queuesPtr_take (int queue, t_data * data);
int queuesPtr_add (int queue, t_data data);
int queuesPtr_remove (int queue);

#endif /* end of include guard: QUEUES_PTR_H */
