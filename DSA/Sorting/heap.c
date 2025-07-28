#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Make max heap at node i
void heapify(int * arr, int size, int idx)
{
    int max_idx = idx;
    int l_idx = 2 * idx + 1;
    int r_idx = 2 * idx + 2;

    // If left child > parent
    if ((l_idx < size) && (arr[l_idx] > arr[max_idx]))
    {
        max_idx = l_idx;
    }

    // If right child > parent
    if ((r_idx < size) && (arr[r_idx] > arr[max_idx]))
    {
        max_idx = r_idx;
    }

    if (max_idx != idx)
    {
        swap(&arr[idx], &arr[max_idx]);

        // Make its subtree max heap
        heapify(arr, size, max_idx);
    }
}

void heap_sort(int * arr, int size)
{
    // Make max heap at root
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // Rearrange the root
    for (int i = size - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void print_arr(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int arr[] = {11,12,32,4,5,6,7,33,2,1,323,4,3,2,11,45,6,755,445,33,45,76,89,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, size);
    print_arr(arr, size);

    return 0;
}