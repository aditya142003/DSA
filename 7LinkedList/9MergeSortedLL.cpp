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

void Merge(Node *&one, Node *&two)
{
    Node *curr1 = one;
    Node *next1 = curr1->next;
    Node *curr2 = two;
    Node *next2 = curr2->next;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data && next1->data > curr2->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return;
            }
        }
    }
    return;
}

int main()
{
    Node *one = NULL;
    Node *two = NULL;
    Insertion(one, 2);
    Insertion(one, 3);
    Insertion(one, 6);
    Insertion(one, 7);

    Insertion(two, 2);
    Insertion(two, 4);
    Insertion(two, 6);
    Insertion(two, 8);

    if ((one->data) <= (two->data))
    {
        Merge(one, two);
        print(one);
    }
    else
    {
        Merge(two, one);
        print(two);
    }
    return 0;
}