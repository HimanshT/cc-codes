// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Node *addOne(Node *head)
{
    vector<int> number;
    Node *ptr = head;
    while (ptr != NULL)
    {
        number.push_back(ptr->data);
        ptr = ptr->next;
    }

    int n = number.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        number[i] += carry;
        if (number[i] >= 10)
        {
            carry = number[i] / 10;
            number[i] = number[i] % 10;
        }
        else
        {
            carry = 0;
            break;
        }
    }
    if (carry >= 1)
    {
        number.insert(number.begin(), carry);
        Node *ptr1 = (Node *)malloc(sizeof(Node));
        ptr1->data = carry;
        ptr1->next = head;
        head = ptr1;
        Node *test;
        test = head->next;
        int j = 1;
        while (test != NULL)
        {
            test->data = number[j];
            j++;
            test = test->next;
        }
    }
    else
    {
        Node *test;
        test = head;
        int j = 0;
        while (test != NULL)
        {
            test->data = number[j];
            j++;
            test = test->next;
        }
    }
    return head;
}

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