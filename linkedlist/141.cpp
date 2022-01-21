// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

bool detectLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    if (head->next == NULL || head == NULL)
        return false;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
        if (fast == slow)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}