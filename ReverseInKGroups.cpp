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

Node *reverseInKGroups(Node *&head, int k)
{
    int count = 0;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // Recursion part
    if (next != NULL)
    {
        head->next = reverseInKGroups(next, k);
    }
    return prev;
}

// Using Recursion 1
Node *reverseInKGroups(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = reverseInKGroups(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
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
    reverseInKGroups(head);
    // Function call
    print(head, tail);
}
// Implemented by Kritagya Kumra