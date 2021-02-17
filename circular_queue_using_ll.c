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
    int curr_size;
} CircularQueue;

CircularQueue *initialize_Queue(int max_size)
{
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    if (!queue)
    {
        printf("Unable to allocate memeory\n");
        exit(-1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->curr_size = 0;
    queue->Max_size = max_size;
    return queue;
}

void Enqueue(CircularQueue *cqueue, int element)
{
    if (cqueue->curr_size == cqueue->Max_size)
    {
        printf("Queue is full\n");
        return;
    }

    node *newNode = create_new_node();
    newNode->data = element;

    if (cqueue->front == NULL)
    {
        cqueue->front = newNode;
        cqueue->rear = newNode;
        cqueue->curr_size++;
        return;
    }
    cqueue->rear->next = newNode;
    cqueue->rear = newNode;
    cqueue->curr_size++;
}

int Dequeue(CircularQueue *cqueue)
{
    if (cqueue->curr_size == 0)
    {
        printf("Queue is empty\n");
        exit(-1);
    }
    const int frontData = cqueue->front->data;

    node *frontNode = cqueue->front;
    cqueue->front = cqueue->front->next;

    free(frontNode);

    if (cqueue->front == NULL)
    {
        cqueue->rear = NULL;
        cqueue->curr_size = 0;
    }
    cqueue->curr_size--;
    return frontData;
}

int main()
{
    CircularQueue *cqueue = initialize_Queue(5);
    Enqueue(cqueue, 1);
    Enqueue(cqueue, 2);
    Enqueue(cqueue, 3);
    Enqueue(cqueue, 4);
    Enqueue(cqueue, 5);

    // Dequeue(cqueue);
    Enqueue(cqueue, 9);
    while (cqueue->front)
    {
        printf("%d ", Dequeue(cqueue));
    }

    return 0;
}