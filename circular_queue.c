#include <stdio.h>
#include <stdlib.h> //for exit()

#define MAX_SIZE 5

void insert(int *queue, int *front, int *rear, int element)
{

    if ((*rear + 1) % MAX_SIZE == *front)
    {
        printf("Queue is full");
        return;
    }
    if (*front == -1)
        *front = 0;
    *rear = (*rear + 1) % MAX_SIZE;
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

void display(int *queue, int front, int rear)
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
            insert(queue, &front, &rear, queue_element);
            break;
        case 1:
            printf("(delete choosen)\n");
            printf("Element deleted %d\n", delete (queue, &front, &rear));
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