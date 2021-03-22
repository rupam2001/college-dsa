class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
