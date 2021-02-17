#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

//function prototypes for stack
void push(char *, int *, char);
char pop(char *, int *);
void display(char *, int);
//

//stack applications
void palindromCheck();
//

int main()
{
    char stack[MAX_SIZE];
    int top = -1;

    int choice;
    char element;

    while (1)
    {
        printf("Enter your choice push:0, pop:1, display:2, pelindrom check 3 >>> ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice)
        {
        case 0:
            printf("(Push choosen)\n Enter the element >> ");
            scanf("%c", &element);
            push(stack, &top, element);
            break;
        case 1:
            printf("(Pop choosen)\n");
            printf("Element poped is %c\n", pop(stack, &top));
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
        // fflush(stdin);
    }
    return 0;
}

//function definations

void push(char *stack, int *top, char element)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

char pop(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    char temp = stack[*top];
    *top = *top - 1;
    return temp;
}

void display(char *stack, int top)
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= top; i++)
        printf(" %c ", stack[i]);
    printf("]\n");
}
//

void palindromCheck()
{
    char string[MAX_SIZE];
    printf("Enter the word to check if it is palindrom > ");
    fflush(stdin);
    // getchar();
    fgets(string, MAX_SIZE, stdin);

    //getting the lenght of the string
    int len = -1;
    while (string[++len] != '\n')
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
    char stack[len / 2 + 1];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (i < len / 2)
            push(stack, &top, string[i]); //pushing in to the stack
        else if (i == len / 2 && len % 2 != 0)
            continue;                           //ignoring the middle if odd length
        else if (pop(stack, &top) != string[i]) //poping and checking
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}