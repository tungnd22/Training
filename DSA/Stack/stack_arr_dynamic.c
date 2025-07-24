#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int capacity;
    int * arr;
} Stack;

Stack * create_stack(int capacity)
{
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *) malloc(capacity * sizeof(int));
    return stack;
}

int is_empty(Stack * stack)
{
    return (stack->top <= -1);
}

int is_full(Stack * stack)
{
    return (stack->top >= stack->capacity - 1);
}

// Push an element onto the stack
// If stack is full, double capacity
void push(Stack * stack, int data)
{
    if (is_full(stack) == 1)
    {
        stack->capacity *= 2;
        int * temp = realloc(stack->arr, stack->capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            return;
        }
        stack->arr = temp;
    }
    stack->arr[++stack->top] = data;
}

// Pop an element from the stack
// If stack size is less than 1/4 capacity, shrink capacity
int pop(Stack * stack)
{
    if (is_empty(stack) == 1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    if (stack->top < stack->capacity / 4)
    {
        stack->capacity /= 2;
        int * temp = realloc(stack->arr, stack->capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            return -1;
        }
        stack->arr = temp;
    }
    int popped_data = stack->arr[stack->top];
    stack->arr[stack->top] = 0; // Optional: clear the popped position
    stack->top--;
    return popped_data;
}

// Free the stack memory
void free_stack(Stack * stack)
{
    free(stack->arr);
    free(stack);
}

void print_stack(Stack * stack)
{
    for (int i = 0; i < stack->capacity; i++)
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
    Stack * stack = create_stack(5);

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
    print_stack(stack);

    free_stack(stack);
    return 0;
}