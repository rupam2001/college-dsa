#include <stdio.h>

#define true 1
#define false 0

//helper functions

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int a, int b, int desc)
{
    if (desc)
        return a < b;
    return a > b;
}

//bubble sort

void bubbleSort(int *arr, int size, int desc)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1], desc))
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

//selection sort
void selectionSort(int *arr, int size, int desc)
{
    for (int i = 0; i < size; i++)
    {
        int max = arr[i];
        int max_pos = i;
        for (int j = i; j < size; j++)
        {
            if (compare(max, arr[j], desc))
            {
                max = arr[j];
                max_pos = j;
            }
        }
        swap(&arr[i], &arr[max_pos]);
    }
}

//insertion sort

void insertinSort(int *arr, int size, int desc)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && compare(arr[j], key, desc))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//merge sort

//merge function

void merge(int *arr, int left, int mid, int right, int desc)
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
        if (compare(rightSubArray[index_rightSub], leftSubArray[index_leftSub], desc))
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

void mergeSort(int *arr, int left, int right, int desc)
{
    if (left < right)
    {
        int mid = (left + right - 1) / 2;
        mergeSort(arr, left, mid, desc);
        mergeSort(arr, mid + 1, right, desc);
        merge(arr, left, mid, right, desc);
    }
}

//quick sort

int partition(int *arr, int low, int high, int desc)
{

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (compare(pivot, arr[j], desc))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high, int desc)
{
    if (low < high)
    {
        int pv = partition(arr, low, high, desc);
        quickSort(arr, low, pv - 1, desc);
        quickSort(arr, pv + 1, high, desc);
    }
}

void display(int *arr, int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("}\n");
}

//menu
void input(char *stdout_msg, int *stdin_var)
{
    printf("%s", stdout_msg);
    scanf("%d", &(*stdin_var));
}

void MENU()
{

    int size;
    int choice;
    int desc;

    while (1)
    {
        input("Enter the size of the array: ", &size);
        int arr[size];
        printf("Enter the array: ");
        for (int i = 0; i < size; i++)
            input("", &arr[i]);

        input("Enter your algorithm\n  bubble sort: 1, selection sort: 2, insertion sort: 3, merge sort: 4, quick sort: 5 , exit: 6 \n > ", &choice);
        if (choice != 6)
        {
            input("Accending: 0, deccending: 1 > ", &desc);
        }
        switch (choice)
        {
        case 1:
            bubbleSort(arr, size, desc);
            break;
        case 2:
            selectionSort(arr, size, desc);
            break;
        case 3:
            insertinSort(arr, size, desc);
            break;
        case 4:
            mergeSort(arr, 0, size - 1, desc);
            break;
        case 5:
            quickSort(arr, 0, size - 1, desc);
            break;
        case 6:
            printf("Exiting..");
            return;
        default:
            printf("Invalid choice\n");
            continue;
        }
        display(arr, size);
    }
}

int main()
{
    MENU();
    return 0;
}