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

vector<int> topViewOfBinaryTree(node *root)
{
    // First int is for the hd and then we have map of level and vector of int
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        if (nodes.find(hd) == nodes.end())
        {
            nodes[hd][lvl].push_back(frontNode->data);
        }
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    // Fetch all the elements from the nodes and store it into the ans array
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
vector<int> topViewOfBinaryTree1(node *root)
{
    // First int is for the hd and then  second for the int value
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;
        if (nodes.find(hd) == nodes.end())
            nodes[hd] = frontNode->data;
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    // Fetch all the elements from the nodes and store it into the ans array
    for (auto i : nodes)
    {
        ans.push_back(i.second);
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
    vector<int> ans = topViewOfBinaryTree1(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// Implemented by Kritagya Kumra