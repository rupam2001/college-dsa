#include <stdio.h>

void merge(int *arr, int left, int right, int mid)
{
    int leftSubArraySize = mid - left + 1;
    int rightSubArraySize = right - mid;

    int leftSubArray[leftSubArraySize];
    int rightSubArray[rightSubArraySize];

    for (int l = 0; l < leftSubArraySize; l++)
        leftSubArray[l] = arr[left + l];
    for (int r = 0; r < rightSubArraySize; r++)
        rightSubArray[r] = arr[(mid + 1) + r];

    //merge
    int il = 0, ir = 0, ia = left;

    while (il < leftSubArraySize && ir < rightSubArraySize)
    {
        if (leftSubArray[il] < rightSubArray[ir])
        {
            arr[ia++] = leftSubArray[il++];
        }
        else
        {
            arr[ia++] = rightSubArray[ir++];
        }
    }

    while (il < leftSubArraySize)
    {
        arr[ia++] = leftSubArray[il++];
    }
    while (ir < rightSubArraySize)
    {
        arr[ia++] = rightSubArray[ir++];
    }
}

void merge_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right - 1) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, right, mid);

        //merge
    }
}

void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[5] = {4, -1, 3, 2, 0};
    merge_sort(arr, 0, 5);

    displayArray(arr, 5);

    return 0;
}