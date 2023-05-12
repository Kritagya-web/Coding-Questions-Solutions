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
int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *middleOfLinkedList(Node *&head)
{
    int ans = getLength(head);
    int middle = ans / 2;
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < middle)
    {
        count++;
        temp = temp->next;
    }
    return temp;
}
Node *middleOfLinkedList2(Node *&head)
{
    Node *slow = head;
    Node *fast = slow->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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
    Node *answer = middleOfLinkedList(head);
    cout << answer->data << endl;
    // reverseLinkedList(head);
    // Function call
    print(head, tail);
}
// Implemented by Kritagya Kumra