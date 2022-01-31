// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

bool isPalindrome(Node *head)
{
    vector<int> v1;
    Node *ptr = head;
    int n = 0;
    while (ptr != NULL)
    {
        v1.insert(v1.begin(), ptr->data);
        n++;
        ptr = ptr->next;
    }
    Node *ptr1 = head;
    for (int i = 0; i < n; i++)
    {
        if (v1[i] != ptr1->data)
            return false;
        ptr1 = ptr1->next;
    }
    return true;
}

// METHOD 1 (Use a Stack)

// A simple solution is to use a stack of list nodes. This mainly involves three steps.
// Traverse the given list from head to tail and push every visited node to stack.
// Traverse the list again. For every visited node, pop a node from the stack and compare data of popped node with the currently visited node.
// If all nodes matched, then return true, else false.

// METHOD 2 (By reversing the list)
// This method takes O(n) time and O(1) extra space.
// 1) Get the middle of the linked list.
// 2) Reverse the second half of the linked list.
// 3) Check if the first half and second half are identical.
// 4) Construct the original linked list by reversing the second half again and attaching it back to the first half

// METHOD 3 (Using Recursion)
// Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
// 1) Sub-list is a palindrome.
// 2) Value at current left and right are matching.
