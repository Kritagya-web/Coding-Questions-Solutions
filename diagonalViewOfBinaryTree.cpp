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

vector<int> diagonalViewOfBinaryTree(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp)
        {
            ans.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }

    return ans;
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
    // bool ans = isBalanced(root);
    vector<int> ans = diagonalViewOfBinaryTree(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// Implemented by Kritagya Kumra