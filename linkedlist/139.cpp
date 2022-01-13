// Given pointer to the head node of a linked list,
// the task is to reverse the linked list.
//  We need to reverse the list by changing the links
//   between nodes.
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    struct node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void insertLast(struct node *head)
{
    int n;
    cout << "Enter the value to be inserted\n";
    cin >> n;
    struct node *ptr, *cur;
    ptr = (struct node *)malloc(sizeof(struct node));
    cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    ptr->data = n;
    ptr->next = cur->next;
    cur->next = ptr;
}

void reverse(struct node *head)
{
    struct node *pre, *cur, *front;
    pre = NULL, cur = head, front = NULL;
    while (cur != NULL)
    {
        front = cur->next;
        cur->next = pre;
        pre = cur;
        cur = front;
    }
    head = pre;
    display(head);
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;
    for (int i = 0; i < 3; i++)
        insertLast(head);
    display(head);
    reverse(head);
    return 0;
}