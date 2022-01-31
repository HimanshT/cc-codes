// Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Node *reverseDLL(Node *head)
{
    Node *cur, *before, *after;
    cur = head, before = NULL, after = NULL;
    while (cur != NULL)
    {
        after = cur->next;
        cur->next = before;
        cur->prev = after;
        before = cur;
        cur = after;
    }
    return before;
}