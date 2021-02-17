#include <stdio.h>

int partition(int *arr, int low, int high)
{
    int pe = arr[high];

    int start = low - 1;

    for (int i = low; i < high - 1; i++)
    {
        if (arr[i] < pe)
        {
            start++;
            int temp = arr[i];
            arr[i] = arr[start];
            arr[start] = temp;
        }
    }
    start++;
    int temp = arr[start];
    arr[start] = pe;
    arr[high] = temp;
    return start;
}

void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int i = 0;
void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        printf("i = %d,  ", i);
        i++;
        displayArray(arr, 9);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[9] = {67, 92, 48, 5, 23, 81, 98, 3, 2};

    quick_sort(arr, 0, 9);

    return 0;
}
