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

void Insertion(Node *&head, Node *&tail, int data)
{
    Node *add = new Node(data);
    if (head == NULL)
    {
        head = add;
        tail = add;
        return;
    }
    add->next = tail->next;
    tail->next = add;
    tail = add;
}

Node *Reverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *forward = NULL;
    Node *curr = head;
    Node *pre = NULL;
    int count = 0;
    while (count < k && curr != NULL)
    {
        forward = curr->next;
        curr->next = pre;
        pre = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        head->next = Reverse(forward, k);
    }
    return pre;
}

void Print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Insertion(head, tail, 1);
    Insertion(head, tail, 2);
    Insertion(head, tail, 3);
    Insertion(head, tail, 4);
    Insertion(head, tail, 5);
    Insertion(head, tail, 6);
    Insertion(head, tail, 7);
    Insertion(head, tail, 8);
    Print(head, tail);
    int k;
    cout << "Enter number of elements in a group: ";
    cin >> k;

    head = Reverse(head, k);
    cout << "After reverse in K groups: ";
    Print(head, tail);

    return 0;
}