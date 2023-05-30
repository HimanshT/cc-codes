// Remove duplicate element from sorted Linked List

Node *removeDuplicates(Node *head)
{
// your code goes here
    Node *ptr = head;
    while (ptr != NULL)
    {
        Node *temp = ptr->next;
        while (temp != NULL and temp->data == ptr->data)
        {
            temp = temp->next;
        }
        ptr->next = temp;
        ptr = temp;
    }
    return head;
}