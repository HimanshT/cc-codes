// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

bool isCircular(Node *head)
{
    Node *ptr = head;
    ptr = ptr->next;
    while (ptr != NULL)
    {
        if (ptr->next == head)
            return true;
        if (ptr->next == NULL)
            return false;
        ptr = ptr->next;
    }
    return false;
}