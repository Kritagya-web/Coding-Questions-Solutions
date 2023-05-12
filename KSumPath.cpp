// Implemented by Kritagya Kumra
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
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

void solvesumK(node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == k)
        count++;
    path.push_back(root->data);
    solvesumK(root->left, k, count, path);
    solvesumK(root->right, k, count, path);
    // Here in this case you will get here after you reach the leaf node
    // Check whether the sum is equal to k
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}
int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solvesumK(root, k, count, path);
    return count;
}
void solv(node *root, int k, int &count, int sum, unordered_map<int, int> &mp)
{
    if (root == NULL)
    {
        return;
    }
    sum = sum + root->data;
    count = count + mp[sum - k];
    if (sum == k)
        count++;
    cout << "sum -> " << sum << " and count -> " << count << endl;
    mp[sum]++;
    solv(root->left, k, count, sum, mp);
    solv(root->right, k, count, sum, mp);
    mp[sum]--;
}

int sumK1(node *root, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    solv(root, k, count, 0, mp);
    return count;
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
    root->left = new node(3);
    root->right = new node(-1);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->left->right->left = new node(1);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right->right = new node(6);
    int ans = sumK1(root, 5);
    cout << "The sum Of Longest Root To Leaf Path is " << ans;
    return 0;
}
// Implemented by Kritagya Kumra