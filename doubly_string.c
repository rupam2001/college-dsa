#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *prev;
    struct node *next;
} node;

node *create_new_node(char data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Error: Unable o allocate memory\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

typedef struct DoublyLinkedList
{
    node *head;
    node *tail;
} DoublyLinkedList;

DoublyLinkedList *initialize_DoublyLinkedList()
{
    DoublyLinkedList *dbl = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    dbl->head = NULL;
    dbl->tail = NULL;
    return dbl;
}

void insert_End(DoublyLinkedList *dbl, char data)
{
    node *newNode = create_new_node(data);
    if (dbl->head == NULL) //if it is the first node to be inserted bboht tail and head must point to the same node
    {
        dbl->head = newNode;
        dbl->tail = newNode;
        return;
    }
    dbl->tail->next = newNode; //making the current last nodes next field to point to the newly created node
    newNode->prev = dbl->tail; //making the newNodes prev to point to the current last node
}

void display(DoublyLinkedList *dbl)
{
    node *iterator = dbl->head;
    while (iterator)
    {
        printf("%d ", iterator->data);
        iterator = iterator->next;
    }
}

int isEqual(DoublyLinkedList *str1, DoublyLinkedList *str2)
{

    node *itr1 = str1->head;
    node *itr2 = str2->head;

    int count1 = 0, count2 = 0;

    while (itr1 && itr2)
    {
        if (itr1->data != itr2->data)
            return 0;
        itr1 = itr1->next;
        itr2 = itr2->next;
        if (itr1)
            count1++;
        if (itr2)
            count2++;
    }
    if (count1 != count2)
        return 0;
    return 1;
}

#define br printf("\n");

int main()
{
    DoublyLinkedList *str1 = initialize_DoublyLinkedList();

    insert_End(str1, 'r');
    insert_End(str1, 'u');
    insert_End(str1, 'p');
    insert_End(str1, 'a');
    insert_End(str1, 'm');

    DoublyLinkedList *str2 = initialize_DoublyLinkedList();

    insert_End(str2, 'r');
    insert_End(str2, 'u');
    insert_End(str2, 'p');
    insert_End(str2, 'a');
    insert_End(str2, 'm');

    if (isEqual(str1, str2))
    {
        printf("Equal\n");
    }
    else
    {
        printf("Not equal\n");
    }

    return 0;
}