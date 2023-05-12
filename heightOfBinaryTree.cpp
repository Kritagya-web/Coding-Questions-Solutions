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
int height1(node *root)
{
    //     stack<node *> st;
    //     node *curr = root;
    //     int count = INT16_MIN;
    //     while (!st.empty() || curr != NULL)
    //     {
    //         int num = 0;
    //         if (curr != NULL)
    //         {
    //             st.push(curr);
    //             curr = curr->left;
    //             num++;
    //         }
    //         else
    //         {
    //             count = max(num, count);
    //             curr = st.top();
    //             st.pop();
    //             curr = curr->right;
    //         }
    //     }
    //     return count;
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
    int ans = height1(root);
    cout << "Height of the binary tree " << ans;
}
// Implemented by Kritagya Kumra