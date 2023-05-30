// Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *ptr1 = head, *ptr2 = head;
    if (head->next == NULL)
    {
        *head1_ref = head, *head2_ref = NULL;
        return;
    }
    while (ptr2->next != head and ptr2->next->next != head)
    {
        ptr1 = ptr1->next, ptr2 = ptr2->next->next;
    }

    Node *last = head;
    while (last->next != head) last = last->next;

    Node *head2 = ptr1->next; last->next = head2;
    Node *head1 = head; ptr1->next = head1;
    *head1_ref = head1, *head2_ref = head2;
    return;
}