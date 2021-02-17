#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Stack
{
    node *top;
    int MAX_SIZE;
    int size;
} Stack;

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

void insert_beg(node **head, int data)
{
    if (*head == NULL)
    {
        node *newNode = create_new_node();
        newNode->data = data;
        *head = newNode;
    }
    node *newNode = create_new_node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
int delete_beg(node **head)
{

    int temp = (*head)->data;
    node *first = (*head);
    (*head) = (*head)->next;
    free(first);
    return temp;
}

Stack *initialize_stack(int max_size)
{
    Stack *stack = (Stack *)malloc(sizeof(stack));
    stack->MAX_SIZE = max_size;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack *stack, int element)
{
    if (stack->size == stack->MAX_SIZE)
    {
        printf("Stack overflow\n");
        exit(-1);
    }

    insert_beg(&stack->top, element);
    stack->size++;
}

int pop(Stack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack underflow");
        exit(-1);
    }
    return delete_beg(&stack->top);
}

int main()
{
    Stack *stack = initialize_stack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);

    for (int i = 0; i < stack->size; i++)
    {
        printf("%d \n", pop(stack));
    }
    return 0;
}
