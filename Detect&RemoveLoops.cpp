// Implemented by Kritagya Kumra
/*************************************************

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
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
Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
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
    Node *final = removeLoop(head);
}
\ //Implemented by Kritagya Kumra