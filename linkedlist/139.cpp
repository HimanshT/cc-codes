// Given pointer to the head node of a linked list,
// the task is to reverse the linked list.
//  We need to reverse the list by changing the links
//   between nodes.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    class Node* next;
};

Node* insert(Node* head, int value)
{
    if (head == NULL)
    {
        Node* ptr = new Node();
        ptr->data = value;
        ptr->next = NULL;
        return ptr;
    }

    Node *temp = new Node();
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverse(Node* head)
{
    Node *curr, *front, *back;
    back = NULL, curr = head;
    while (curr != NULL)
    {
        front = curr->next;
        curr->next = back;
        back = curr;
        curr = front;
    }
    return back;
}

int main()
{
    Node *head = NULL;
    for (int i = 0; i < 5; ++i)
    {
        head = insert(head, i);
    }

    display(head);
    head = reverse(head);
    display(head);
}