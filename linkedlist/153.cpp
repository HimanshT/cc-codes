// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

ListNode *middleNode(ListNode *head)
{
    ListNode *ptr1 = head;
    int n = 0;
    while (ptr1 != NULL)
    {
        n++;
        ptr1 = ptr1->next;
    }
    n = n / 2;
    ListNode *ptr = head;
    while (n--)
    {
        ptr = ptr->next;
    }
    return ptr;
}