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
        for (int i = 0; i < 10; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

int main()
{
    int arr[10] = {67, 92, 48, 79, 5, 23, 81, 98, 3, 2};
    insertionSort(arr, 10);

    // for (int i = 0; i < 5; i++)
    //     printf("%d ", arr[i]);
    printf("\n");
    return 0;
}