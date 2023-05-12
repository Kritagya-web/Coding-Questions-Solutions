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

bool isSumTree(node *root)
{
    // Time Complexity is O(n^2)
    // Time Complexity is O(height)

    if (root == NULL)
        return true;
    isSumTree(root->left);
    isSumTree(root->right);
    if (root->left == NULL && root->right == NULL)
        return true;
    int sum = 0;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;
    if (root->data != sum)
        return false;
    root->data += sum;
    return true;
}
pair<bool, int> isSumTreeFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> s = make_pair(true, 0);
        return s;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> s = make_pair(true, root->data);
        return s;
    }
    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool leftSide = left.first;
    bool rightSide = right.first;
    bool third = (left.second + right.second) == root->data;
    pair<bool, int> ans;

    if (leftSide && rightSide && third)
    {
        ans.first = true;
        ans.second = left.second + right.second + root->data;
    }
    else
    {
        ans.first = false;
        ans.second = left.second + right.second + root->data;
    }
    return ans;
}
bool isSumTree1(node *root)
{
    return isSumTreeFast(root).first;
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
    // node *root1 = new node(10);
    // root1->left = new node(8);
    // root1->right = new node(2);
    // root1->left->left = new node(3);
    // root1->left->right = new node(5);
    // root1->right->left = new node(2);
    // root1->right->left->right = new node(12);
    // root1->right->left->right->left = new node(11);
    node *root1 = new node(20);
    root1->left = new node(8);
    root1->right = new node(12);
    // root1->left->left = new node(3);
    // root1->left->right = new node(5);
    // root1->right->left = new node(2);
    // root1->right->right = new node(10);

    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    // bool ans = isBalanced(root);
    bool ans = isSumTree(root);
    if (ans == true)
    {
        cout << "Binary Tree is a Sum Tree ";
    }
    else
    {
        cout << "Binary Tree is not a Sum Tree ";
    }
}
// Implemented by Kritagya Kumra