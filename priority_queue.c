#include <stdio.h>
#include <stdlib.h>

//node for each level
struct node
{
    int data;
    struct node *next;
};

struct node *createNewNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Memory Error: Unable to allocate memory\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct PriorityQueue
{
    struct node **fronts;                               //holds  fronts for each of the level
    struct node **rears;                                // holds rear for each of the level
    int num_levels;                                     //number of levels
    int max_size;                                       //size of the each level
    int *each_levels_current_rear_pos;                  //the position of rear for each level
    void (*Enqueue)(struct PriorityQueue **, int, int); //function pointer to enqueue    args:(queue, element, priority_level)
    int (*Dequeue)(struct PriorityQueue **);            //function pointer to dequeue               args:(queue)
};

void Enqueue(struct PriorityQueue **pq, int element, int priority_level)
{
    //checking if the level is full
    if ((*pq)->each_levels_current_rear_pos[priority_level - 1] == (*pq)->max_size - 1)
    {
        printf("Unable to Enqueue, level %d is full\n", priority_level);
        exit(-1);
    }
    //if the level is empty
    if ((*pq)->fronts[priority_level - 1] == NULL)
    {
        //create anew node and point the front and rear of this level to that node
        struct node *newQueueNode = createNewNode(element);
        (*pq)->fronts[priority_level - 1] = newQueueNode;
        (*pq)->rears[priority_level - 1] = newQueueNode;
        (*pq)->each_levels_current_rear_pos[priority_level - 1]++;
        return;
    }

    //create a new node and insert it at the end of the current level
    struct node *newQueueNode = createNewNode(element);
    (*pq)->rears[priority_level - 1]->next = newQueueNode;
    (*pq)->rears[priority_level - 1] = newQueueNode;
    (*pq)->each_levels_current_rear_pos[priority_level - 1]++;
}

int Dequeue(struct PriorityQueue **pq)
{

    int dequeued_element; //to hold the data of the element which is going to be dequeued

    //iterate through all the levels until a nonempty level found then remove the front of that level
    for (int level = 0; level < (*pq)->num_levels; level++)
    {
        if ((*pq)->rears[level] != NULL)
        {
            //gettinh the front of the level
            struct node *first_node = (*pq)->fronts[level];
            dequeued_element = first_node->data;

            //making the front point to the next element of this level
            (*pq)->fronts[level] = (*pq)->fronts[level]->next;

            free(first_node); //free the elemnt which was at front before

            //if the level becomes empty
            if ((*pq)->fronts[level] == NULL)
            {
                //fronts and rear will point to NULL and rears position will be -1
                (*pq)->rears[level] == NULL;
                (*pq)->each_levels_current_rear_pos[level] = -1;
            }
            return dequeued_element;
        }
    }

    //if no nonempty level is found that means queue is empty
    printf("Queue is empty\n");
    exit(-1);
}

struct PriorityQueue *InitializePriorityQueue(int num_levels, int max_size)
{

    //create a priorityqueue structure
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->num_levels = num_levels;
    pq->max_size = max_size;

    //allocation the array for fronts and rears of type node*   eg: [node*, node*, node*....(up to num_levels)]
    pq->fronts = (struct node **)malloc(num_levels * sizeof(struct node));
    pq->rears = (struct node **)malloc(num_levels * sizeof(struct node));

    pq->each_levels_current_rear_pos = (int *)malloc(num_levels * sizeof(int));

    //iterate throgh all the levels of front and rear and initialize them with NULL
    for (int i = 0; i < num_levels; i++)
    {
        pq->fronts[i] = NULL;
        pq->rears[i] = NULL;
        pq->each_levels_current_rear_pos[i] = -1; //position of rear will be -1 initialy
    }

    pq->Dequeue = &Dequeue;
    pq->Enqueue = &Enqueue;
}

void DisplayLevelOrderAll(const struct PriorityQueue *pq)
{
    for (int level = 0; level < pq->num_levels; level++)
    {
        printf("Level %d [", level + 1);
        if (pq->each_levels_current_rear_pos[level] >= 0)
        {
            struct node *iterator = pq->fronts[level];
            while (iterator)
            {

                printf(" %d ", iterator->data);
                iterator = iterator->next;
            }
        }
        printf("]\n");
    }
}

//Menu

void input(char *stdout_msg, int *stdin_var)
{
    printf("%s", stdout_msg);
    scanf("%d", &(*stdin_var));
}

void MENU()
{
    int num_level, max_size;

    input("Enter the number of levels you want > ", &num_level);
    input("Enter the max size for the all levels > ", &max_size);

    struct PriorityQueue *pq = InitializePriorityQueue(num_level, max_size);

    int queue_element, priority_level, choice;

    while (1)
    {

        input("Enter choice: \n Enqueue: 1, Dequeue: 2, Display 3,  Exit: 4 > ", &choice);
        switch (choice)
        {
        case 1:
            printf("(Enqueue selected)\n");
            input("Enter the element and  prority level: ", &queue_element);
            input("", &priority_level);
            pq->Enqueue(&pq, queue_element, priority_level);
            printf("<<Success>>\n");
            break;
        case 2:
            printf("(Dequeue selected)\n");
            printf("<<Success>> element dequeued: %d\n", pq->Dequeue(&pq));
            break;

        case 3:
            printf("(Display selected)\n");
            DisplayLevelOrderAll(pq);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("###Invalid choice###\n");
            break;
        }
    }
}

int main()
{

    MENU();
    return 0;
}