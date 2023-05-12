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
int diameter(node *root)
{
    // Time Complexity is O(n^2)
    // Time Complexity is O(height)
    if (root == NULL)
    {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = height(root->left) + height(root->right) + 1;

    int ans = max(option1, max(option2, option3));
    return ans;
}
pair<int, int> diameterFast(node *root)
{
    // Here in the pair first is for the diamter and second is for the height
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftAns = diameterFast(root->left);
    pair<int, int> rightAns = diameterFast(root->right);
    int option1 = leftAns.first;
    int option2 = rightAns.first;
    int option3 = leftAns.second + rightAns.second + 1;
    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3));
    ans.second = max(leftAns.second, rightAns.second) + 1;
    return ans;
}
int diameter1(node *root)
{
    // Time Complexity :- O(n)
    return diameterFast(root).first;
}
int diameterIterative(node *root)
{
    // Time Complexity :- O(n)

    // Time Complexity is O(n^2)
    // Time Complexity is O(height)
    if (root == NULL)
    {
        return 0;
    }
    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = heightIterative(root->left) + heightIterative(root->right) + 1;

    int ans = max(option1, max(option2, option3));
    return ans;
}
int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
    root->right->left->right = new node(12);
    root->right->left->right->left = new node(11);
    int ans = diameterIterative(root);
    cout << "Diameter of the binary tree " << ans;
}
// Implemented by Kritagya Kumra