


typedef struct queue_struct {
   int count;
  struct queue_struct *next;
} queue;


queue *pull (queue *top);


queue *put (queue *top, int n);


queue* clear(queue *top);









