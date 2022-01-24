// Remove duplicates from an unsorted linked list
Node *removeDuplicates(Node *head)
{
    int arr[10001] = {0};
    Node *cur, *prev, *ptr;
    prev = head;
    arr[prev->data]++;
    cur = prev->next;
    while (cur != NULL)
    {
        if (arr[cur->data] >= 1)
        {
            prev->next = cur->next;
            ptr = cur;
            cur = cur->next;
            free(ptr);
        }
        else
        {
            arr[cur->data]++;
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
