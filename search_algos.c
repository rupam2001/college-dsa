#include <stdio.h>
#include <stdlib.h>

int linear_search(int itemTpSearch, int *arr, int size)
{
    while (size > 0)
        if (arr[--size] == itemTpSearch)
            return size;
    return -1;
}

int binary_search(int itemToSearch, int *arr, int size)
{
    int mid;
    int low = 0, high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2; //middle of current list

        if (arr[mid] == itemToSearch)
            return mid;

        if (arr[mid] > itemToSearch) //if element we are searching for is in the left side
            high = mid - 1;

        else //if element we are searching for is in the right side
            low = mid + 1;
    }
    return -1;
}

int Menu()
{

    int size;
    int choice;
    int itemToSearch;
    int res;

    while (1)
    {
        printf("Enter the size of the array followed by the elements of the array: (enter -1 to exit)\n > ");
        scanf("%d", &size);
        if (size < 0)
            return 0;

        int *arr = (int *)malloc(sizeof(int) * size);

        if (!arr)
        {
            printf("Error: Unable to alocate memory\n");
            return -1;
        }

        for (int i = 0; i < size; i++)
            scanf("%d", &arr[i]);

        printf("Enter your choice of searching algorithm: \n linear search : 1,\n binary search: 2 (array must be sorted in ascending order) \n > ");
        scanf("%d", &choice);

        printf("Enter the item to search: ");
        scanf("%d", &itemToSearch);

        if (choice == 1)
            res = linear_search(itemToSearch, arr, size);
        else if (choice == 2)
            res = binary_search(itemToSearch, arr, size);
        else
        {
            printf("Error: Invalid choice\n");
            return -1;
        }

        res != -1 ? printf("Element found at index %d \n", res) : printf("Element not found\n");

        free(arr);
    }
}

int main()
{
    return Menu();
}