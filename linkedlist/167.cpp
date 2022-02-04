// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Node *segregate(Node *head)
{

    int zero = 0, one = 0, two = 0;
    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
            zero++;
        else if (ptr->data == 1)
            one++;
        else
            two++;
        ptr = ptr->next;
    }
    Node *ptr1 = head;
    int i = 0;
    while (i < zero)
    {
        ptr1->data = 0;
        i++;
        ptr1 = ptr1->next;
    }
    i = 0;
    while (i < one)
    {
        ptr1->data = 1;
        i++;
        ptr1 = ptr1->next;
    }
    i = 0;
    while (i < two)
    {
        ptr1->data = 2;
        i++;
        ptr1 = ptr1->next;
    }
    return head;
}

// other way can be to check the element,if it is one continue,if it is tail ,send it front,else send it in the last.
// update front and last every time