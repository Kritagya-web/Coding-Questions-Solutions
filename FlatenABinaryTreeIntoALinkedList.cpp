// Implemented by Kritagya Kumra
#include <iostream>
#include <queue>
#include <stack>
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
class LLNode
{
public:
    int data;
    LLNode *next = 0;

    LLNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~LLNode()
    {
        int value = this->data;
        // Trying to free up the memory
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void flattenAbinaaryTreeUsingMorrisAlgo(node *root)
{
    node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            current = current->right;
        }
        else
        {

            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            pre->right = current->right;
            current->right = current->left;
            current->left = NULL;
            current = current->right;
        }
    }
}
void inorderTraversalIterative(node *root)
{
    stack<node *> st;
    node *curr = root;
    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}
void printElements(LLNode *&head)
{
    LLNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
LLNode *solve(node *root, LLNode *&head, LLNode *&current)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (head == NULL)
    {
        head = new LLNode(root->data);
        current = head;
    }
    else
    {
        current->next = new LLNode(root->data);
        current = current->next;
    }
    solve(root->left, head, current);
    solve(root->right, head, current);
    return head;
}
void flatenABinaryTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    LLNode *head = NULL;
    LLNode *current = NULL;
    head = solve(root, head, current);
    printElements(head);
}
void preorderTraversal(node *root)
{
    // NLR
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main()
{
    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
    cout << "Preorder Traversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "Inorder Traversal using Morris Algo" << endl;
    flatenABinaryTree(root);
    return 0;
}
// Implemented by Kritagya Kumra