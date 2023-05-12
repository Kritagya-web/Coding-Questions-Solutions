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

void insertAtHead(Node *&head, Node *&tail, int d)
{
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
}
void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{
}

void deleteElementByPosition(int position, Node *&head, Node *&tail)
{
}

void deleteElementByValue(Node *&head, int value)
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
    // Node *node1 = new Node(11);
    // // cout << node1->data << endl;
    // // cout << node1->next << endl;
    // Node *head = node1;
    // Node *tail = node1;
    // insertAtHead(head, tail, 10);
    // printElements(head, tail);
    // insertAtHead(head, tail, 2);
    // printElements(head, tail);
    // // insertAtHead(head, 12);
    // // printElements(head);
    // // cout << getLength(head);
    // insertAtTail(head, tail, 121);
    // printElements(head, tail);
    // // insertAtTail(tail, 15);
    // insertAtMiddle(head, tail, 1, 1);
    // printElements(head, tail);
    // insertAtMiddle(head, tail, 5, 13);
    // printElements(head, tail);
    // insertAtMiddle(head, tail, 7, 137);
    // printElements(head, tail);
    // // cout << "Tail: " << tail->data << endl;
    // // cout << "Head: " << head->data << endl;
    // deleteElementByPosition(1, head, tail);
    // printElements(head, tail);
    // deleteElementByPosition(4, head, tail);
    // printElements(head, tail);
    // deleteElementByPosition(5, head, tail);
    // printElements(head, tail);
    // // printElements(head, tail);
    // cout << tail->data << endl;
    // deleteElementByPosition(1, head);
    // deleteElementByPosition(2, head);
    // cout << tail->data << endl;
    // cout << head->data;
    // deleteElementByValue(head, 11);
    // printElements(head);
}
// Implemented by Kritagya Kumra