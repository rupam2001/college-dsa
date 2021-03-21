#include <stdio.h>
#include "utils.h"

void merge(int *arr, int l, int m, int r)
{
    int size_left = m - l + 1;
    int size_right = r - m;

    int left_array[size_left];
    int right_array[size_right];

    //fill the left part
    for (int i = 0; i < size_left; i++)
        left_array[i] = arr[l + i];

    //fill the right part
    for (int i = 0; i < size_right; i++)
        right_array[i] = arr[(m + 1) + i];

    //merge both
    int l_index = 0;
    int r_index = 0;
    int main_index = l;

    while (l_index < size_left && r_index < size_right)
    {
        if (left_array[l_index] < right_array[r_index])
        {
            arr[main_index] = left_array[l_index++];
        }

        else
        {
            arr[main_index] = right_array[r_index++];
        }
        main_index++;
    }

    //remaining for left
    while (l_index < size_left)
    {
        arr[main_index++] = left_array[l_index++];
    }
    //remaining for right
    while (r_index < size_right)
    {
        arr[main_index++] = right_array[l_index++];
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right - 1) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{

    int size = 5;
    int arr[] = {5, 4, -1, 0, 2};

    mergeSort(arr, 0, size - 1);
    displayArray(arr, size);

    return 0;
}