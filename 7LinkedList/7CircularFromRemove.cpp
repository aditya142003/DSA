#include <iostream>
#include <map>
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

void MakeCircular(Node *&head, int index)
{
    Node *temp = head;
    Node *from = NULL;
    int count = 1;
    while (count < index)
    {
        temp = temp->next;
        count++;
    }
    from = temp;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = from;
}

bool IsCircular(Node *&head)
{
    Node *temp = head;
    map<Node *, bool> validate;
    while (temp != NULL)
    {
        if (validate[temp] == false)
        {
            validate[temp] = true;
        }
        else
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int Starting(Node *&head)
{
    Node *fast = head;
    Node *slow = head;
    Node *temp = head;
    while (temp != NULL)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
        temp = temp->next;
        if (fast == slow)
        {
            break;
        }
    }
    slow = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

int main()
{
    Node *head = NULL;
    Insertion(head, 1);
    Insertion(head, 2);
    Insertion(head, 3);
    Insertion(head, 4);
    Insertion(head, 5);
    print(head);
    MakeCircular(head, 5);
    if (IsCircular(head))
    {
        cout << "Loop Starting from: " << Starting(head) << endl;
    }
    else
        cout << "Not Circular";
    return 0;
}