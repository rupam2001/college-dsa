#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insert(int *queue, int *rear, int element)
{
    if (*rear == MAX_SIZE - 1)
    {
        printf("Queue is full \n");
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
    if (*front > *rear)
        *front = *rear = -1;

    return temp;
}

void display(int *queue, int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("Nothing to display (queue is empty)\n");
        return;
    }
    else if (front == -1)
        front = 0;

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{

    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    int choice;

    int queue_element;

    while (1)
    {
        printf("Enter your choice insert: 0, delete: 1, display: 2 >> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("(insert choosen)\n");
            printf("Enter the element > ");
            scanf("%d", &queue_element);
            insert(queue, &rear, queue_element);
            break;
        case 1:
            printf("(delete choosen)\n");
            delete (queue, &rear, &front);
            break;
        case 2:
            printf("(display choosen)\n");
            display(queue, front, rear);
            break;
        default:
            printf("Exiting...\n");
            return 0;
            break;
        }
    }

    return 0;
}