#include <stdio.h>
#include <stdlib.h>

#define Error(msg)            \
    printf("Error: %s", msg); \
    exit(-1);
#define true 1
#define false 0

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNewNode(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (!newNode)
    {
        printf("Memory error: Unable to allocate memeory\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct node *insertBeg(struct node *head, int data)
{
    struct node *newNode = createNewNode(data);

    if ((head) == NULL)
    {

        newNode->next = newNode;
        newNode->prev = newNode;
        (head) = newNode;
        return head;
    }

    newNode->next = (head);
    newNode->prev = (head)->prev;

    (head)->prev->next = newNode;

    (head)->prev = newNode;
    (head) = newNode;
    return head;
}
struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = createNewNode(data);

    if ((head) == NULL)
    {

        newNode->next = newNode;
        newNode->prev = newNode;
        (head) = newNode;
        return head;
    }

    head->prev->next = newNode; //lastnode->next = newNode
    newNode->prev = head->prev;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

struct node *insert(struct node *head, int data, int pos)
{

    if ((head) == NULL || pos == 0)
        return insertBeg(head, data);

    struct node *iterator = head;
    int counter = 0;
    while (counter != pos - 1 && iterator->next != head)
    {
        iterator = iterator->next;
        counter++;
    }

    if (counter != pos - 1)
    {
        Error("Invalid pos\n")
    }
    if (iterator->next == head)
        return insertEnd(head, data);

    struct node *newNode = createNewNode(data);

    newNode->next = iterator->next;
    newNode->prev = iterator;
    iterator->next->prev = newNode;
    iterator->next = newNode;
    return head;
}

struct node *deleteBeg(struct node *head)
{

    if (head == NULL)
    {
        Error("Trying to delete from an empty list\n")
    }
    if (head->next == head)
    {
        head = NULL;
        return head;
    }
    struct node *first_node = head;
    head = head->next;
    head->prev = first_node->prev;
    first_node->prev->next = head;
    free(first_node);
    return head;
}

struct node *deleteEnd(struct node *head)
{

    if (head == NULL)
    {
        Error("Trying to delete from an empty list\n")
    }
    if (head->next == head)
    {

        head = NULL;
        return head;
    }
    struct node *last_node = head->prev;
    head->prev = last_node->prev;
    last_node->prev->next = head;
    free(last_node);
    return head;
}
struct node *delete (struct node *head, int pos)
{

    if (head == NULL)
    {
        Error("Trying to delete from an empty list\n")
    }

    if (head->next == head || pos == 0)
    {
        return deleteBeg(head);
    }

    struct node *iterator = head;
    int counter = 0;
    while (counter != pos && iterator->next != head)
    {
        iterator = iterator->next;
        counter++;
    }
    if (counter != pos)
    {
        Error("Invalid pos\n")
    }
    // printf("pos %d", iterator->data);

    if (iterator->next == head)
        return deleteEnd(head);

    iterator->prev->next = iterator->next;
    iterator->next->prev = iterator->prev;
    free(iterator);

    return head;
}

void traverse(struct node *head, void (*callback)(struct node *), int rev)
{

    /*
        THIS FUNCTION TRAVERSES THE ENITIRE LIST AND CALLS THE CALLBACK FUNCTION FOR EACH ELEMENT.
        
        the rev arg determines whether to go from head to tail or tail to head
        
    */

    if (!head)
        return;

    struct node *iterator = rev ? head->prev : head;
    do
    {
        callback(iterator);
        iterator = rev ? iterator->prev : iterator->next;
    } while (iterator != (rev ? head->prev : head));
}

void printFn(struct node *ptr)
{
    printf(" %d ", ptr->data);
}

void display(struct node *head)
{
    printf("[");
    traverse(head, printFn, false);
    printf("]\n");
}
void displayRev(struct node *head)
{
    printf("[");
    traverse(head, printFn, true);
    printf("]\n");
}

struct node *CircularDoublyLinkedList()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode = NULL;
    return newNode;
}

int main()
{
    struct node *cdll = CircularDoublyLinkedList();

    cdll = insertEnd(cdll, 8);
    cdll = insertEnd(cdll, 9);
    cdll = insert(cdll, 99, 2);
    // insertBeg(&cdll, 2);
    // insertBeg(&cdll, 3);
    // insertBeg(&cdll, 4);
    display(cdll);

    displayRev(cdll);

    return 0;
}