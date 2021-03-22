#include <stdio.h>
#include <stdlib.h>

#define br printf("\n")

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

void preorder(const node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// void inorder(const node *root)
// {
//     if (!root)
//         return;
//     inorder(root->left);
//     printf("%d ", root->data);
//     inorder(root->right);
// }

void postorder(const node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

node *search(node *root, int data)
{
    node *ptr;
    if (!root)
        return NULL;
    if (root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    if (root->data > data)
        return search(root->left, data);
}

// void show(const node *ptr)
// {
//     if (!ptr)
//     {
//         printf("not found");
//         return;
//     }
//     printf("%d ", ptr->data);
// }

node *delete (node *root, int data)
{

    if (root == NULL)
        return root;
    //these are just searching for the data to be deleted
    if (data < root->data)
        root->left = delete (root->left, data);

    else if (data > root->data)
        root->right = delete (root->right, data);
    //this is where actual deletion is happening
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            //if the left is NULL that means tis only one child which is right..
            // we return the right child and it will be added in the above searching  where we assign it by calling the delete recursively
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            //means it has one child and it is the left  (read the above comment)
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // inorder successor:   go right then go left only as much as you can 

        struct node *temp = root;
        temp = temp->right;
        while (temp && temp->left)
            temp = temp->left;

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete (root->right, temp->data);
    }
    return root;
}

int main()
{
    node *tree = NULL;

    insert(&tree, 1);
    insert(&tree, 2);
    insert(&tree, 3);
    insert(&tree, 4);
    insert(&tree, 5);
    insert(&tree, 6);
    insert(&tree, 7);
    insert(&tree, 8);
    // insert(&tree, 13);

    preorder(tree);

    // postorder(tree);
    // br;

    // tree = delete (tree, 6);
    // postorder(tree);
    // br;

    // node *searched = search(tree, 13);
    // if (searched)
    //     printf("%d ", searched->data);

    return 0;
}