// Implemented by Kritagya Kumra
#include <iostream>
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
};

void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Tail: " << tail->data << endl;
    cout << "Head: " << head->data << endl;
}

bool checkCircular(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    // Recursion part
    if (temp == head)
    {
        return true;
    }
    return false;
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocate 3 nodes in the heap
    first = new Node(1);
    second = new Node(2);
    third = new Node(3);
    first->next = second;
    second->next = third;
    third->next = NULL;
    head = first;
    tail = third;
    if (checkCircular(head))
    {
        cout << "The linked list is circular";
    }
    else
    {
        cout << "The linked list is not circular";
    }
    // Function call
    // print(head, tail);
}
// Implemented by Kritagya Kumra