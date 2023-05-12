// Implemented by Kritagya Kumra
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
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
node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to print Inorder traversal
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

// mirrorify function takes two trees,
// original tree and a mirror tree
// It recurses on both the trees,
// but when original tree recurses on left,
// mirror tree recurses on right and
// vice-versa
void mirrorify(node *root, node **mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }
    *mirror = createNode(root->data);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}
// Approach 2 : by swapping the left and right subtree element of the node

node *mirrorify2(node *root)
{
    if (root == NULL)
    {
        return root;
    }
    node *mirror = root->left;
    root->left = root->right;
    root->right = mirror;
    if (root->left)
    {
        mirrorify2(root->left);
    }
    else if (root->right)
    {
        mirrorify2(root->right);
    }
    return root;
}

// Driver code
int main()
{

    node *tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    // Print inorder traversal of the input tree
    cout << "Inorder of original tree: ";
    inorder(tree);
    node *mirror = NULL;
    // mirrorify(tree, &mirror);
    mirrorify2(tree);

    // Print inorder traversal of the mirror tree
    cout << "\nInorder of mirror tree: ";
    inorder(tree);

    return 0;
}
// Implemented by Kritagya Kumra