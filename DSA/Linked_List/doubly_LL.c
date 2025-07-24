#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node * create_node(int data)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void traverse_forward(Node * head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * curr = head;
    printf("HEAD -> ");
    while (curr != NULL)
    {
        printf("%d <-> ", curr->data);   // Do something
        curr = curr->next;
    }
    printf("TAIL\n");
}

void traverse_backward(Node * tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * curr = tail;
    printf("TAIL -> ");
    while (curr != NULL)
    {
        printf("%d <-> ", curr->data);   // Do something
        curr = curr->prev;
    }
    printf("HEAD\n");
}

void insert_head(Node ** head, Node ** tail, int data)
{
    Node * new_node = create_node(data);
    new_node->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;

    if (*tail == NULL)  // If the list was empty
    {
        *tail = new_node;
    }
}

void insert_tail(Node ** head, Node ** tail, int data)
{
    Node * new_node = create_node(data);
    new_node->prev = *tail;
    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    *tail = new_node;

    if (*head == NULL)  // If the list was empty
    {
        *head = new_node;
    }
}


void free_list(Node ** head)
{
    if (*head == NULL)
    {
        return;   // List is already empty
    }

    Node * curr = *head;
    Node * next_node;

    while (curr != NULL)
    {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    *head = NULL;
}

int main()
{
    Node * head = NULL;
    Node * tail = NULL;
    for (int i = 0; i < 10; i++)
    {
        insert_tail(&head, &tail, 10 * (i + 1));
    }
    traverse_backward(tail);
    traverse_forward(head);

    free_list(head);
    return 0;
}