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

void insertAtHead(Node *&head, int d)
{
    // For empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {
        // Create new node
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
void insertAtTail(Node *&tail, int d)
{
    // Create new node
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtMiddle(Node *&head, Node *&tail, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int count = 1;
    // Create new node

    Node *newNode = new Node(d);
    Node *temp = head;
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    while (temp != NULL)
    {
        if (count != (position - 1))
        {
            count++;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

void deleteElementByPosition(int position, Node *&head, Node *&tail)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// void deleteElementByPosition(Node *&head, int position)
// {
//     Node *temp = head;
//     if (position == 1)
//     {
//         head = head->next;
//         temp = temp->next;
//         delete temp;
//         return;
//     }
//     Node *element = head->next;
//     int count = 1;
//     while (count != position - 1)
//     {
//         temp = temp->next;
//         count++;
//         element = element->next;
//     }

//     temp->next = element->next;
// }
// void deleteElementByPosition(Node *&head, int position)
// {
//     Node *temp = head;

//     int count = 1;
//     while (count != position - 1)
//     {
//         temp = temp->next;
//         count++;
//     }

//     temp->next = (temp->next)->next;
// }
void deleteElementByValue(Node *&head, int value)
{
    Node *temp = head;

    Node *element = head->next;
    while (element->data != value)
    {
        temp = temp->next;
        element = element->next;
    }
    temp->next = element->next;
    delete temp;
    // temp->next = (temp->next)->next;
}
void printElements(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // Node *head = node1;
    // Node *tail = node1;
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, 11);
    // insertAtHead(head, 12);
    printElements(head);
    insertAtTail(tail, 11);
    insertAtTail(tail, 15);
    insertAtMiddle(head, tail, 12, 3);
    printElements(head);
    // deleteElementByPosition(head, 3);
    deleteElementByPosition(4, head, tail);
    // cout << tail->data << endl;
    // deleteElementByPosition(1, head);
    // deleteElementByPosition(2, head);
    // cout << tail->data << endl;
    // cout << head->data;
    // deleteElementByValue(head, 11);
    printElements(head);
}
// Implemented by Kritagya Kumra