/*
Given a string S, and two numbers N, M - arrange the characters of string in between the indexes N and M (both inclusive) in descending order. (Indexing starts from 0).

Input Format:
First line contains T - number of test cases.
Next T lines contains a string(S) and two numbers(N, M) separated by spaces.

Output Format:
Print the modified string for each test case in new line.

Sample input:
3
hlleo 1 3
ooneefspd 0 8
effort 1 4

Sample output:
hlleo
spoonfeed
erofft
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CASES   1000
#define MAX_LEN     10000


void merge(char * arr, int start, int mid, int end)
{
    int l_size = mid - start + 1;
    int r_size = end - mid;
    int i, j, k;
    char l_str[l_size], r_str[r_size];

    for (i = 0; i < l_size; i++)
    {
        l_str[i] = arr[start + i];
    }

    for (j = 0; j < r_size; j++)
    {
        r_str[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = start;

    while ((i < l_size) && (j < r_size))
    {
        if (l_str[i] >= r_str[j])
        {
            arr[k] = l_str[i];
            i++;
        }
        else
        {
            arr[k] = r_str[j];
            j++;
        }
        k++;
    }

    while (i < l_size)
    {
        arr[k] = l_str[i];
        i++;
        k++;
    }

    while (j < r_size)
    {
        arr[k] = r_str[j];
        j++;
        k++;
    }
}

void merge_sort(char * arr, int start, int end)
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
    int num_cases;
    printf("Number of test cases: ");
    scanf("%d", &num_cases);

    if ((num_cases < 1) || (num_cases > MAX_CASES))
    {
        printf("Invalid number of cases\n");
        return 1;
    }

    // Allocate memory
    char ** str = (char **) calloc(num_cases, sizeof(char *));
    for (int i = 0; i < num_cases; i++)
    {
        str[i] = (char *) calloc(MAX_LEN, sizeof(char));
    }

    int ** idx = (int **) calloc(num_cases, sizeof(int *));
    for (int i = 0; i < num_cases; i++)
    {
        idx[i] = (int *) calloc(2, sizeof(int));
    }

    // Get strings
    for (int i = 0; i < num_cases; i++)
    {
        scanf("%s %d %d", str[i], &idx[i][0], &idx[i][1]);
    }

    // Sort characters
    for (int i = 0; i < num_cases; i++)
    {
        merge_sort(str[i], idx[i][0], idx[i][1]);
    }

    // Print output
    printf("Output:\n");
    for (int i = 0; i < num_cases; i++)
    {
        printf("%s\n", str[i]);
    }

    // Free memory
    for (int i = 0; i < num_cases; i++)
    {
        free(str[i]);
        free(idx[i]);
    }
    
    free(str);
    free(idx);

    return 0;
}