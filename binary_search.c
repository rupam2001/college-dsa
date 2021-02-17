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
int binary_search(int itemToSearch, int *arr, int size)
{
    int mid;
    int low = 0, high = size - 1;

    //we will conisider the array from low to high only

    while (low <= high)
    {
        mid = (low + high) / 2; //middle of current list
        printf("%d %d %d \n", low, high, mid);

        if (arr[mid] == itemToSearch)
            return mid;

        if (arr[mid] > itemToSearch) //if element we are searching for is in the left side
            high = mid - 1;

        else //if element we are searching for is in the right side
            low = mid + 1;
    }
    return -1;
}
void displayArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[10] = {23, 90, 56, 71, 12, 39, 88, 47, 3, 95};

    merge_sort(arr, 0, 10);
    displayArray(arr, 10);

    printf("%d\n", binary_search(3, arr, 10));
    return 0;
}