#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *create_new_node()
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Unable to allocate memory\n");
        exit(-1);
    }
    newNode->next = NULL;
    return newNode;
}

typedef struct queue
{
    node *front;
    node *rear;
    int Max_size;
    int rear_pos;
} Queue;

Queue *initialize_Queue(int max_size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        printf("Unaable to allocate memeory\n");
        exit(-1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->rear_pos = 0;
    queue->Max_size = max_size;
    return queue;
}

void Enqueue(Queue *queue, int element)
{
    if (queue->rear_pos == queue->Max_size)
    {
        printf("Queue is full\n");
        return;
    }

    node *newNode = create_new_node();
    newNode->data = element;

    if (queue->front == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        queue->rear_pos++;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    queue->rear_pos++;
}

int Dequeue(Queue *queue)
{
    if (queue->rear_pos == 0)
    {
        printf("Queue is empty\n");
        exit(-1);
    }
    const int frontData = queue->front->data;

    node *frontNode = queue->front;
    queue->front = queue->front->next;

    free(frontNode);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
        queue->rear_pos = 0;
    }

    return frontData;
}

int main()
{
    Queue *queue = initialize_Queue(5);
    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
    Enqueue(queue, 5);

    while (queue->front)
    {
        printf("%d ", Dequeue(queue));
    }

    return 0;
}