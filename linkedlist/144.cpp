// Remove duplicate element from sorted Linked List
Node *removeDuplicates(Node *head)
{
    Node *cur = head;
    Node *front;
    while (cur != NULL && cur->next != NULL)
    {

        front = cur->next;
        while (front->data == cur->data)
        {
            front = front->next;
            if (front == NULL)
                break;
        }
        cur->next = front;
        cur = front;
    }
    return head;
}