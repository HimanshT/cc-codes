// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

int length(Node *head)
{
    Node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
int inter(Node *head1, Node *head2, int l)
{
    Node *temp1 = head1;
    while (l--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;
}
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int l1 = length(head1);
    int l2 = length(head2);
    if (l1 > l2)
    {
        return inter(head1, head2, abs(l1 - l2));
    }
    else
    {
        return inter(head2, head1, abs(l1 - l2));
    }
}