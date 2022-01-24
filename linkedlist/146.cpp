// Write a function that moves the last element to the front in a given Singly Linked List. For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.
// It's approach is easy
// 1->2->3->4->5 -->> 5->1->2->3->4

// we can make two pointers ptr1 & ptr2;
ptr1 = head;
ptr2 = ptr1->next;
while (ptr2->next != NULL)
{
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}

ptr2->next = head;
ptr1->next = NULL;
head = ptr2;