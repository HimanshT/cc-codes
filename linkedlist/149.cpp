// Intersection of two sorted Linked lists
Node *insertAtLast(Node *head, int value)
{
    if (head == NULL)
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr->data = value;
        ptr->next = NULL;
        head = ptr;
        return head;
    }

    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    ptr->next = node;
    return head;
}

Node *findIntersection(Node *head1, Node *head2)
{
    Node *ptr1 = head1, *ptr2 = head2;
    Node *head = NULL;
    int arr[100001] = {0};
    while (ptr1 != NULL)
    {
        arr[ptr1->data]++;
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        if (arr[ptr2->data] > 0)
        {
            arr[ptr2->data] = 0;
            head = insertAtLast(head, ptr2->data);
        }
        ptr2 = ptr2->next;
    }
    return head;
}