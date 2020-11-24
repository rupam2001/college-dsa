#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100


void push(char* stack, int* top, char element){
    if(*top == MAX_SIZE - 1){
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}

int pop(char *stack, int *top){
    if(*top == -1){
        printf("Stack underflow\n");
        exit(-1);
    }
    // printf("ELement poped: %d\n", stack[*top]);
    *top = *top - 1;
    return stack[*top + 1];
}

void display(char *stack, int top){
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    for(int i = 0; i <= top; i++)
        printf("%c ", stack[i]);
    printf("\n");
}


void paranthesis(char* input, int size){
    char stack[MAX_SIZE];
    int top = -1;

    for(int i = 0; i < size; i++ ){
        if(input[i] == '+' || input[i] == '-'){
           int poped = pop(stack, &top);
           push(stack, &top, '(');
           push(stack, &top ,poped);
           push(stack, &top, input[i]);
        }
        else if(input[i] == '/' || input[i] == '*'){
            push(stack, &top, ')');
            push(stack, &top, input[i]);
        }

        else{
            push(stack, &top, input[i]);
        }
    }
    display(stack, top);
}


int main(){
    char *input =  "3*2+5/2-3+10";
    int size = 12;
    paranthesis(input, size);

    return 0;
}
