// Implemented by Kritagya Kumra
//  C++ program to implement hash table approach
//  #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left, *right;
};

// Utility function to create a new node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to print the remaining path starting
// from index i
void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

// Utility function to print all the k-sum paths starting
// from a given node
void printKPathUtil(Node *root, vector<int> &path, unordered_map<int, int> &um, int k)
{
    // If the current node is NULL, return
    if (!root)
        return;

    // Add the current node's value to the path
    path.push_back(root->data);

    // Recursively traverse the left subtree
    printKPathUtil(root->left, path, um, k);

    // Recursively traverse the right subtree
    printKPathUtil(root->right, path, um, k);

    // Calculate the prefix sum of the path
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];

        // If the prefix sum equals k, print the path
        if (sum == k)
            printVector(path, i);

        // If there exists a prefix path that ends at a node
        // whose value is (sum - k), print the path
        auto itr = um.find(sum - k);
        if (itr != um.end())
        {
            cout << "Node" << endl;
            printVector(path, itr->second);
        }
    }

    // Remove the current node's value from the path
    path.pop_back();
}

// Utility function to print all the k-sum paths in the
// binary tree
void printKPath(Node *root, int k)
{
    vector<int> path;                  // to store the path
    unordered_map<int, int> um;        // to store the prefix sums
    printKPathUtil(root, path, um, k); // call the recursive utility function
}

// Driver code
int main()
{
    int k = 5;
    Node *root = newNode(1);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(1);
    root->left->right->left = newNode(1);
    root->right = newNode(-1);
    root->right->left = newNode(4);
    root->right->left->left = newNode(1);
    root->right->left->right = newNode(2);
    root->right->right = newNode(5);
    root->right->right->right = newNode(6);
    printKPath(root, k); // call the utility function to
                         // print all the k-sum paths
    return 0;
}
// Implemented by Kritagya Kumra