// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group
// and must be reversed

class Solution
{
public:
    struct node *reverse (struct node *head, int k)
    {
        if (head == NULL)
            return NULL;
        int count = 1;
        struct node *ptr = head;
        while (count <= k and ptr != NULL)
        {
            ptr = ptr->next, count++;
        }
        struct node *prev;
        if (ptr == NULL)
            prev = NULL;
        else
            prev = reverse(ptr, k);
        struct node *curr, *front;
        curr = head, front = NULL;
        count = 0;
        while (count < k and curr != NULL)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            count++;
        }
        return prev;
    }
};
