#include <stdio.h>
#include <stdlib.h>

void append(int ** arr, int * size, int * capacity, int value)
{
    if (*size >= *capacity)
    {
        *capacity *= 2;
        int * temp = realloc(*arr, *capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            return;
        }
        *arr = temp;
        printf("New array address: %p, new capacity: %d\n", (void *)*arr, *capacity);
    }
    (*arr)[*size] = value;
    (*size)++;
}

void delete(int ** arr, int * size, int * capacity, int index)
{
    for (int i = index; i < *size - 1; i++)
    {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size)--;
}

void resize(int ** arr, int * size, int * capacity)
{
    if (*size < *capacity / 2)
    {
        *capacity /= 2;
        int * temp = realloc(*arr, *capacity * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory reallocation failed\n");
            return;
        }
        *arr = temp;
    }
}

int main()
{
    int size = 0;
    int capacity = 5;
    int * p1 = (int *) malloc(capacity * sizeof(int));
    if(p1 == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original array address: %p, capacity: %d\n", (void *)p1, capacity);
    for (int i = 0; i < 20; i++)
    {
        append(&p1, &size, &capacity, i + 1);
        for (int j = 0; j < capacity; j++)
        {
            printf("%d ", p1[j]);
        }
        printf("\n");
    }

    delete(&p1, &size, &capacity, 10);
    for (int j = 0; j < size; j++)
    {
        printf("%d ", p1[j]);
    }
    printf("\n");

    free(p1);
    return 0;
}