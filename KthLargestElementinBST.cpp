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
// void preorderTraversal(BinaryTreeNode *root, int &size)
// {
//     // NLR
//     if (root == NULL)
//     {
//         return;
//     }
//     size++;
//     preorderTraversal(root->left, size);
//     preorderTraversal(root->right, size);
// }
// int inorderTraversal1(BinaryTreeNode *root, int k, int &count, int size)
// {
//     // LNR
//     if (root == NULL)
//     {
//         return -1;
//     }
//     int left = inorderTraversal1(root->left, k, count, size);

//     if (left != -1)
//         return left;
//     count++;
//     if (count == size - k + 1)
//         return root->data;
//     return inorderTraversal1(root->right, k, count, size);
// }

// int kthLargest1(BinaryTreeNode *root, int k)
// {
//     int count = 0;
//     int size = 0;
//     preorderTraversal(root, size);
//     return inorderTraversal1(root, k, count, size);
// }

// int inorderTraversalMorrisAlgo(BinaryTreeNode *root, int k, int count)
// {
//     // LNR
//     if (root == NULL)
//     {
//         return -1;
//     }
//     BinaryTreeNode *curr = root;
//     while (curr != NULL)
//     {
//         // If current->left is null then we would print current and then we would move to right
//         if (curr->left == NULL)
//         {
//             // cout << curr->data << " ";
//             count++;
//             if (count == k)
//             {
//                 return curr->data;
//             }
//             curr = curr->right;
//         }
//         // If current->left is not null then we would find its predecesssor
//         else
//         {
//             BinaryTreeNode *predecessor = curr->left;
//             while (predecessor->right != NULL && predecessor->right != curr)
//                 predecessor = predecessor->right;

//             if (predecessor->right == NULL)
//             {
//                 predecessor->right = curr;
//                 curr = curr->left;
//             }
//             else
//             {
//                 predecessor->right = NULL;
//                 // cout << curr->data << " ";
//                 count++;
//                 if (count == k)
//                 {
//                     return curr->data;
//                 }
//                 curr = curr->right;
//             }
//         }
//     }
//     if (count < k)
//     {
//         return -1;
//     }
// }

// int kthLargest(BinaryTreeNode *root, int k)
// {
//     int count = 0;
//     return inorderTraversalMorrisAlgo(root, k, count);
// }
void inorderTraversal(BinaryTreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
int kthLargestNew(BinaryTreeNode *root, int k)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int size = ans.size();
    int res = ans[size - k];
    return res;
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

    cout << "Kth Largest element  using Morris Algo" << endl;
    cout << kthLargestNew(root, 3);
    return 0;
}
// Implemented by Kritagya Kumra