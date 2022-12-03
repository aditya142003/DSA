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

Node *Reverse(Node *&head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    Node *first = NULL;
    Node *second = NULL;
    Node *sum = NULL;
    int value;
    Insertion(first, 1);
    Insertion(first, 2);
    Insertion(first, 3);

    Insertion(second, 1);
    Insertion(second, 2);
    Insertion(second, 3);
    Insertion(second, 3);
    cout << "First: ";
    print(first);
    cout << endl;
    cout << "second: ";
    print(second);
    cout << endl;
    first = Reverse(first);
    second = Reverse(second);

    int carry = 0;
    while (first != NULL && second != NULL)
    {
        value = first->data + second->data + carry;
        if (value < 10)
        {
            Insertion(sum, value);
        }
        else
        {
            Insertion(sum, value % 10);
            carry = value/10;
        }
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        value = first->data + carry;
        Insertion(sum, value);
        first = first->next;
    }
    while (second != NULL)
    {
        value = second->data + carry;
        Insertion(sum, value);
        second = second->next;
    }
    sum = Reverse(sum);
    cout<<"Sum: ";
    print(sum);
    return 0;
}