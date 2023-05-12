// Implemented by Kritagya Kumra
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next = 0;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
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
class Stack
{
    // properties
public:
    Node *top;

    // behaviour
    Stack()
    {
        top = NULL;
    }
    void push(int element)
    {
        // For empty list
        if (top == NULL)
        {
            Node *temp = new Node(element);
            top = temp;
        }
        else
        {
            // Create new node
            Node *temp = new Node(element);
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        Node *temp = top;
        top = top->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }

    int peek()
    {
        if (top != NULL)
        {
            int value = top->data;
            return value;
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    Stack st;

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is Empty mere dost " << endl;
    }
    else
    {
        cout << "Stack is not Empty mere dost " << endl;
    }

    st.display();
    /*
    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    */

    return 0;
}
// Implemented by Kritagya Kumra