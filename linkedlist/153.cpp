// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return head;
        if (!head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast != NULL and fast->next != NULL)
            fast = fast->next->next, slow = slow->next;
        return slow;
    }
};