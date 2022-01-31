// Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.

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

// bubble sort without using k--can be implemented same as singly linked list
void sortK(Node *head, int k)
{
    Node *iter = head;
    while (iter->next != NULL)
    {
        int min = iter->data;
        Node *hold, *ptr;
        ptr = iter->next;
        for (int i = 1; i <= k; i++)
        {
            if (ptr == NULL)
                break;
            if (ptr->data < min)
            {
                min = ptr->data;
                hold = ptr;
            }
            ptr = ptr->next;
        }
        // swapping process
        if (iter->data > min)
        {
            int swap;
            swap = iter->data;
            iter->data = hold->data;
            hold->data = swap;
        }
        iter = iter->next;
    }
}

int main()
{
    Node *head = new Node;
    head->data = 3;
    head->next = NULL, head->pre = NULL;
    insertlast(head, 6);
    insertlast(head, 2);
    insertlast(head, 12);
    insertlast(head, 56);
    insertlast(head, 8);
    sortK(head, 2);
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    return 0;
}