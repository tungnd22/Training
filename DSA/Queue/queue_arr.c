#include <stdio.h>
#include <stdlib.h>

// Definition of queue 
typedef struct Queue
{
    int capacity;
    int front;
    int size;
    int * arr;
} Queue;

// Create a new queue
Queue * create_queue(int cap)
{
    Queue * new_queue = (Queue *) malloc(sizeof(Queue));
    new_queue->capacity = cap;
    new_queue->front = 0;
    new_queue->size = 0;
    new_queue->arr = (int *) malloc(cap * sizeof(int));
    return new_queue;
}

// Enqueue
void enqueue(Queue * q, int data)
{
    if (q->size == q->capacity)
    {
        printf("Queue is full\n");
    }
    else
    {
        int rear = (q->front + q->size) % q->capacity;
        q->arr[rear] = data;
        q->size++;
    }
}

// Dequeue
int dequeue(Queue * q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int retrieved_data = q->arr[q->front];
        q->arr[q->front] = 0;   // Optional: clear the dequeued position
        q->front++;
        q->size--;
        return retrieved_data;
    }
}

void print_queue(Queue * q)
{
    for (int i = 0; i < q->capacity; i++)
    {
        if (i == q->front)
        {
            printf("F");
        }
        if (q->arr[i] != 0)
        {
            printf("%d ", q->arr[i]);
        }
        else
        {
            printf("N ");
        }
    }
    printf("\n");
}

// Get front and rear elements
int get_front(Queue * q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int get_rear(Queue * q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int rear = (q->front + q->size - 1) % q->capacity;
    return q->arr[rear];
}

void free_queue(Queue * q)
{
    free(q->arr);
    free(q);
}

int main()
{
    Queue * q1 = create_queue(5);
    printf("Initial Queue:\t");
    print_queue(q1);
    for (int i = 0; i < 3; i++)
    {
        printf("Enqueuing: %d\t", i + 1);
        enqueue(q1, i + 1);
        print_queue(q1);
    }

    printf("\n");
    printf("Dequeueing: %d\t", dequeue(q1));
    print_queue(q1);

    printf("Dequeueing: %d\t", dequeue(q1));
    print_queue(q1);
    printf("\n");
    
    for (int i = 3; i < 7; i++)
    {
        printf("Enqueuing: %d\t", i + 1);
        enqueue(q1, i + 1);
        print_queue(q1);
    }

    printf("Enqueuing: %d\t", 8);
    enqueue(q1, 8);

    free_queue(q1);
    return 0;
}