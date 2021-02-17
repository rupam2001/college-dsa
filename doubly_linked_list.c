#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *create_new_node(int data)
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

void insert_Beg(DoublyLinkedList *dbl, int data)
{
    node *newNode = create_new_node(data);
    if (dbl->head == NULL) //if it is the first node to be inserted bboht tail and head must point to the same node
    {
        dbl->head = newNode;
        dbl->tail = newNode;
        return;
    }

    newNode->next = dbl->head;
    dbl->head->prev = newNode; //dbl->head->prev will always be null since it is the first node, but we are inserting another node at first so it has becom second now
    dbl->head = newNode;       //head always points to the newNode since it is the first node noe
}

void insert_End(DoublyLinkedList *dbl, int data)
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

void insert_at(DoublyLinkedList *dbl, int data, int pos)
{
    node *newNode = create_new_node(data);

    if (dbl->head == NULL) //if it is the first node to be inserted bboht tail and head must point to the same node
    {
        dbl->head = newNode;
        dbl->tail = newNode;
        return;
    }
    if (pos == 0)
    { //insert beg
        newNode->next = dbl->head;
        dbl->head->prev = newNode;
        dbl->head = newNode;
        return;
    }

    node *iterator = dbl->head;

    int counter = -1; //to keep track of the current position of iterator inside the while loop below
    //we will go upto the node just before the position we need to insert in
    while (iterator->next != NULL && counter != pos - 1)
    {
        iterator = iterator->next;
        counter++;
    }

    if (counter != pos - 1) //if counter has not reached the pos - 1 that means iterator->next has become NULL inside the loop that means we have
                            //reached end and still counter is not the node which should be  pos - 1
    {
        printf("Error: invalid index");
        exit(-1);
    }

    //now we are 1 index before the node where we have to insert the new node
    //for that we need to shift

    newNode->prev = iterator; //since newnNode is the node just after the iterator

    if (iterator->next)
    {
        //means there are nodes after this node
        //we have to connect them with our new node
        iterator->next->prev = newNode;
        newNode->next = iterator->next;
    }
    else
    {
        //means iterator is the last node and we need to insert the new node to the end so tail must point to the new end which is newNode
        dbl->tail = newNode;
    }
    //since iterator is the node just before the newNode we have to assign next to newNode
    iterator->next = newNode;
}

int delete_beg(DoublyLinkedList *dbl)
{
    if (dbl->head == NULL)
    {
        printf("List is empty");
        exit(-1);
    }

    int data = dbl->head->data;
    node *firstNode = dbl->head;
    dbl->head = dbl->head->next;
    if (dbl->head)
    {
        dbl->head->prev = NULL;
    }
    else
    {
        dbl->tail = NULL;
    }
    free(firstNode);
    return data;
}

int delete_end(DoublyLinkedList *dbl)
{
    if (dbl->head == NULL)
    {
        printf("List is empty");
        exit(-1);
    }
    int data = dbl->tail->data;
    node *lastNode = dbl->tail;
    dbl->tail = dbl->tail->prev;
    if (dbl->tail)
    {
        dbl->tail->next = NULL;
    }
    else
    {
        dbl->head = NULL;
    }
    free(lastNode);

    return data;
}

int delete_at(DoublyLinkedList *dbl, int pos)
{

    if (dbl->head == NULL)
    {
        printf("List is empty");
        exit(-1);
    }
    if (pos == 0)
    { //delete beg
        node *firstNode = dbl->head;
        dbl->head = dbl->head->next;
        if (dbl->head)
        {
            dbl->head->prev = NULL;
        }
        else
        {
            dbl->tail = NULL;
        }
        int data = firstNode->data;
        free(firstNode);
        return data;
    }

    node *iterator = dbl->head;

    int counter = 0; //to keep track of the current position of iterator inside the while loop below
    //we will go upto the node just before the position we need to insert in
    while (iterator->next != NULL && counter != pos - 1)
    {
        iterator = iterator->next;
        counter++;
    }

    if (counter != pos - 1) //if counter has not reached the pos - 1 that means iterator->next has become NULL inside the loop that means we have
                            //reached end and still counter is not the node which should be  pos - 1
    {
        printf("Error: invalid index");
        exit(-1);
    }

    //now we are 1 index before the node where we have to delete the new node

    node *deadNode = iterator->next; //node to be deleted

    iterator->next = deadNode->next; //iterator is the prev node of deadNode so we need to make the next of iteartor point to the node after the dead node

    if (deadNode->next)
    {
        //that means there are nodes after the dead node
        deadNode->next->prev = iterator; //setting the prev of the node just after the dead node point to the node just before dead node
    }
    int data = deadNode->data;
    free(deadNode);
    return data;
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

#define br printf("\n");

int main()
{
    DoublyLinkedList *dbl = initialize_DoublyLinkedList();
    insert_at(dbl, 1, 0);
    insert_at(dbl, 2, 0);

    display(dbl);

    delete_at(dbl, 0);
    display(dbl);

    return 0;
}