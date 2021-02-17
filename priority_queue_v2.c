#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

node *create_new_node(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Error: Unable to allocate memeory\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct PQueue
{
    node *front;
    node *rear;
} PQueue;

void Enqueue(PQueue *pqueue, int data, int priority)
{
    node *newNode = create_new_node(data);
    newNode->priority = priority;

    if (pqueue->front == NULL)
    {
        pqueue->front = newNode;
        pqueue->rear = newNode;
        return;
    }
    node *iterator = pqueue->front;

    if (iterator->next == NULL && iterator->priority > priority)
    {
        newNode->next = iterator;
        pqueue->front = newNode;
        return;
    }

    while (iterator->next)
    {
        if (iterator->priority > priority)
        {
            newNode->next = iterator->next;
            iterator->next = newNode;
            return;
        }
        iterator = iterator->next;
    }
    iterator->next = newNode;
}

void display(PQueue *pqueue)
{
    node *iterator = pqueue->front;
    while (iterator)
    {
        printf("%d ", iterator->data);
        iterator = iterator->next;
    }
    printf("\n");
}

int main()
{
    PQueue *pq = (PQueue *)malloc(sizeof(PQueue));
    pq->front = NULL;
    pq->rear = NULL;

    Enqueue(pq, 120, 1);
    Enqueue(pq, 10, 2);
    Enqueue(pq, 1280, 0);
    Enqueue(pq, 12890, 0);
    Enqueue(pq, 8790, 0);

    display(pq);

    return 0;
}