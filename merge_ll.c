#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void memoryCheck(struct node *ptr)
{
    if (!ptr)
    {
        printf("Unable to allocate memory\n");
        exit(-1);
    }
}

struct node *insertBeg(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    memoryCheck(newNode);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct node *insertEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    memoryCheck(newNode);
    newNode->data = data;
    newNode->next = NULL;
    if (!head)
    {
        head = newNode;
        return head;
    }

    struct node *iterator = head;
    while (iterator->next)
    {
        iterator = iterator->next;
    }
    iterator->next = newNode;
    return head;
}

struct node *insert(struct node *head, int data, int pos)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    memoryCheck(newNode);
    newNode->data = data;
    if (pos == 0)
        return insertBeg(head, data);

    struct node *iterator = head;
    int counter = 0;
    while (counter != pos - 1 && iterator->next)
    {
        iterator = iterator->next;
        counter++;
    }

    if (counter != pos - 1)
    {
        printf("Invalid index\n");
        exit(-1);
    }
    if (!iterator->next)
        return insertEnd(head, data);
    newNode->next = iterator->next;
    iterator->next = newNode;
    return head;
}

struct node *deleteBeg(struct node *head)
{
    if (!head)
    {
        printf("Nothing to delete(list is empty)\n");
        exit(-1);
    }
    struct node *to_be_deleted = head;
    head = head->next;
    free(to_be_deleted);
    return head;
}
struct node *deleteEnd(struct node *head)
{
    if (!head)
    {
        printf("Nothing to delete(list is empty)\n");
        exit(-1);
    }
    if (!head->next)
    {
        struct node *to_be_deleted = head;
        head = NULL;
        free(to_be_deleted);
        return head;
    }
    struct node *iterator = head->next, *prev = head;
    while (iterator->next)
    {
        iterator = iterator->next;
        prev = prev->next;
    }
    free(iterator);
    prev->next = NULL;
    return head;
}

struct node *delete (struct node *head, int pos)
{

    if (pos == 0)
        return deleteBeg(head);

    struct node *iterator = head;
    int counter = 0;
    while (counter != pos - 1 && iterator->next)
    {
        iterator = iterator->next;
        counter++;
    }

    if (counter != pos - 1)
    {
        printf("Invalid index\n");
        exit(-1);
    }
    if (!iterator->next)
        return deleteEnd(head);
    struct node *to_be_deleted = iterator->next;
    iterator->next = iterator->next->next;
    free(to_be_deleted);

    return head;
}

void traverse(struct node *head)
{
    struct node *iterator = head;
    printf("[");
    while (iterator)
    {
        printf(" %d ", iterator->data);
        iterator = iterator->next;
    }
    printf("]\n");
}

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *i = head1, *j = head2, *head;

    if (i->data < j->data)
    {
        head = i;
        i = i->next;
    }
    else
    {
        head = j;
        j = j->next;
    }

    while (i && j)
    {
        if (i->data < j->data)
        {
            head->next = i;
            i = i->next;
            head = head->next;
        }
        else
        {
            head->next = j;
            j = j->next;
            head = head->next;
        }
    }
    while (i)
    {
        head->next = i;
        i = i->next;
        head = head->next;
    }
    while (j)
    {
        head->next = j;
        j = j->next;
        head = head->next;
    }
    if (head1->data < head2->data)
        return head1;
    return head2;
}

int main()
{
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 4);
    list1 = insertEnd(list1, 5);
    list1 = insertEnd(list1, 7);

    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 3);
    list2 = insertEnd(list2, 6);
    list2 = insertEnd(list2, 8);

    struct node *ml = merge(list1, list2);

    traverse(ml);

    return 0;
}