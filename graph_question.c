#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int size = 5;

    node *graph = create_graph(size); //the graph is array of strutures
    graph = input(graph, size);
    display(graph, size);

    // BFS(graph, size, 0);

    return 0;
}

// int **getAdjList(node *graph, int size)
// {

//     int **adj = (int **)malloc(num * sizeof(int *));
//     for (int i = 0; i < size; i++)
//     {
//         memset(adj[i], 0, sizeof(int));
//     }

//     for (int i = 0; i < size; i++)
//     {
//         node *itr = graph[i];

//         while (itr)
//         {

//             int v = itr->vertext;
//             for (int j = 0; j < size; j++)
//             {
//                 if (v == graph[j].vertext)
//                 {
//                     adj[i][j] = 1;
//                 }
//             }
//             itr = itr->next;
//         }
//     }
//     return adj;
// }

// void display(int size, int adj[][size])
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             printf("%d ", adj[i][j]);
//         }
//         printf("\n");
//     }
// }