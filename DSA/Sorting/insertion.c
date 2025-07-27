#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int * arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertion_sort(arr, size);
    print_arr(arr, size);

    return 0;
}