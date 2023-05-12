// Implemented by Kritagya Kumra
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isIdentical(node *root1, node *root2)
{
    // Time Complexity is O(n^2)
    // Time Complexity is O(height)
    if ((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
    {
        return false;
    }
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    bool leftAns = isIdentical(root1->left, root2->left);
    bool rightAns = isIdentical(root1->left, root2->left);
    bool mainCondition = root1->data == root2->data;

    if (leftAns && rightAns && mainCondition)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isIdenticalIterative(node *root1, node *root2)
{
    // Time Complexity :- O(n)
    // Time Complexity is O(height)
    queue<node *> q1;
    queue<node *> q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
        node *curr1 = q1.front();
        node *curr2 = q2.front();
        q1.pop();
        q2.pop();
        if (curr1->data != curr2->data)
        {
            return false;
        }
        if (curr1->left != NULL && curr2->left != NULL)
        {
            q1.push(curr1->left);
            q2.push(curr2->left);
        }
        if (curr1->right != NULL && curr2->right != NULL)
        {
            q1.push(curr1->right);
            q2.push(curr2->right);
        }
    }
    if (q1.size() == q2.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root1 = new node(10);
    root1->left = new node(8);
    root1->right = new node(2);
    root1->left->left = new node(3);
    root1->left->right = new node(5);
    root1->right->left = new node(2);
    root1->right->left->right = new node(12);
    root1->right->left->right->left = new node(11);

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    // bool ans = isBalanced(root);
    bool ans = isIdenticalIterative(root, root);
    if (ans == true)
    {
        cout << "Both Binary Tree are identical ";
    }
    else
    {
        cout << "Both Binary Tree are not identical ";
    }
}
// Implemented by Kritagya Kumra