#include <stdio.h>
#include <stdlib.h>

// Merge 2 sorted subarrays arr[start...mid] and arr[mid+1...end] into arr[start...end]
void merge(int * arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j, k;
    
    // Temporary arrays
    int L[n1], R[n2];

    // Copy arr[start...mid] into L[0...n1-1]
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];  
    }

    // Copy arr[mid+1...end] into R[0...n2-1]
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];    
    }

    i = 0;
    j = 0;
    k = start;

    // Compare elements from L and R and merge them into arr
    while ((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;   
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Merge the rest of L or R into arr
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Divide arr[start...end] into 2 subarrays recursively and merge them
void merge_sort(int * arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6,5,4,3,2,1,0,-1,-2,40,30,20,10,39,38,37,36};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, size - 1);
    

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}