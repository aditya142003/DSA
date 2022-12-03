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
    Node *next = curr->next;
    while (next != NULL)
    {
        if (curr->data != next->data)
        {
            curr = next;
            next = next->next;
        }
        else
        {
            if (next->next == NULL)
            {
                curr->next = next->next;
                delete (next);
                return;
            }
            while (next->data == next->next->data)
            {
                next = next->next;
                if (next->next == NULL)
                {
                    curr->next = next->next;
                    delete (next);
                    return;
                }
            }
            curr->next = next->next;
            curr = next->next;
            delete (next);
            next = curr->next;
        }
    }
    return;
}

int main()
{
    Node *head = NULL;
    Insertion(head, 0);
    Insertion(head, 1);
    Insertion(head, 1);
    Insertion(head, 2);
    Insertion(head, 2);
    Insertion(head, 2);
    Insertion(head, 3);
    Insertion(head, 4);
    Insertion(head, 4);
    Insertion(head, 5);
    Insertion(head, 5);
    Insertion(head, 5);
    Insertion(head, 5);
    Insertion(head, 5);
    Insertion(head, 6);
    cout << "Before Removal: ";
    print(head);
    cout << endl;
    Duplicate(head);
    cout << "After Removal: ";
    print(head);
    return 0;
}