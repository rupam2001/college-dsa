#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//function prototypes for stack
void push(int *, int *, int);
int pop(int *, int *);
void display(int *, int);
//

//stack applications
void palindromCheck();
//

int main()
{
    int stack[MAX_SIZE];
    int top = -1;

    int choice;
    int element;

    while (1)
    {
        printf("Enter your choice push:0, pop:1, display:2, pelindrom check 3 >>> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("(Push choosen)\n Enter the element >> ");
            scanf("%d", &element);
            push(stack, &top, element);
            break;
        case 1:
            printf("(Pop choosen)\n");
            printf("Element poped is %d\n", pop(stack, &top));
            break;
        case 2:
            printf("(Display choosen)\n");
            display(stack, top);
            break;
        case 3:
            printf("(Pelindrom check choosen)\n");
            palindromCheck();
            break;
        default:
            printf("Exit..");
            return 0;
            break;
        }
    }
    return 0;
}

//function definations

void push(int *stack, int *top, int element)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

int pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    int temp = stack[*top];
    *top = *top - 1;
    return temp;
}

void display(int *stack, int top)
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= top; i++)
        printf(" %d ", stack[i]);
    printf("]\n");
}
//

void palindromCheck()
{
    char string[MAX_SIZE];
    printf("Enter the word to check if it is palindrom > ");
    fflush(stdin);
    gets(string);

    //getting the lenght of the string
    int len = -1;
    while (string[++len] != '\0')
        ;

    if (!len)
    {
        printf("You did not enter any string\n");
        return;
    }

    /*
        initialize a stack of length half of the original string
        push up to the half of length of characters to the stack
        pop from the stack and check if it is equal to the current character of the string (ie from half of the length of the string onward)
        if at any point it is not equal then it is not plaindrom
        else it is palindrom
    */
    int stack[len / 2], top = -1;

    for (int i = 0; i < len; i++)
    {
        if (i <= len / 2)
            push(stack, &top, string[i]);       //pushing int to the stack
        else if (pop(stack, &top) != string[i]) //poping and checking
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}