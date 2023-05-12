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
void traverse(node *root, int n1, int n2, vector<node *> &list1, vector<node *> &list2)
{
    if (root == NULL)
        return;
    list1.push_back(root);
    list2.push_back(root);
    traverse(root->left, n1, n2, list1, list2);
    traverse(root->right, n1, n2, list1, list2);
    if (list1.back()->data != n1)
        list1.pop_back();
    if (list2.back()->data != n2)
        list2.pop_back();
}

// Function to return the lowest common ancestor in a Binary Tree.

node *lca(node *root, int n1, int n2)

{
    if (root == NULL)
        return NULL;
    vector<node *> list1;
    vector<node *> list2;
    traverse(root, n1, n2, list1, list2);
    while (list1.back() != list2.back())
    {
        if (list1.size() > list2.size())
            list1.pop_back();
        else if (list1.size() < list2.size())
            list2.pop_back();
        else
        {
            list1.pop_back();
            list2.pop_back();
        }
    }
    return list1.back();
}
node *lca1(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *left = lca1(root->left, n1, n2);
    node *right = lca1(root->right, n1, n2);
    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else if (left != NULL && right == NULL)
    {
        return left;
    }
    else if (right != NULL && left != NULL)
    {
        return root;
    }
    else
    {
        return right;
    }
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
    node *ans = lca(root, 4, 5);
    cout << "The sum Of Longest Root To Leaf Path is " << ans->data;
    return 0;
}
// Implemented by Kritagya Kumra