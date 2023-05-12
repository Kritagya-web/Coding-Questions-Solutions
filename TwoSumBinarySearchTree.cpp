// Implemented by Kritagya Kumra
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool search(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data < target)
    {
        return search(root->right, target);
    }
    else
    {
        return search(root->right, target);
    }
}
bool twoSumInBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (search(root, target - root->data) == true)
    {
        return true;
    }
    bool leftAns = twoSumInBST(root->left, target);
    bool rightAns = twoSumInBST(root->right, target);
    if (leftAns == true || rightAns == true)
    {
        return true;
    }
    return false;
}
Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = insertIntoBST(root->left, d);
    }
    else
    {
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insertIntoBST(root, d);
        cin >> d;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create a BST" << endl;
    takeInput(root);
    cout << endl;
    cout << "Two sum pair BST: " << twoSumInBST(root, 25);
}
// Implemented by Kritagya Kumra