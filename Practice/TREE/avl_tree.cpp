#include <iostream>
#include "tree.h"

class AVL_tree : public Tree
{
private:
    Node *root;
    int getBalancedFactor(Node *ptr)
    {
    }

public:
    AVL_tree()
    {
        root = NULL;
    }
    void insert(int d) override
    {
    }
    void del(int d) override
    {
    }
};

int main()
{

    AVL_tree tree;
    tree.insert(21);
    tree.insert(26);
    tree.insert(30);
    tree.insert(9);

    return 0;
}