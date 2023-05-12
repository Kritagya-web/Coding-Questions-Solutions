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

void solve(node *root, int &includeSum, int &excludeSum, bool connected)
{
    if (root == NULL)
        return;
    if (connected == false)
        includeSum += root->data;
    else
        excludeSum += root->data;
    solve(root->left, includeSum, excludeSum, !connected);
    solve(root->right, includeSum, excludeSum, !connected);
}
int getMaxSum(node *root)
{
    int includeSum = 0;
    int excludeSum = 0;
    bool connected = false;
    solve(root, includeSum, excludeSum, connected);
    return max(includeSum, excludeSum);
}
pair<int, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    // LeftAns is for the element including the first element
    // rightAns is for the element excluding the first element
    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);
    // ans.first is for the element including the first element
    // ans.second is for the element excluding the first element
    pair<int, int> ans;
    ans.first = leftAns.second + rightAns.second + root->data;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    return ans;
}
int getMaxSum1(node *root)
{
    pair<int, int> result = solve(root);
    return max(result.first, result.second);
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
    int ans = getMaxSum1(root);
    cout << "The maximum sum Of Non-Adjecent Nodes is " << ans;
    return 0;
}
// Implemented by Kritagya Kumra