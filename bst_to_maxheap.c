#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create_new_node(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Error: Unable to allocate memory\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(node **root, int data)
{
    node *newNode = create_new_node(data);
    if (!*root)
    {
        (*root) = newNode;
        return;
    }
    node *ptr = *root;
    while (ptr)
    {
        if (data < ptr->data)
        {
            if (ptr->left == NULL)
            {
                ptr->left = newNode;
                return;
            }
            ptr = ptr->left;
            continue;
        }
        if (ptr->right == NULL)
        {
            ptr->right = newNode;
            return;
        }
        ptr = ptr->right;
    }
}

void inorder(node **root, void (*fun)(node *ptr))
{
    if (*root == NULL)
        return;
    inorder(&(*root)->left, fun);
    fun(*root);
    inorder(&(*root)->right, fun);
}

void postorder(node **root, void (*fun)(node *ptr))
{
    if (*root == NULL)
        return;
    postorder(&(*root)->left, fun);
    postorder(&(*root)->right, fun);
    fun(*root);
}



void toHeap(node **tree)
{
}

int main()
{
    return 0;
}