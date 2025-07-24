#include <stdio.h>
#include <stdlib.h>

// Definition of a singly LL node
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

// Definition of a stack using LL
typedef struct Stack
{
    Node * top;
} Stack;

// Create a new stack
Stack * create_stack()
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Check if the stack is empty
int is_empty(Stack * stack)
{
    return (stack->top == NULL);
}

// Push an element onto the stack -> insert at head of LL
void push(Stack * stack, int data)
{
    Node * new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop an element from the stack -> delete at head of LL
int pop(Stack * stack)
{
    if (is_empty(stack) == 1)
    {
        printf("Stack underflows\n");
        return -1;
    }

    Node * temp = stack->top;
    int popped_data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped_data;
}

// Get the top element of the stack
int peek(Stack * stack)
{
    if (stack->top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Free the stack memory
void free_stack(Stack * stack)
{
    Node * curr = stack->top;
    Node * next_node;

    while (curr != NULL)
    {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    free(stack);
} 

int main()
{
    return 0;
}