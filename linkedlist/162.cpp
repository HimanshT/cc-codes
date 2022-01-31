// Given a doubly-linked list, rotate the linked list counter-clockwise by N nodes. Here N is a given positive integer and is smaller than the count of nodes in linked list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;
};

void insertlast(Node *head, int value)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *element = new Node;
    element->data = value;
    element->next = NULL;
    ptr->next = element;
    element->pre = ptr;
}

// 1 2 3 4 5 6 7 ,k=2
// 3 4 5 6 7 1 2
Node *ans(Node *head, int k)
{
    Node *iter, *end, *first;
    iter = head, end = head, first = head;
    while (end->next != NULL)
        end = end->next;
    for (int i = 1; i < k; i++)
        iter = iter->next;
    end->next = first;
    first->pre = end;
    head = iter->next;
    iter->next = NULL;
    head->pre = NULL;
    return head;
}

int main()
{
    Node *head = new Node;
    head->data = 1;
    head->next = NULL, head->pre = NULL;
    insertlast(head, 2);
    insertlast(head, 3);
    insertlast(head, 4);
    insertlast(head, 5);
    insertlast(head, 6);
    insertlast(head, 7);
    head = ans(head, 2);
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return 0;
}