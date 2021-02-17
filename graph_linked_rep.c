#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertext;
    int weight;
    struct node *next;
} node;

node *create_new_node(int vertext, int weight)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertext = vertext;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

node *create_graph(int num)
{
    node *adj = (node *)malloc(num * sizeof(node));

    if (!adj)
    {
        printf("Memory Error\n");
        exit(-1);
    }
    return adj;
}

node *input(node *adj, int num)
{

    int adjNodeNum;
    node *last;

    int temp_vertext, temp_weight;

    for (int i = 0; i < num; i++)
    {

        printf("Enter the node %d: ", i + 1);
        scanf("%d", &(adj[i].vertext));

        last = &adj[i];

        printf("Enter the number of adjucent nodes of this node: ");
        scanf("%d", &adjNodeNum);

        printf("Enter all the adjucent nodes vertext, weight : ");
        for (int j = 0; j < adjNodeNum; j++)
        {

            scanf("%d %d", &temp_vertext, &temp_weight);
            node *newNode = create_new_node(temp_vertext, temp_weight);
            last->next = newNode;
            last = newNode;
        }
    }
    return adj;
}

void display(node *adj, int num)
{
    printf("\n\n");
    node *itr;
    for (int i = 0; i < num; i++)
    {
        itr = &adj[i];

        printf("[v = %d]-", itr->vertext);
        itr = itr->next;
        while (itr)
        {

            printf("%d->(v = %d)", itr->weight, itr->vertext);
            itr = itr->next;
            if (itr)
                printf("-");
        }
        printf("\n\n");
    }
}

int main()
{
    node *graph = create_graph(5);
    graph = input(graph, 5);
    display(graph, 5);

    return 0;
}