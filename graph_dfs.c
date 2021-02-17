#include <stdio.h>
#include <string.h>

#define SIZE 5

void DFS(const int size, char *vertexs, int adj[size][size], int start)
{
    int stack[size]; //stack will hold the indeices of the vertexes
    int top = -1;

    int visited[size];
    memset(visited, 0, size * sizeof(visited[0])); //initialize to zero (memset function's source: string.h)

    //ipush the starter vertex's index and mark as visited
    stack[++top] = start;
    visited[start] = 1;

    //until the  stack is not empty
    while (top >= 0)
    {
        //Pop from the stack and display it
        int poped = stack[top];
        top--;
        printf("%c ", vertexs[poped]);

        //iterate over the adjaceny row for the poped vertex
        for (int i = size - 1; i >= 0; i--)
        {
            if (adj[poped][i] == 1 && visited[i] == 0) //if the vertex is adjacent and is not visited
            {
                //push it to the stack and marked as visited
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    char vertexs[SIZE] = {'A', 'B', 'C', 'D', 'E'};

    int adj[SIZE][SIZE] = {
        // A, B, C, D, E
        {0, 1, 0, 0, 1}, // A
        {0, 0, 1, 1, 0}, // B
        {0, 0, 0, 1, 0}, // C
        {1, 0, 0, 0, 0}, // D
        {0, 0, 0, 1, 0}  // E
    };
    DFS(SIZE, vertexs, adj, 0);
    return 0;
}