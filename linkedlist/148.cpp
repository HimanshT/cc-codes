// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
// segmentation fault;
Node *ans(Node *head1, Node *head2)
{
    Node *ptr1, *ptr2;
    ptr1 = head1, ptr2 = head2;
    int carry = 0, sum = 0;
    while (ptr2 != NULL)
    {
        sum = ptr1->data + ptr2->data + carry;
        if (sum >= 10)
            carry = sum / 10;
        else
            carry = 0;
        ptr1->data = sum % 10;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    Node *pre = ptr1;
    while (ptr1 != NULL)
    {
        pre = ptr1;
        sum = ptr1->data + carry;
        if (sum >= 10)
            carry = sum / 10;
        else
            carry = 0;
        ptr1->data = sum % 10;
        ptr1 = ptr1->next;
    }
    if (carry > 0)
    {
        int val;
        Node *insert = new Node(val);
        val = carry;
        pre->next = insert;
        insert->next = NULL;
    }
    return head1;
}
int length(Node *head)
{
    int n = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        n++;
    }
    return n;
}
Node *reverse(Node *head)
{
    Node *pre, *cur, *front;
    pre = NULL, cur = head, front = NULL;
    while (cur != NULL)
    {
        front = cur->next;
        cur->next = pre;
        pre = cur;
        cur = front;
    }
    head = pre;
    return head;
}
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    Node *head1 = reverse(first);
    Node *head2 = reverse(second);
    int n1 = length(first);
    int n2 = length(second);
    if (n1 >= n2)
        return reverse(ans(head1, head2));
    else
        return reverse(ans(head2, head1));
}
// this was getting siggev fault