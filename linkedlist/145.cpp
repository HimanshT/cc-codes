// Remove duplicates from an unsorted linked list

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head)
    {
        // your code goes here
        unordered_map<int, int> umap;
        Node *ptr = head;
        umap[ptr->data]++;
        while (ptr->next != NULL)
        {
            if (umap[ptr->next->data] == 1)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
                umap[ptr->data]++;
            }
        }
        return head;
    }
};
