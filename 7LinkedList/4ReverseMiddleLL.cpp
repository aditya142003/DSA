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

void Reverse(Node *&head, Node *&curr, Node *&pre)
{
    if (curr == NULL)
    {
        head = pre;
        return;
    }
    head = curr->next;
    curr->next = pre;
    pre = curr;
    curr = head;
    Reverse(head, curr, pre);
    return;
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

int FromLast(Node *fast, Node *slow, int n, int count)
{
    while (fast->next != NULL)
    {
        fast = fast->next;
        count++;
        if (count > n)
        {
            slow = slow->next;
        }
    }
    return slow->data;
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

    int n;
    cout << "Enter number to find from last: ";
    cin >> n;
    Node *fast = head;
    Node *slow = head;
    int count = 1;
    cout << n << "th element from last is: " << FromLast(fast, slow, n, count) << endl;
    
    cout << "Before reverse: ";
    Print(head, tail);

    Node *pre = NULL;
    Node *curr = head;
    cout << "After reverse: ";
    Reverse(head, curr, pre);
    Print(head, tail);

    return 0;
}