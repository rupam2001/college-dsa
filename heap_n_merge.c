#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int size, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = l + 1;

    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int *arr, int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i > 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

///////////////////////////////////////////////////Merge Sort

void merge(int *arr, int left, int mid, int right)
{
    int size_leftSub = mid - left + 1;
    int size_rightSub = right - mid;

    int leftSubArray[size_leftSub];
    int rightSubArray[size_rightSub];

    for (int i = 0; i < size_leftSub; i++)
        leftSubArray[i] = arr[left + i];
    for (int i = 0; i < size_rightSub; i++)
        rightSubArray[i] = arr[(mid + 1) + i];

    int index_leftSub = 0;
    int index_rightSub = 0;

    int index_mergeArray = left;

    while (index_leftSub < size_leftSub && index_rightSub < size_rightSub)
    {
        if (rightSubArray[index_rightSub] > leftSubArray[index_leftSub])
        {
            arr[index_mergeArray++] = leftSubArray[index_leftSub++];
        }
        else
        {
            arr[index_mergeArray++] = rightSubArray[index_rightSub++];
        }
    }

    //fill the remaining elements if any
    //for left
    while (index_leftSub < size_leftSub)
    {
        arr[index_mergeArray++] = leftSubArray[index_leftSub++];
    }
    //for right
    while (index_rightSub < size_rightSub)
    {
        arr[index_mergeArray++] = rightSubArray[index_rightSub++];
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

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    int choice;

    printf("Heap Sort: 1   Merge Sort: 2 > ");
    scanf("%d", &choice);

    if (choice == 1)
        heapSort(arr, size);
    else if (choice == 2)
        mergeSort(arr, 0, size - 1);

    display(arr, size);

    return 0;
}