#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
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

void insertBeg(node **head, int data)
{

    node *newNode = create_new_node(data);

    if (*head == NULL)
    {
        (*head) = newNode;
        newNode->next = newNode;
        return;
    }
    node *iterator = (*head);

    while (iterator->next != *head)
    {
        iterator = iterator->next;
    }
    newNode->next = (*head);
    iterator->next = newNode;
    (*head) = newNode;
}

void insertEnd(node **head, int data)
{
    node *newNode = create_new_node(data);

    if (*head == NULL)
    {
        (*head) = newNode;
        newNode->next = newNode;
        return;
    }

    node *iterator = (*head);

    while (iterator->next != *head)
    {
        iterator = iterator->next;
    }
    newNode->next = *head;
    iterator->next = newNode;
}

int deleteBeg(node **head)
{
    if (*head == NULL)
    {
        printf("Error: list is emepty");
        exit(-1);
    }

    node *iterator = (*head);

    while (iterator->next != *head)
    {
        iterator = iterator->next;
    }

    node *temp = (*head);
    int data = temp->data;
    (*head) = (*head)->next;
    iterator->next = *head;
    free(temp);

    return data;
}

void display(node *head)
{
    node *iterator = head;
    if (iterator == NULL)
        return;

    do
    {
        printf("%d ", iterator->data);
        iterator = iterator->next;
    } while (iterator != head);
}

int main()
{
    node *cll = (node *)malloc(sizeof(node));
    cll = NULL;

    insertBeg(&cll, 1);
    // insertBeg(&cll, 2);
    // insertBeg(&cll, 3);
    // insertEnd(&cll, 9);

    deleteBeg(&cll);

    display(cll);

    return 0;
}