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
void solve(node *root, int sum, int &maxSum, int length, int maxLength)
{
    if (root == NULL)
    {
        if (length > maxLength)
        {
            maxLength = length;
            maxSum = sum;
        }
        else if (length == maxLength)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;
    solve(root->left, sum, maxSum, length + 1, maxLength);
    solve(root->right, sum, maxSum, length + 1, maxLength);
}
int sumOfLongRootToLeafPath(node *root)
{
    int sum = 0;
    int maxSum = INT16_MIN;
    int length = 0;
    int maxLength = 0;
    solve(root, sum, maxSum, length, maxLength);
    return maxSum;
}
pair<int, int> result(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = result(root->left);
    pair<int, int> right = result(root->right);

    pair<int, int> ans;
    ans.second = max(left.second, right.second) + 1;
    // int sum = left.first + right.first;
    if (left.second > right.second)
    {
        ans.first = left.first + root->data;
    }
    else if (left.second == right.second)
    {
        ans.first = max(left.first, right.first) + root->data;
    }
    else
    {
        ans.first = right.first + root->data;
    }
    return ans;
}
int sumOfLongRootToLeafPath1(node *root)
{
    return result(root).first;
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
    int ans = sumOfLongRootToLeafPath1(root);
    cout << "The sum Of Longest Root To Leaf Path is " << ans;
    return 0;
}
// Implemented by Kritagya Kumra