#include <stdio.h>
#include <string.h>

#define SIZE 5

void BFS(const int size, char *vertexs, int adj[][size], int start)
{
    // the queue to reference the vertex by holding the indices of  vertex fron vertexs array
    int queue[size];

    int front = 0, rear = 0;

    //the array to keep track of the visited vertex by storing 1 at the position of the visited vertexes from vertexs array
    int visited[size];
    memset(visited, 0, size * sizeof(visited[0])); //initially none is visited so all are set to 0

    //enqueue the index of the starter node
    queue[rear] = start;

    //print the starter vertex
    printf("%c ", vertexs[start]);

    //mark starter vertex as visited
    visited[start] = 1;

    while (front <= rear) //until the queue is empty
    {
        //dequeue  the queue
        int v = queue[front]; // v holds the position of the current vertex
        front++;

        for (int i = 1; i < size; i++) //travers the adjucency list for this node
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                printf("%c ", vertexs[i]);
                //mark it as visited
                visited[i] = 1;

                //Enqueue the visited node  so that we can get the adjucency list of it later
                rear++;
                queue[rear] = i;
            }
        }
    }
}

int main()
{

    char vertexs[SIZE] = {'A', 'B', 'C', 'D', 'E'};

    int adj[SIZE][SIZE] = {
        // A, B, C, D, E
        {0, 1, 1, 1, 0}, // A
        {0, 0, 0, 1, 1}, // B
        {0, 0, 0, 1, 0}, // C
        {0, 0, 0, 0, 1}, // D
        {0, 0, 0, 0, 0}  // E
    };

    BFS(SIZE, vertexs, adj, 3);

    return 0;
}