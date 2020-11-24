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

int main()
{
    struct node *list = NULL;

    int choice;
    int list_element;
    int list_element_pos;

    while (1)
    {
        printf("Enter your choice insertBeg: 0, insertEnd: 1, insert: 2, deleteBeg: 3, deleteEnd: 4, delete: 5, traver: 6 >> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("(insertBeg choosen)\n");
            printf("enter the element > ");
            scanf("%d", &list_element);
            list = insertBeg(list, list_element);
            break;
        case 1:
            printf("(insertEnd choosen)\n");
            printf("enter the element > ");
            scanf("%d", &list_element);
            list = insertEnd(list, list_element);
            break;
        case 2:
            printf("(insert choosen)\n");
            printf("enter the element and the position > ");
            scanf("%d %d", &list_element, &list_element_pos);
            list = insert(list, list_element, list_element_pos);
            break;
        case 3:
            printf("(deleteBeg choosen)\n");

            list = deleteBeg(list);
            break;
        case 4:
            printf("(deleteEnd choosen)\n");
            list = deleteEnd(list);
            break;
        case 5:
            printf("(delete choosen)\n");
            printf("enter the position > ");
            scanf("%d", &list_element_pos);
            list = delete (list, list_element_pos);
            break;
        case 6:
            printf("(traverse choosen)\n");
            traverse(list);
            break;
        default:
            printf("Exiting..");
            return 0;
            break;
        }
    }
    return 0;
}