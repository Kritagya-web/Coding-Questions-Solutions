// Implemented by Kritagya Kumra
//{ Driver Code Starts
//  #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    /*You are required to complete this method*/
    void sizeOfTheLeafNode(Node *root, int &size, int &maxSize)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            maxSize = size;
            return;
        }
        size = size + 1;
        sizeOfTheLeafNode(root->left, size, maxSize);
        sizeOfTheLeafNode(root->right, size, maxSize);
    }
    bool solve(Node *root, int &size, int &maxSize)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (maxSize == size)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        size = size + 1;
        bool left = solve(root->left, size, maxSize);
        bool right = solve(root->right, size, maxSize);

        return left && right;
    }
    bool check(Node *root)
    {
        int size = 0;
        int maxSize = 0;
        sizeOfTheLeafNode(root, size, maxSize);
        return solve(root, size, maxSize);
    }
};

//{ Driver Code Starts.
// Driver program to test size function
int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *head = buildTree(s);
        Solution obj;
        cout << obj.check(head) << endl;
    }
    return 0;
}

// } Driver Code Ends
// Implemented by Kritagya Kumra