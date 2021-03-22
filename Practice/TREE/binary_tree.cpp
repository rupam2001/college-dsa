#include <iostream>
#include "tree.h"
using namespace std;

class BST : public Tree
{

private:
    Node *delUtil(Node *itr, int data)
    {

        if (itr == NULL)
            return itr;

        if (data < itr->data)
            itr->left = delUtil(itr->left, data);
        else if (data > itr->data)
            itr->right = delUtil(itr->right, data);

        else
        {
            /**
         * 3 conditions
         * no child
         * 1 child 
         * 2 children 
         */
            if (itr->left == NULL && itr->right == NULL)
            {
                //having no child
                free(itr);
                return NULL;
            }
            if (itr->left == NULL)
            {
                //having right child
                Node *temp = itr->right;
                free(itr);
                return temp;
            }
            if (itr->right == NULL)
            {
                //having left child
                Node *temp = itr->left;
                free(itr);
                return temp;
            }

            //having 2 child
            //>>> find in order successor
            Node *inorder_succ = itr;
            inorder_succ = inorder_succ->right;
            while (inorder_succ && inorder_succ->left)
            {
                inorder_succ = inorder_succ->left;
            }
            //copy the content of inorder successor to the node to be deleted
            itr->data = inorder_succ->data;

            //delete the inorder successor but rember that this inorder successor may have other nodes (right nodes only!) so we need to called delete right
            itr->right = delUtil(itr->right, inorder_succ->data);
        }
        return itr;
    }

public:
    void insert(int d) override
    {
        if (root == NULL)
        {
            root = new Node(d);
            return;
        }
        Node *itr = root;
        Node *newNode = new Node(d);
        while (itr)
        {
            if (d < itr->data)
            {
                if (itr->left == NULL)
                {
                    itr->left = newNode;
                    return;
                }
                itr = itr->left;
            }
            else
            {
                if (itr->right == NULL)
                {
                    itr->right = newNode;
                    return;
                }
                itr = itr->right;
            }
        }
    }
    void del(int d) override
    {
        root = delUtil(root, d);
    }
};

int main()
{
    BST bst;
    bst.insert(1);
    bst.insert(-2);
    bst.insert(3);
    bst.insert(-4);
    bst.insert(5);
    bst.inorder(cout << "Inorder: ");
    bst.del(1);
    bst.inorder(cout << "\nAfter deletion: ");

    return 0;
}