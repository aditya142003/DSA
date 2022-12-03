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

void Insertion(Node *&head, int data, int element = 0)
{
    Node *temp = head;
    Node *add = new Node(data);
    if (head == NULL)
    {
        head = add;
        add->pre = add;
        add->next = add;
        return;
    }
    if (temp->next == temp)
    {
        add->next = temp->next;
        temp->next = add;
        add->pre = temp;
        temp->pre = add;
        return;
    }
    while (temp->data != element)
    {
        temp = temp->next;
    }
    add->next = temp->next;
    temp->next->pre = add;
    temp->next = add;
    add->pre = temp;
    return;
}

void Deletion(Node *&head, int element)
{
    Node *temp = head;
    if (head->data == element)
    {
        head = temp->next;
    }
    while (temp->data != element)
    {
        temp = temp->next;
    }
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    delete temp;
    return;
}

void print(Node *head)
{
    Node *temp = head;
    do
    {
        cout << "Add: " << temp << "  " << temp->data << " "
             << "Next: " << temp->next << "  Prev: " << temp->pre << endl;
        temp = temp->next;
    } while (head->next != temp->next);
}

int main()
{
    Node *head = NULL;
    Insertion(head, 1);
    Insertion(head, 2, 1);
    Insertion(head, 3, 2);
    Insertion(head, 4, 3);

    Deletion(head, 1);
    Deletion(head, 2);

    print(head);
    cout << "Head: " << head->data << endl;
    return 0;
}