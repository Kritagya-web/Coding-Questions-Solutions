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

// void reverseLinkedList(Node *&head)
// {
//     Node *prev = NULL;
//     Node *curr = head;
//     while (curr != NULL)
//     {
//         Node *forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     head = prev;
// }

// Using Recursion 1
Node *reverse1(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

// Using Recursion 2
void solve(Node *&head, Node *&curr, Node *&prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    solve(head, forward, curr);
    curr->next = prev;
}
Node *reverseLinkedList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    solve(head, curr, prev);
    return head;
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
    reverseLinkedList(head);
    // Function call
    print(head, tail);
}
// Implemented by Kritagya Kumra