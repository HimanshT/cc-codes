// Intersection of two sorted Linked lists
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int, int> umap;
    while (head1 != NULL)
    {
        umap[head1->data]++;
        head1 = head1->next;
    }

    Node *head = NULL;
    Node *ptr = head;
    while (head2 != NULL)
    {
        if (umap[head2->data] > 0)
        {
            umap[head2->data]--;
            if (head == NULL)
            {
                Node *temp = new Node(head2->data);
                head = temp;
                ptr = head;
            } else
            {
                Node *temp = new Node(head2->data);
                ptr->next = temp;
                ptr = ptr->next;
            }
        }
        head2 = head2->next;
    }
    return head;
}