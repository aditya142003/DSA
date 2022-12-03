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

Node *Middle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        else
        {
            return slow;
        }
    }
    cout << "Not Palindrome";
    return 0;
}

void IsPalindrome(Node *&head, Node *middle)
{
    Node *prev = middle->next;
    Node *curr = prev->next;
    Node *next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    middle->next->next = NULL;
    middle->next = prev;

    Node *first = head;
    Node *second = middle->next;
    int count = 0;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            count++;
        }
        first = first->next;
        second = second->next;
    }
    if (count == 0)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    prev = middle->next;
    curr = prev->next;
    next = curr->next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    middle->next->next = NULL;
    middle->next = prev;
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
    Insertion(head, 2);
    Insertion(head, 3);
    Insertion(head, 3);
    Insertion(head, 2);
    Insertion(head, 1);
    print(head);
    cout << endl;

    Node *middle = Middle(head);
    IsPalindrome(head, middle);
    return 0;
}