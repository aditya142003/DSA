#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        delete this->next;
    }
};

void Insertion(Node *&head, int data)
{

    Node *add = new Node(data);
    Node *temp = head;
    if (head == NULL)
    {
        head = add;
        add->next = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    add->next = temp->next;
    temp->next = add;
}

void InsertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

void Sort(Node *&curr, Node *&zerotail, Node *&onetail, Node *&twotail)
{
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            InsertAtTail(zerotail, curr);
        }
        else if (curr->data == 1)
        {
            InsertAtTail(onetail, curr);
        }
        else if (curr->data == 2)
        {
            InsertAtTail(twotail, curr);
        }
        else
        {
            cout << "Invalid data" << endl;
        }
        curr = curr->next;
    }
    return;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Insertion(head, 1);
    Insertion(head, 0);
    Insertion(head, 1);
    Insertion(head, 2);
    Insertion(head, 0);
    Insertion(head, 2);
    print(head);
    cout << endl;

    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;
    Node *onehead = new Node(-1);
    Node *onetail = onehead;
    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;
    Sort(curr, zerotail, onetail, twotail);

    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next = NULL;
    head = zerohead->next;
    delete (zerohead);
    delete (onehead);
    delete (twohead);
    print(head);
    return 0;
}