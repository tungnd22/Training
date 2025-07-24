#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a Node in a singly linked list
typedef struct Node
{    
    int data;          
    struct Node * next;
} Node;

// Function to create a new Node
Node * create_node(int data)
{
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to traverse the linked list and print the data
void traverse(Node * head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);   // Do something
        curr = curr->next;
    }
    printf("NULL\n");

    curr = head;
    while (curr != NULL)
    {
        printf("%p -> ", curr);   // Do something
        curr = curr->next;
    }
    printf("NULL\n");

}

// Function to search for a node with a specific value
Node * search(Node * head, int value)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    Node * curr = head;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            return curr;    // Found the node with value
        }
        curr = curr->next;
    }
    return NULL;    // Can not find the node with value
}

// Function to count the number of nodes in the linked list
int count_nodes(Node * head)
{
    if (head == NULL)
    {
        return 0;   // List is empty
    }

    int count = 0;
    Node * curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;   // Return the number of nodes in the list
}

// Function to insert a new node at the head of the linked list
void insert_head(Node ** head, int data)
{
    Node * new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the linked list
void insert_last(Node ** head, int data)
{
    Node * new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    Node * curr = *head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

// Function to insert a new node after a specific node
void insert_after(Node * head, int prev_data, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * curr = head;
    while (curr != NULL)
    {
        if (curr->data == prev_data)
        {
            Node * new_node = create_node(data);
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }
    printf("Node with value %d not found\n", prev_data);
}

// Function to insert a new node before a specific node
void insert_before(Node * head, int next_data, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->data == next_data)
    {
        insert_head(&head, data);
        return;
    }

    Node * curr = head;
    while (curr->next != NULL)
    {
        if (curr->next->data == next_data)
        {
            Node * new_node = create_node(data);
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }
    printf("Node with value %d not found\n", next_data);
}

// Function to insert a new node at a specific position
void insert_at_position(Node ** head, int pos, int data)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insert_head(head, data);
        return;
    }

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * curr = *head;
    int count = 1;
    while ((curr != NULL) && (count < pos - 1))
    {
        curr = curr->next;
        count++;
    }
    if (curr == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    Node * new_node = create_node(data);
    new_node->next = curr->next;
    curr->next = new_node;
}

// Function to delete the node at the head of the linked list
void delete_head(Node ** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node * temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the node at the end of the linked list
void delete_last(Node ** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node * curr = *head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

// Function to delete a node at a specific position
void delete_at_position(Node ** head, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        delete_head(head);
        return;
    }

    Node * curr = *head;
    int count = 1;
    while ((curr->next != NULL) && (count < pos - 1))
    {
        curr = curr->next;
        count++;
    }
    if (curr->next == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    Node * temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

// Function to free the entire linked list
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
    int len = 5;
    Node * head = NULL;
    for (int i = 0; i < len; i++)
    {
        insert_last(&head, 5 * (i + 1));
    }
    traverse(head);

    free_list(&head);
    return 0;
}