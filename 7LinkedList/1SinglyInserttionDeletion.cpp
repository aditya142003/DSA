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
        int value = this->data;
        if (next != NULL)
        {
            next = NULL;
        }
        delete this->next;
        cout << value << " has been deleted" << endl;
    }
};

void Insert(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        Node *add = new Node(data);
        add->next = head;
        head = add;
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        Node *add = new Node(data);
        add->next = temp->next;
        temp->next = add;
        tail = add;
        return;
    }
    Node *add = new Node(data);
    add->next = temp->next;
    temp->next = add;
}

void deletion(Node *&head, int pos, Node *&tail)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    Node *prev = head;
    int count = 1;
    while (count < pos)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    if (temp->next == NULL)
    {
        tail = prev;
        delete temp;
        return;
    }
    delete temp;
    return;
}

void print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " " << temp->next << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Insert(head, tail, 1, 1);
    Insert(head, tail, 2, 2);
    Insert(head, tail, 3, 3);
    Insert(head, tail, 4, 4);
    print(head, tail);
    cout << "Head: " << head->data << " " << endl
         << "Tail: "
         << tail->data << endl
         << endl;

    deletion(head, 1, tail);
    deletion(head, 3, tail);
    print(head, tail);
    cout << head->data << " " << tail->data << endl;
    return 0;
}