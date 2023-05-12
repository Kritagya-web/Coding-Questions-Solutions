// Implemented by Kritagya Kumra
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = 0;
    Node *prev = 0;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int value = this->data;
        // Trying to free up the memory
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            this->prev = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int d)
{
    // For empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        // Create new node
        Node *temp = new Node(d);
        temp->next = head;
        // temp->prev = NULL;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    // For empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        // Create new node
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
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
        head->prev = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *previous = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            previous = curr;
            curr = curr->next;
            cnt++;
        }
        if (curr->next == NULL)
        {
            tail = tail->prev;
            previous->next = curr->next;
            curr->prev = NULL;
            delete curr;
        }
        else
        {
            previous->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }
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
void printElements(Node *&head, Node *&tail)
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
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int main()
{
    Node *node1 = new Node(11);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 10);
    printElements(head, tail);
    insertAtHead(head, tail, 2);
    printElements(head, tail);
    // insertAtHead(head, 12);
    // printElements(head);
    // cout << getLength(head);
    insertAtTail(head, tail, 121);
    printElements(head, tail);
    // insertAtTail(tail, 15);
    insertAtMiddle(head, tail, 1, 1);
    printElements(head, tail);
    insertAtMiddle(head, tail, 5, 13);
    printElements(head, tail);
    insertAtMiddle(head, tail, 7, 137);
    printElements(head, tail);
    // cout << "Tail: " << tail->data << endl;
    // cout << "Head: " << head->data << endl;
    deleteElementByPosition(1, head, tail);
    printElements(head, tail);
    deleteElementByPosition(4, head, tail);
    printElements(head, tail);
    deleteElementByPosition(5, head, tail);
    printElements(head, tail);
    // printElements(head, tail);
    // cout << tail->data << endl;
    // deleteElementByPosition(1, head);
    // deleteElementByPosition(2, head);
    // cout << tail->data << endl;
    // cout << head->data;
    // deleteElementByValue(head, 11);
    // printElements(head);
}
// Implemented by Kritagya Kumra