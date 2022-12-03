#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->pre = NULL;
    }
    ~Node()
    {
        int value = this->data;
        this->next = NULL;
        this->pre = NULL;
        delete next;
        cout << value << " has been deleted" << endl;
    }
};

void Insertion(Node *&head, int pos, int data)
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
        add->pre = temp;
        return;
    }

    Node *add = new Node(data);
    add->next = temp->next;
    temp->next->pre = add;
    temp->next = add;
    add->pre = temp;
}

void Deletion(Node *&head, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next->pre = temp->pre;
        delete temp;
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    delete temp;
    return;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Add: " << temp << "  " << temp->data << " "
             << "Next: " << temp->next << "  Prev: " << temp->pre << endl;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    Insertion(head, 1, 1);
    Insertion(head, 2, 5);
    Insertion(head, 2, 7);
    Insertion(head, 4, 6);
    cout << "Head: " << head->data << endl;
    print(head);

    Deletion(head, 1);

    print(head);
    cout << "Head: " << head->data << endl;
    return 0;
}