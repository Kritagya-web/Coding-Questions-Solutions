// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
// void solve(node *root, vector<int> &ans, int endEle)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (root->data == endEle)
//     {
//         ans.push_back(root->data);
//         return;
//     }
//     ans.push_back(root->data);
//     solve(root->left, ans, endEle);
//     solve(root->right, ans, endEle);
// }
// vector<int> getLevelOrder(node *root, int endEle)
// {
//     vector<int> ans;
//     solve(root, ans, endEle);
//     return ans;
// }
// node *lca(node *root, int n1, int n2)
// {
//     vector<int> pathToN1 = getLevelOrder(root, n1);
//     vector<int> pathToN2 = getLevelOrder(root, n2);
//     for (int i = 0; i < pathToN1.size(); i++)
//     {
//         cout << pathToN1[i] << " ";
//     }
//     for (int i = 0; i < pathToN2.size(); i++)
//     {
//         cout << pathToN2[i] << " ";
//     }
//     return NULL;
// }
void traverse(node *root, int n1, vector<node *> &list1)
{
    if (root == NULL)
        return;
    list1.push_back(root);
    traverse(root->left, n1, list1);
    traverse(root->right, n1, list1);
    if (list1.back()->data != n1)
        list1.pop_back();
}

// Function to return the lowest common ancestor in a Binary Tree.

node *lca(node *root, int n1, int &k)

{
    if (root == NULL)
        return NULL;
    vector<node *> list1;
    traverse(root, n1, list1);
    while (k != 0)
    {
        list1.pop_back();
        k--;
    }
    return list1.back();
}
node *lca1(node *root, int n, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    cout << root->data << " " << k << endl;
    node *left = lca1(root->left, n, k);
    node *right = lca1(root->right, n, k);
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else
    {
        k--;
        if (left != NULL && right == NULL)
        {
            if (k <= 0)
            {
                k = INT16_MAX;
                return root;
            }
            return left;
        }
        else
        {
            if (k <= 0)
            {
                k = INT16_MAX;
                return root;
            }
            return right;
        }
    }
}
int kthAncestor(node *root, int k, int n)
{
    node *ans = lca(root, n, k);
    // node *ans = lca1(root, n, k);
    if (ans == NULL || ans->data == n)
        return -1;
    return ans->data;
}
int main()
{
    node *root1 = new node(10);
    root1->left = new node(8);
    root1->right = new node(2);
    root1->left->left = new node(3);
    root1->left->right = new node(5);
    root1->right->left = new node(22);
    root1->right->left->right = new node(12);
    root1->right->left->right->left = new node(11);
    // node *root1 = new node(20);
    // root1->left = new node(8);
    // root1->right = new node(12);
    // root1->left->left = new node(3);
    // root1->left->right = new node(5);
    // root1->right->left = new node(2);
    // root1->right->right = new node(10);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    int ans = kthAncestor(root, 2, 5);
    cout << "The sum Of Longest Root To Leaf Path is " << ans;
    return 0;
}
// Implemented by Kritagya Kumra