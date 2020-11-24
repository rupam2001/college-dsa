#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int **make_partition(int *stack, int num_parts)
{
    if (MAX_SIZE % num_parts != 0)
    {
        printf("NOT MULTIPLE OF %d", MAX_SIZE);
        exit(-1);
    }
    int each_len = MAX_SIZE / num_parts;

    int **range = (int **)malloc(sizeof(int **) * each_len);
    for (int i = 0; i < each_len; i++)
    {
        range[i] = (int *)malloc(sizeof(int *) * 2);
        range[i][0] = each_len * i - 1;
        range[i][1] = each_len * (i + 1);
    }
    return range;
}

void push(int *stack, int **range, int part, int element)
{
    //check if full
    if (range[part][0] == range[part][1] - 1)
    {
        printf("Part %d is full", part);
        exit(-1);
    }
    range[part][0]++;
    stack[range[part][0]] = element;
}

void display(int *stack, int **range)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // if(range[i][0] == range[i][])
        for (int j = 0; j < range[i][1]; j++)
        {
            printf("%d", stack[range[i][1] - 1 + j]);
        }
        printf("/n");
    }
}

int main()
{
    int stack[MAX_SIZE];
    int **range = make_partition(stack, 5);

    push(stack, range, 0, 1);
    display(stack, range);

    return 0;
}