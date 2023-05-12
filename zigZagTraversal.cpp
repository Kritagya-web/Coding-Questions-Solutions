// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
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
vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }

    queue<node *> q;
    q.push(root);
    // Here we would need a variable on the basis of whichwe would put
    // elements in left to right or right to left order
    bool leftToRight = true;
    while (!q.empty())
    {
        // Count the no of elements in the q to put them in zig zag order
        int size = q.size();
        vector<int> ans(size);

        // Process the elements and put the left and right child based on the l to r or r to l order
        for (int i = 0; i < size; i++)
        {
            node *frontNode = q.front();
            q.pop();
            // Calculate index based on the leftToRight variable
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
        for (auto i : ans)
        {
            result.push_back(i);
        }
        leftToRight = !leftToRight;
    }
    return result;
}
int main()
{
    node *root1 = new node(10);
    root1->left = new node(8);
    root1->right = new node(2);
    root1->left->left = new node(3);
    root1->left->right = new node(5);
    root1->right->left = new node(2);
    root1->right->left->right = new node(12);
    root1->right->left->right->left = new node(11);
    // node *root1 = new node(20);
    // root1->left = new node(8);
    // root1->right = new node(12);
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
    vector<int> ans = zigZagTraversal(root1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
// Implemented by Kritagya Kumra