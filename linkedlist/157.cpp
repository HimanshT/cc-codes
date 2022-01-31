// We will be given a node and our task is to delete that node from the circular linked list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
// 2->5->7->8

void insertAtFront(Node *head, int value)
{
    Node *element = new Node;
    element->data = value;
    Node *ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = element;
    element->next = head;
}

Node *deleteNode(Node *head, int value)
{
    Node *back, *cur;
    if (value == head->data)
    {
        cur = head;
        back = head;
        while (back->next != head)
            back = back->next;
        head = head->next;
        back->next = head;
        free(cur);
    }
    else
    {
        back = head, cur = head->next;
        while (cur->next != head)
        {
            if (cur->data == value)
            {
                back->next = cur->next;
                free(cur);
                break;
            }
            back = back->next;
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node;
    head->data = 2;
    head->next = head;
    insertAtFront(head, 5);
    insertAtFront(head, 8);
    insertAtFront(head, 7);
    head = deleteNode(head, 5);
    Node *ptr = head;
    while (ptr->next != head)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
    return 0;
}
