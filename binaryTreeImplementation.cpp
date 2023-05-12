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
void levelOrderSimpleTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *frontNode = q.front();
        cout << frontNode->data << " ";
        q.pop();
        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }
        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }
    }
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    // Here null is used as a separator
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderSimpleTraversal(node *root)
{
    queue<node *> q;
    stack<node *> st;
    q.push(root);
    while (!q.empty())
    {
        node *frontNode = q.front();
        st.push(frontNode);
        q.pop();
        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }
        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }
    }
    while (!st.empty())
    {
        node *reverseNode = st.top();
        cout << reverseNode->data << " ";
        st.pop();
    }
}

void reverseLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> st;
    q.push(root);
    // Here null is used as a separator
    q.push(NULL);
    st.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
                st.push(NULL);
            }
        }
        else
        {
            // cout << temp->data << " ";
            st.push(temp);

            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }
    }
    while (!st.empty())
    {
        if (st.top() == NULL)
        {
            cout << endl;
            st.pop();
        }
        cout << st.top()->data << " ";
        st.pop();
    }
}
void inorderTraversal(node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
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
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(5);
    root->right->left = new node(2);
    cout << "Post Traversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "Post Traversal Iterative" << endl;
    postorderTraversalIterative(root);
    return 0;
}
// Implemented by Kritagya Kumra