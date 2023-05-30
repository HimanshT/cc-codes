// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

int findl(Node* head)
{
    int ans = 0;
    while (head != NULL)
    {
        ans++, head = head->next;
    }
    return ans;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = findl(head1); int l2 = findl(head2);
    if (l1 > l2)
    {
        while (l1 > l2)
        {
            head1 = head1->next;
            l1--;
        }
    } else if (l2 > l1)
    {
        while (l2 > l1)
        {
            head2 = head2->next;
            l2--;
        }
    }

    while (head1 != NULL and head2 != NULL)
    {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next, head2 = head2->next;
    }
    return -1;
}