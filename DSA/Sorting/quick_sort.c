#include <stdio.h>
#include <stdlib.h>

void print_arr(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_naive(int * arr, int start, int end)
{
    int pivot = arr[end];
    int * temp = (int *) malloc(sizeof(int) * (end - start + 1));
    int i;
    int index = 0;

    // Copy elements smaller than pivot into temp
    for (i = start; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    int pivot_index = index - 1;    // True pivot position

    // Copy elements larger than pivot into temp
    for (i = start; i <= end; i++)
    {
        if (arr[i] > pivot)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    // Copy temp into arr
    index = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[index];
        index++;
    }
    free(temp);

    return pivot_index;
}

int partition_lomuto(int * arr, int start, int end)
{
    int pivot = arr[end];
    int boundary = start;
    int i;

    for (i = start; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[boundary]);
            boundary++;
        }
    }

    return (boundary - 1);  // True pivot index
}

int partition_hoare(int * arr, int start, int end)
{
    int pivot = arr[start];
    int i = start - 1;
    int j = end + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        
        do
        {
            j--;
        } while (arr[j] > pivot);
        
        if (i >= j)
        {
            return j;   // Approximate pivot position
        }
        else
        {
            swap(&arr[i], &arr[j]);
        }
    }
}

void quick_sort(int * arr, int start, int end)
{
    if (start < end)
    {
        // Take a random position to be pivot
        int r = start + rand() % (end - start + 1);
        swap(&arr[end], &arr[r]);

        int pivot_index = partition_lomuto(arr, start, end);
        quick_sort(arr, start, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

int main()
{
    int arr[] = {11,12,32,4,5,6,7,33,2,1,323,4,3,2,11,45,6,755,445,33,45,76,89,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);
    print_arr(arr, size);
    return 0;
}