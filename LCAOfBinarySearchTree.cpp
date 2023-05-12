// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
using namespace std;
//    Following is the Binary Tree node structure

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode *LCAinaBST(BinaryTreeNode *root, BinaryTreeNode *P, BinaryTreeNode *Q)
{
    // if (root == NULL)
    //     return NULL;
    // if (root->data < P->data || root->data < Q->data)
    // {
    //     // Move to the right side
    //     return LCAinaBST(root->right, P, Q);
    // }
    // else if (root->data > P->data || root->data > Q->data)
    // {
    //     // Move to the left side
    //     return LCAinaBST(root->left, P, Q);
    // }
    // else
    // {
    //     // Move to the root
    //     return root;
    // }
    if (root == NULL)
        return NULL;
    while (root != NULL)
    {
        if (root->data < P->data && root->data < Q->data)
        {
            // Move to the right side
            root = root->right;
        }
        else if (root->data > P->data && root->data > Q->data)
        {
            // Move to the left side
            root = root->left;
        }
        else
        {
            // Move to the root
            return root;
        }
    }
}
int main()
{
    // node *root = NULL;
    // Creation of the tree
    // root = buildTree(root);
    // cout << "Level Order Traversal " << endl;
    // levelOrderTraversal(root);
    // cout << "Reverse Level Order Traversal " << endl;
    // reverseLevelOrderTraversal(root);
    // cout << "Inorder Traversal " << endl;
    // inorderTraversal(root);
    // cout << endl;
    // cout << "Preorder Traversal " << endl;
    // preorderTraversal(root);
    // cout << endl;
    // cout << "Postorder Traversal " << endl;
    // postorderTraversal(root);
    // cout << endl;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

    BinaryTreeNode *root = new BinaryTreeNode(10);
    root->left = new BinaryTreeNode(8);
    root->right = new BinaryTreeNode(20);
    root->left->left = new BinaryTreeNode(3);
    root->left->right = new BinaryTreeNode(9);
    root->right->left = new BinaryTreeNode(12);

    cout << "LCA of both th numbers is " << endl;
    cout << LCAinaBST(root, root->right->left, root->left->left)->data;
    return 0;
}
// Implemented by Kritagya Kumra