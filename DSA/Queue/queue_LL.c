#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct Node
{
    int data;
    struct Node * next;
} Node;

// Create a new node
Node * create_node(int data)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Definition of a queue
typedef struct Queue
{
    Node * front;
    Node * rear;
} Queue;

// Create a new queue
Queue * create_queue()
{
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if a queue is empty
int is_empty(Queue * q)
{
    return (q->front == NULL);
}

// Enqueue
void enqueue(Queue * q, int data)
{
    Node * new_node = create_node(data);
    if (is_empty(q) == 1)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue
int dequeue(Queue * q)
{
    if (is_empty(q) == 1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int retreived_data = q->front->data;
        Node * temp = q->front;
        q->front = q->front->next;
        free(temp);
        return retreived_data;
    }
}

void free_queue(Queue * q)
{
    Node * curr = q->front;
    Node * next_node;

    while (curr != NULL)
    {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    q->front = NULL;
    q->rear = NULL;
}

void print_queue(Queue * q)
{
    if (is_empty(q) == 1)
    {
        printf("Queue is empty\n");
        return;
    }

    Node * curr = q->front;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Queue * q1 = create_queue();
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

    printf("Dequeueing: %d\t", dequeue(q1));
    print_queue(q1);
    printf("\n");

    printf("Dequeueing: %d\t", dequeue(q1));
    print_queue(q1);
    printf("\n");
    


    free_queue(q1);
    return 0;
}