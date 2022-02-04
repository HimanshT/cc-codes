// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

int getNthFromLast(Node *head, int n)
{
    Node *ptr = head;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    if (n > len)
        return -1;
    else
    {
        Node *ptr1 = head;
        for (int i = 1; i <= (len - n); i++)
            ptr1 = ptr1->next;
        return (ptr1->data);
    }
}