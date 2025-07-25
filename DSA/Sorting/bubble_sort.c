#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int * arr, int size)
{
    bool swapped = false;

    for (int boundary = size; boundary > 0; boundary--)
    {
        for (int i = 0; i < boundary; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }

        // Check if array is already sorted
        if (swapped == false)
        {
            return;
        }
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

    print_arr(arr, size);
    bubble_sort(arr, size);
    print_arr(arr, size);
    
    return 0;
}