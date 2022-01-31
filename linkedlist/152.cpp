// Sort the given Linked List using quicksort.
// which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

void quickSort(struct node **headRef)
{
    int n = 0;
    struct node *ptr = *headRef;
    while (ptr != NULL)
    {
        n++;
        ptr = ptr->next;
    }
    struct node *pre, *cur, *front;
    pre = *headRef, cur = NULL, front = NULL;
    for (int i = 1; i < n; i++)
    {
        cur = pre;
        for (int j = i; j < n; j++)
        {
            front = cur->next;
            if (cur->data > front->data)
            {
                int swap;
                swap = cur->data;
                cur->data = front->data;
                front->data = swap;
            }
            cur = front;
        }
    }
}