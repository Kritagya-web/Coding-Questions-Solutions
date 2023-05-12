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

Node *divideIntoTwoCircularLists(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int ans = 1;
    temp = head->next;
    Node *head1 = new Node(head->data);
    Node *head2 = NULL;
    while (temp != NULL && ans < (count / 2))
    {
        ans++;
        Node *newNode = new Node(temp->data);
        head1->next = newNode;
        temp = temp->next;
    }
    while (temp != NULL && ans < count)
    {
        ans++;
        Node *newNode = new Node(temp->data);
        if (head2 == NULL)
        {
            head2 = newNode;
            temp = temp->next;
        }
        else
        {
            head2->next = newNode;
            temp = temp->next;
        }
    }
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
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *sixth = NULL;

    // allocate 3 nodes in the heap
    first = new Node(1);
    second = new Node(2);
    third = new Node(3);
    fourth = new Node(4);
    fifth = new Node(5);
    sixth = new Node(6);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = first;
    head = first;
    if (checkCircular(head))
    {
        cout << "The linked list is circular";
    }
    else
    {
        cout << "The linked list is not circular";
    }
}
// Implemented by Kritagya Kumra