#include <iostream>
#include "Node.h"
class Tree
{
protected:
    Node *root;

private:
    void preorderRec(Node *itr, std::ostream &stream)
    {
        if (itr == NULL)
            return;
        stream << itr->data << " ";
        preorderRec(itr->left, stream);
        preorderRec(itr->right, stream);
    }
    void inorderRec(Node *itr, std::ostream &stream)
    {
        if (itr == NULL)
            return;
        inorderRec(itr->left, stream);
        stream << itr->data << " ";
        inorderRec(itr->right, stream);
    }

public:
    Tree()
    {
        root = NULL;
    }
    virtual ~Tree()
    {
        //pending
    }
    virtual void insert(int) = 0;
    virtual void del(int) = 0;
    virtual void preorder(std::ostream &stream)
    {
        preorderRec(root, stream);
    }
    virtual void inorder(std::ostream &stream)
    {
        inorderRec(root, stream);
    }
};