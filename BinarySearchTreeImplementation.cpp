// Implemented by Kritagya Kumra
#include <iostream>
#include <stack>
#include <queue>
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
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // Here null is used as a separator
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
void reverseLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    // Here null is used as a separator
    q.push(NULL);
    st.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
void inorderTraversal(Node *root)
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
void inorderTraversalIterative(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
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
void preorderTraversal(Node *root)
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
void preorderTraversalIterative(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
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

void postorderTraversal(Node *root)
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
void postorderTraversalIterative(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> final;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *temp = st.top();
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
// int returnMaxValue(Node* root){
//     Node* temp = root;
//     while(temp->left!=NULL){
//         temp = temp->left;
//     }
//     return temp->data;
// }
// int returnMinValue(Node* root){
//     Node* temp = root;
//     while(temp->right!=NULL){
//         temp = temp->right;
//     }
//     return temp->data;
// }
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
vector<int> inorderTraversalnew(Node *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}
// int inorderPredecessor(Node* root, int element){
//     vector<int> ans = inorderTraversalnew(root);
//     for(int i =0;i<ans.size();i++)
//     {
//         if(ans[i] == element)
//         {
//             return ans[i+1];
//             break;
//         }

//     }
// }
Node *returnMaxValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *returnMinValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
Node *inOrderSuccessor(Node *root, Node *element)
{
    // Step 1 of the above algorithm
    if (element->right != NULL)
    {
        return returnMinValue(element->right);
    }
    Node *successor = NULL;
    // Start from root and search for
    // successor down the tree
    while (root->data != element->data)
    {
        if (root->data > element->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return successor;
}
Node *inOrderPredecessor(Node *root, Node *element)
{
    // Step 1 of the above algorithm
    if (element->left != NULL)
    {
        return returnMaxValue(element->left);
    }
    Node *predecessor = NULL;
    // Start from root and search for
    // successor down the tree
    while (root->data != element->data)
    {
        if (root->data > element->data)
        {
            root = root->left;
        }
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}
Node *deleteFromBST(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == value)
    {
        // For Zero child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // For One child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // For Two child
        if (root->left != NULL && root->right != NULL)
        {
            // int maxi = returnMaxValue(root->left)->data;
            int mini = returnMinValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    if (root->data > value)
    {
        root->left = deleteFromBST(root->left, value);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, value);
        return root;
    }
}
int main()
{
    Node *root = NULL;
    cout << "Enter data to create a BST" << endl;
    takeInput(root);
    cout << "Printing the BST using Level order Traversal" << endl;
    levelOrderTraversal(root);
    cout << "Printing the Preorder Traversal" << endl;
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "Printing the Preorder Traversal Iterative" << endl;
    preorderTraversalIterative(root);
    cout << endl;
    cout << "Printing the Inorder Traversal" << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Printing the Inorder Traversal Iterative" << endl;
    inorderTraversalIterative(root);
    cout << endl;
    cout << "Printing the Postorder Traversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "Printing the Postorder Traversal Iterative" << endl;
    preorderTraversalIterative(root);
    cout << endl;
    cout << "Printing the maximum element from the BST " << returnMaxValue(root)->data;
    cout << endl;
    cout << "Printing the minimum element from the BST " << returnMinValue(root)->data;
    cout << endl;
    // cout << "Inorder Predecessor of "
    //      << "45 is " << inOrderPredecessor(root, 45);
    // cout << endl;
    // cout << "Inorder Successor of"
    //      << "45 is " << inOrderSuccessor(root, 45);
    // cout << endl;
    cout << deleteFromBST(root, 30);
    cout << endl;
    cout << "Printing the Postorder Traversal Iterative" << endl;
    preorderTraversalIterative(root);
    cout << endl;
}
// Implemented by Kritagya Kumra