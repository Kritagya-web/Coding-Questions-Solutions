// Implemented by Kritagya Kumra
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
bool solvevalidateBST(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return true;

    if (root->data > mini && root->data < maxi)
    {
        bool left = solvevalidateBST(root->left, mini, root->data);
        bool right = solvevalidateBST(root->right, root->data, maxi);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(Node *root)
{
    int maxi = INT_MAX;
    int mini = INT_MIN;
    return solvevalidateBST(root, mini, maxi);
}

void solve(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}

vector<int> inorderTraversal(Node *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}
bool is_sorted(vector<int> &ans)
{
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            return false;
            break;
        }
    }
    return true;
}
bool ValidBST(Node *root)
{
    vector<int> ans = inorderTraversal(root);
    if (is_sorted(ans))
    {
        return true;
    }
    else
    {
        return false;
    }
}
Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = insertIntoBST(root->left, d);
    }
    else
    {
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insertIntoBST(root, d);
        cin >> d;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create a BST" << endl;
    takeInput(root);
    cout << endl;
    cout << "Validate BST: " << ValidBST(root);
}
// Implemented by Kritagya Kumra