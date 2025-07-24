#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Fixed sizedstack array
typedef struct Stack
{
    int top;
    int arr[MAX_SIZE];
} Stack;

// Create stack
Stack * create_stack()
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Check if stack is empty or full
int is_empty(Stack * stack)
{
    return (stack->top <= -1);
}

int is_full(Stack * stack)
{
    return (stack->top >= MAX_SIZE - 1);
}

// Push an element onto the stack
void push(Stack * stack, int data)
{
    if (is_full(stack) == 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

// Pop an element from the stack
int pop(Stack * stack)
{
    if (is_empty(stack) == 1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    int popped_data = stack->arr[stack->top];
    stack->arr[stack->top] = 0; // Optional: clear the popped position
    stack->top--;
    return popped_data;
}

// Get the top element of the stack
int peek(Stack * stack)
{
    if (is_empty(stack) == 1)
    {
        printf("Stack is empty\n");
        return -1; // or some error value
    }
    return (stack->arr[stack->top]);
}

// Free the stack memory
void free_stack(Stack * stack)
{
    free(stack);
}

void print_stack(Stack * stack)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (stack->arr[i] == 0)
        {
            printf("N ");
        }
        else
        {
            printf("%d ", stack->arr[i]);
        }
        
    }
    printf("\n");
}

int main()
{
    Stack * stack = create_stack();
    printf("Initial Stack:\t");
    print_stack(stack);
    for (int i = 1; i <= 3; i++)
    {
        printf("Pushing %d\t", i);
        push(stack, i);
        print_stack(stack);
    }

    printf("\n");
    printf("Popping %d\t", pop(stack));
    print_stack(stack);
    printf("Popping %d\t", pop(stack));
    print_stack(stack);
    printf("\n");

    for (int i = 4; i <= 7; i++)
    {
        printf("Pushing %d\t", i);
        push(stack, i);
        print_stack(stack);
    }

    printf("Pushing %d\t", 8);
    push(stack, 8);

    free_stack(stack);
    return 0;
}