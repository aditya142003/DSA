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
        this->next = NULL;
        delete (this->next);
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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Duplicate(Node *&head)
{
    Node *curr = head;
    Node *prev = curr;
    Node *next = curr->next;
    while (curr != NULL)
    {
        while (next != NULL)
        {
            if (curr->data == next->data)
            {
                prev->next = next->next;
                delete (next);
                next = prev->next;
            }
            else
            {
                next = next->next;
                prev = prev->next;
            }
        }
        if (curr->next == NULL)
        {
            curr = curr->next;
            prev = curr;
        }
        else
        {
        curr = curr->next;
        prev = curr;
        next = curr->next;
        }
    }
    return;
}

int main()
{
    Node *head = NULL;
    Insertion(head, 3);
    Insertion(head, 3);
    Insertion(head, 2);
    Insertion(head, 5);
    Insertion(head, 5);
    Insertion(head, 0);
    Insertion(head, 2);
    Insertion(head, 4);
    Insertion(head, 3);
    Insertion(head, 4);
    Insertion(head, 2);
    Insertion(head, 1);
    Insertion(head, 6);
    Insertion(head, 5);
    cout << "Before Removal: ";
    print(head);
    cout << endl;
    Duplicate(head);
    cout << "After Removal: ";
    print(head);
    return 0;
}