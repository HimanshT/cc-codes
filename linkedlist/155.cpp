// Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *middle, *last, *after;
    middle = head, last = head, after = head->next->next;
    while (after != head)
    {
        middle = middle->next;
        if (after->next == head)
            break;
        after = after->next->next;
    }
    while (last->next != head)
    {
        last = last->next;
    }
    *head2_ref = middle->next;
    last->next = *head2_ref;
    *head1_ref = head;
    middle->next = *head1_ref;
}