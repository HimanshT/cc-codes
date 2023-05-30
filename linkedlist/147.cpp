// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *back, *curr, *front;
        back = NULL, curr = head;
        while (curr != NULL)
        {
            front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        return back;
    }
    Node* addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        Node *ptr = reverse(head);
        int carry = 0;
        Node *temp = ptr;
        temp->data = temp->data + 1;
        if (temp->data == 10)
        {
            carry = 1;
            temp->data = 0;
            temp = temp->next;
            while (temp != NULL)
            {
                int sum = carry + temp->data;
                temp->data = sum % 10;
                carry = sum / 10;
                temp = temp->next;
            }
        }
        if (carry == 1)
        {
            Node *curr = new Node(carry);
            Node *temp1 = ptr;
            while (temp1->next != NULL) temp1 = temp1->next;
            temp1->next = curr;
        }

        Node *ans = reverse(ptr);
        return ans;
    }
};

// other approach
//  Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
//  Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. Keep moving to the next node while there is a carry.
//  Reverse modified linked list and return head.

// can be solved recursively easily
int addWithCarry(Node *head)
{
    // If linked list is empty, then
    // return carry
    if (head == NULL)
        return 1;

    // Add carry returned be next node call
    int res = head->data + addWithCarry(head->next);

    // Update data and return new carry
    head->data = (res) % 10;
    return (res) / 10;
}

// This function mainly uses addWithCarry().
Node *addOne(Node *head)
{
    // Add 1 to linked list from end to beginning
    int carry = addWithCarry(head);

    // If there is carry after processing all nodes,
    // then we need to add a new node to linked list
    if (carry)
    {
        Node *newNode = new Node;
        newNode->data = carry;
        newNode->next = head;
        return newNode; // New node becomes head now
    }

    return head;
}