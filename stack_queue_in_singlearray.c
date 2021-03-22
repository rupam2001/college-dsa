#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

void push(int *stack, int *top, int element)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

int pop(int *stack, int *top)
{
    if (*top == MAX_SIZE / 2 - 1)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    int temp = stack[*top];
    *top = *top - 1;
    return temp;
}
void insert(int *queue, int *rear, int element)
{
    if (*rear == MAX_SIZE / 2 - 1)
    {
        printf("Queue is full");
        exit(-1);
    }
    *rear = *rear + 1;
    queue[*rear] = element;
}
int delete (int *queue, int *rear, int *front)
{

    if (*front == -1 && *rear == -1)
    {
        printf("Queue is empty\n");
        exit(-1);
    }
    if (*front == -1)
        *front = 0;
    int temp = queue[*front];
    *front = *front + 1;
    // if (*front > *rear)
    //     *front = *rear = -1;

    return temp;
}

int main()
{

    int arr[MAX_SIZE];
    int front = -1, rear = -1, top = MAX_SIZE / 2 - 1;

    
    push(arr, &top, 1);
    push(arr, &top, 2);

    insert(arr, &rear, 3);
    insert(arr, &rear, 4);

    //display queue  loop from front -> rear

    //display stack loop from top -> MAX_SIZE - 1

    return 0;
}
