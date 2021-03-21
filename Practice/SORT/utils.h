#include <stdio.h>

int displayArray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
