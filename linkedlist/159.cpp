// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value x, without using any extra space?

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

void findPairs(Node *head, int sum)
{
    Node *ptr1, *ptr2;
    ptr1 = head, ptr2 = head;
    while (ptr2->next != NULL)
        ptr2 = ptr2->next;
    while (ptr1 != ptr2 && ptr2->next != ptr1)
    {
        int add = ptr1->data + ptr2->data;
        if (add == sum)
        {
            cout << "(" << ptr1->data << "," << ptr2->data << ")" << endl;
            ptr1 = ptr1->next;
        }
        else if (add < sum)
            ptr1 = ptr1->next;
        else
            ptr2 = ptr2->pre;
    }
}

int main()
{
    Node *head = new Node;
    head->data = 1;
    head->next = NULL, head->pre = NULL;
    insertlast(head, 2);
    insertlast(head, 4);
    insertlast(head, 5);
    insertlast(head, 6);
    insertlast(head, 8);
    insertlast(head, 9);
    findPairs(head, 10);
    return 0;
}