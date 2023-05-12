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

void insertANode(Node *&tail, int d, int value)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        Node *temp = tail->next;
        while (temp->data != value)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
        // tail = newNode;
    }
}

void deleteANode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "Cannot delete element from empty list" << endl;
        return;
    }
    else
    {
        Node *previous = tail;
        Node *curr = previous->next;
        while (curr->data != value)
        {
            previous = curr;
            curr = curr->next;
        }

        previous->next = curr->next;
        // 1 node linked list deletion process
        if (curr == previous)
        {
            tail = NULL;
        }
        else if (curr == tail)
        {
            tail = previous;
        }
        curr->next = NULL;
        delete curr;
        // Node *curr = tail;
        // Node *previous = NULL;
        // while (curr->data != value)
        // {
        //     previous = curr;
        //     curr = curr->next;
        // }
        // if (curr->data == tail->data)
        // {
        //     tail = curr->next;
        // }
        // previous->next = curr->next;
        // curr->next = NULL;
        // delete curr;
    }
}

void insertAtHead(Node *&tail, int d)
{
}
void insertAtTail(Node *&tail, int d)
{
}
void insertAtMiddle(Node *&tail, int position, int d)
{
}

void deleteElementByPosition(int position, Node *&tail)
{
}

void deleteElementByValue(Node *&tail, int value)
{
}
void printElements(Node *tail)
{
    // Node *temp = tail;
    // cout << temp->data << " ";
    // while (tail->next != temp)
    // {
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // }
    // cout << endl;
    // cout << "Tail: " << tail->data << endl;
    if (tail == NULL)
    {
        cout << "Cannot print elements of an empty list" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
    cout << "Tail: " << tail->data << endl;
    cout << endl;
}
// int getLength(Node *&tail)
// {
//     int length = 0;
//     Node *temp = tail->next;

//     while (temp->data == tail->next->data)
//     {
//         length++;
//         temp = temp->next;
//     }
//     return length;
// }

int main()
{
    // Node *node1 = new Node(11);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    Node *tail = NULL;
    insertANode(tail, 10, 11);
    printElements(tail);
    insertANode(tail, 11, 10);
    printElements(tail);
    insertANode(tail, 12, 11);
    printElements(tail);
    insertANode(tail, 13, 12);
    printElements(tail);
    deleteANode(tail, 11);
    printElements(tail);
    deleteANode(tail, 13);
    printElements(tail);
    deleteANode(tail, 10);
    printElements(tail);
    deleteANode(tail, 12);
    printElements(tail);
    // insertANode(tail, 9, 10);
    // printElements(tail);
    // insertAtHead(tail, 10);
    // printElements(tail);
    // insertAtHead(tail, 2);
    // printElements(tail);
    // insertAtHead( 12);
    // printElements(head);
    // cout << getLength(head);
    // insertAtTail(tail, 121);
    // printElements(tail);
    // // insertAtTail(tail, 15);
    // insertAtMiddle(tail, 1, 1);
    // printElements(tail);
    // insertAtMiddle(tail, 5, 13);
    // printElements(tail);
    // insertAtMiddle(tail, 7, 137);
    // printElements(tail);
    // cout << "Tail: " << tail->data << endl;
    // cout << "Head: " << head->data << endl;
    // deleteElementByPosition(1, tail);
    // printElements(tail);
    // deleteElementByPosition(4, tail);
    // printElements(tail);
    // deleteElementByPosition(5, tail);
    // printElements(tail);
    // // printElements( tail);
    // cout << tail->data << endl;
    // deleteElementByPosition(1, head);
    // deleteElementByPosition(2, head);
    // cout << tail->data << endl;
    // cout << head->data;
    // deleteElementByValue( 11);
    // printElements(head);
}
// Implemented by Kritagya Kumra