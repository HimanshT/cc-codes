// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Node *insertLast(Node *head, int n)
{
    if (head == NULL)
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr->data = n;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        Node *pre, *cur;
        pre = head, cur = head->next;
        Node *element = (Node *)malloc(sizeof(Node));
        element->data = n;
        if (n < pre->data)
        {
            element->next = head;
            head = element;
            return head;
        }
        while (cur != NULL)
        {
            if (n >= pre->data && n <= cur->data)
            {
                pre->next = element;
                element->next = cur;
                break;
            }
            pre = pre->next;
            cur = cur->next;
        }
        if (cur == NULL)
        {
            pre->next = element;
            element->next = NULL;
        }
    }
    return head;
}
// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    for (int i = 0; i < K; i++)
    {
        Node *ptr1 = arr[i];
        while (ptr1 != NULL)
        {
            head = insertLast(head, ptr1->data);
            ptr1 = ptr1->next;
        }
    }

    return head;
}
// it gave tle

Node *insertFirst(Node *head, int n)
{
    if (head == NULL)
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr->data = n;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr->data = n;
        ptr->next = head;
        head = ptr;
    }
    return head;
}
// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    Node *head = NULL;
    vector<int> v1;
    for (int i = 0; i < K; i++)
    {
        Node *ptr = arr[i];
        while (ptr != NULL)
        {
            v1.push_back(ptr->data);
            ptr = ptr->next;
        }
    }
    sort(v1.begin(), v1.end());
    int len = v1.size();
    for (int i = len - 1; i >= 0; i--)
        head = insertFirst(head, v1[i]);
    return head;
}