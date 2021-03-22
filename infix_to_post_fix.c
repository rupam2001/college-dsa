#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define true 1
#define false 0

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

int pop(char *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        exit(-1);
    }
    *top = *top - 1;
    return stack[*top + 1];
}

void toPostfix(char *infix, int size, int verbose)
{

    char postfix[size]; //result
    int p = 0;

    char stack[size];
    int top = -1;

    for (int i = 0; i < size && infix[i] != '\0'; i++)
    {
        if (infix[i] == ' ')
            continue;
        if (infix[i] == '+' || infix[i] == '-')
        {
            while (stack[top] == '*' || stack[top] == '+' || stack[top] == '-' || stack[top] == '/')
                postfix[p++] = pop(stack, &top);

            push(stack, &top, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                postfix[p++] = pop(stack, &top);

            pop(stack, &top);
        }
        else if (infix[i] == '(' || infix[i] == '*' || infix[i] == '/')
            push(stack, &top, infix[i]);

        else
            postfix[p++] = infix[i];

        if (verbose)
        {

            printf("%d =>\nStack: ", i);
            for (int j = 0; j <= top; j++)
                printf("%c ", stack[j]);
            printf("\noutput: ");
            for (int j = 0; j < p; j++)
                printf("%c", postfix[j]);
            printf("\n");
        }
    }
    while (top != -1)
        postfix[p++] = pop(stack, &top);

    for (int i = 0; i < p; i++)
        printf("%c", postfix[i]);
    printf("\n");
}

int main()
{
    // char* infix = "a+b*c+(d*e+f)*g";
    // char *infix = " ( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J )\0";
    char *infix = "A+B*C+D\0";
    // char *infix2 = "a+b*c+(d*e+f)*g";
    toPostfix(infix, 8, true);
    return 0;
}
