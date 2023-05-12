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

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorderTraversalUsingMorrisAlgo1(node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }
    node *curr = root;
    while (curr != NULL)
    {
        // If current->left is null then we would print current and then we would move to right
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        // If current->left is not null then we would find its predecesssor
        else
        {
            node *predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
                predecessor = predecessor->right;

            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
void inorderTraversalUsingMorrisAlgo(node *root)
{
    // LNR
    node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {

            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right
               child of predecessor */
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            } /* End of if condition pre->right == NULL */
        }     /* End of if condition current->left == NULL*/
    }         /* End of while */
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
void preorderTraversalIterative(node *root)
{
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        cout << temp->data << " ";

        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
}

void postorderTraversal(node *root)
{
    // LRN
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
void postorderTraversalIterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> final;
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        final.push(temp);
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
    }
    while (!final.empty())
    {
        cout << final.top()->data << " ";
        final.pop();
    }
}

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    // node *root = NULL;
    // Creation of the tree
    // root = buildTree(root);
    // cout << "Level Order Traversal " << endl;
    // levelOrderTraversal(root);
    // cout << "Reverse Level Order Traversal " << endl;
    // reverseLevelOrderTraversal(root);
    // cout << "Inorder Traversal " << endl;
    // inorderTraversal(root);
    // cout << endl;
    // cout << "Preorder Traversal " << endl;
    // preorderTraversal(root);
    // cout << endl;
    // cout << "Postorder Traversal " << endl;
    // postorderTraversal(root);
    // cout << endl;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);

    node *root = new node(10);
    root->left = new node(8);
    root->right = new node(20);
    root->left->left = new node(3);
    root->left->right = new node(9);
    root->right->left = new node(12);
    cout << "Inorder Traversal" << endl;
    inorderTraversalIterative(root);
    cout << endl;
    cout << "Inorder Traversal using Morris Algo" << endl;
    inorderTraversalUsingMorrisAlgo1(root);
    return 0;
}
// Implemented by Kritagya Kumra