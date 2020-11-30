#include <stdio.h>

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int i = 0; i < 9; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

int main()
{
    int arr[9] = {57, 48, 33, 12, 78, 90, 25, 67, 4};
    insertionSort(arr, 9);

    // for (int i = 0; i < 5; i++)
    //     printf("%d ", arr[i]);
    printf("\n");
    return 0;
}