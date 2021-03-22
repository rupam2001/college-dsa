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

void insert(int *queue, int *front, int *rear, int element)
{

    if ((*rear + 1) % (MAX_SIZE / 2) == *front)
    {
        printf("Queue is full");
        return;
    }
    if (*front == -1)
        *front = 0;
    *rear = (*rear + 1) % (MAX_SIZE / 2);
    queue[*rear] = element;
}

int delete (int *queue, int *front, int *rear)
{
    if (*front == -1 && *rear == -1)
    {
        printf("Queue is empty");
        exit(-1);
    }

    int deleted_element = queue[*front];
    if (*front == *rear)
    {
        *rear = -1;
        *front = -1;
        return deleted_element;
    }

    *front = (*front + 1) % MAX_SIZE;

    return deleted_element;
}

void displayQueue(int *queue, int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("Nothing to display (queue is empty)\n");
        return;
    }
    if (rear >= front)
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    else
    {
        for (int i = front; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i < rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{

    int arr[MAX_SIZE];
    int front = -1, rear = -1, top = MAX_SIZE / 2 - 1;

    push(arr, &top, 1);
    push(arr, &top, 2);

    insert(arr, &front, &rear, 3);
    insert(arr, &front, &rear, 4);

    displayQueue(arr, front, rear);

    return 0;
}
