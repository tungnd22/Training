#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int * arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(&arr[i], &arr[min_idx]);
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

    selection_sort(arr, size);
    print_arr(arr, size);

    return 0;
}