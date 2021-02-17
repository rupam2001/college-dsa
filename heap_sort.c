#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int size, int i)
{

    int leftIndex = 2 * i + 1;
    int rightIndex = leftIndex + 1;

    if (leftIndex >= size) //means no children exist
        return;
    if (rightIndex >= size)
    { //means left child exist
        if (arr[i] > arr[leftIndex])
        { //means parent is largest
            //no need to go further , stop
            return;
        }
        //means left index is largest
        heapify(arr, size, leftIndex);
    }
    else
    {
        //means there are two children
        if (arr[leftIndex] > arr[rightIndex])
        {
            if (arr[leftIndex] > arr[i])
            {
                //means left is the largest
                swap(&arr[i], &arr[leftIndex]);
                heapify(arr, size, leftIndex);
            }
            else
            {
                //means parent is the largest
                return;
            }
        }
        else
        {
            if (arr[rightIndex] > arr[i])
            {
                //means right is the largest
                swap(&arr[i], &arr[rightIndex]);
                heapify(arr, size, rightIndex);
            }
            else
            {
                //means parent is the largest
                return;
            }
        }
    }
}

void heapSort(int *arr, int size)
{

    for (int i = 0; i <= size / 2; i++)
        heapify(arr, size, i);

    for (int i = 1; i < size - 1; i++)
    {
        swap(&arr[0], &arr[size - i]);
        heapify(arr, size - i, 0);
    }
}

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size = 7;
    int arr[] = {9, 37879, 4, -1, 0, -11, 898};

    heapSort(arr, size);
    display(arr, size);

    return 0;
}