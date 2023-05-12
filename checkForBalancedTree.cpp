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
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // For the left half of the tree
    int h1 = height(root->left);
    // For the right half of the tree
    int h2 = height(root->right);
    // Find the max of both and add 1 for the root node
    int ans = max(h1, h2) + 1;
    return ans;
}
int heightIterative(node *root)
{
    int height = 0;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            height++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return height;
}
bool isBalanced(node *root)
{
    // Time Complexity is O(n^2)
    // Time Complexity is O(height)
    if (root == NULL)
    {
        return true;
    }
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    bool difference = abs(height(root->left) - height(root->right)) <= 1;
    if (leftAns && rightAns && difference)
    {
        return true;
    }
    else
    {
        return false;
    }
}
pair<bool, int> isBalancedFast(node *root)
{
    // Here in the pair first is for checking the difference condition
    // and second is for the height
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> leftAns = isBalancedFast(root->left);
    pair<bool, int> rightAns = isBalancedFast(root->right);

    bool option1 = leftAns.first;
    bool option2 = rightAns.first;
    bool difference = abs(leftAns.second - rightAns.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    if (option1 && option2 && difference)
    {
        ans.first = true;
    }
    else
    {
        ans.second = false;
    }
    return ans;
}
bool isBalanced1(node *root)
{
    // Time Complexity :- O(n)
    return isBalancedFast(root).first;
}
bool isBalancedIterative(node *root)
{
    // Time Complexity :- O(n)

    // Time Complexity is O(n^2)
    // Time Complexity is O(height)
    if (root == NULL)
    {
        return true;
    }
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    bool difference = abs(heightIterative(root->left) - heightIterative(root->right)) <= 1;
    if (leftAns && rightAns && difference)
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
    // node *root = new node(10);
    // root->left = new node(8);
    // root->right = new node(2);
    // root->left->left = new node(3);
    // root->left->right = new node(5);
    // root->right->left = new node(2);
    // root->right->left->right = new node(12);
    // root->right->left->right->left = new node(11);
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(60);
    // bool ans = isBalanced(root);
    bool ans = isBalanced1(root);
    if (ans == true)
    {
        cout << "Binary Tree is balanced ";
    }
    else
    {
        cout << "Binary Tree is not balanced ";
    }
}
// Implemented by Kritagya Kumra