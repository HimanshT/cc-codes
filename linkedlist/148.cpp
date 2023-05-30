// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
// segmentation fault;
class Solution
{
public:
    Node *ans(Node* head1, Node* head2)
    {
        int carry = 0;
        Node *head = NULL;
        Node *ptr = head;
        while (head1 != NULL and head2 != NULL)
        {
            int sum = head1->data + head2->data + carry;
            carry = sum / 10;
            if (head == NULL)
            {
                Node *temp = new Node(sum % 10);
                head = temp;
                ptr = head;
            } else
            {
                Node *temp = new Node(sum % 10);
                ptr->next = temp;
                ptr = ptr->next;
            }
            head1 = head1->next, head2 = head2->next;
        }

        while (head1 != NULL)
        {
            int sum = head1->data + carry;
            carry = sum / 10;
            if (head == NULL)
            {
                Node *temp = new Node(sum % 10);
                head = temp;
                ptr = head;
            } else
            {
                Node *temp = new Node(sum % 10);
                ptr->next = temp;
                ptr = ptr->next;
            }
            head1 = head1->next;
        }

        while (carry > 0)
        {
            Node *temp = new Node(carry % 10);
            carry = carry / 10;
            ptr->next = temp;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }

    int length(Node *head)
    {
        int n = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            n++;
        }
        return n;
    }
    Node *reverse(Node *head)
    {
        Node *pre, *cur, *front;
        pre = NULL, cur = head, front = NULL;
        while (cur != NULL)
        {
            front = cur->next;
            cur->next = pre;
            pre = cur;
            cur = front;
        }
        return pre;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *head1 = reverse(first);
        Node *head2 = reverse(second);
        int n1 = length(head1);
        int n2 = length(head2);
        if (n1 >= n2)
            return reverse(ans(head1, head2));
        else
            return reverse(ans(head2, head1));
    }
};