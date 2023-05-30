// Sort the given Linked List using bubble sort.
// which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

struct node *getTail(struct node *head)
{
	while (head->next != NULL)
		head = head->next;
	return head;
}
//partition the list containing last element as pivot
struct node *partition(struct node *head, struct node *end, struct node **newHead, struct node **newEnd)
{
	struct node *pivot = end;
	struct node *prev = NULL, *cur = head, *tail = pivot;
	while (cur != pivot)
	{
		if (cur->data < pivot->data)
		{
			if (*newHead == NULL) *newHead = cur;
			prev = cur;
			cur = cur->next;
		}
		else {
			if (prev)
				prev->next = cur->next;
			struct node *temp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = temp;
		}
	}
	//if pivot data is the smallest element in the current list,
	if (*newHead == NULL)
		*newHead = pivot;
	//update newEnd to the current last node
	*newEnd = tail;
	return pivot;

}
struct node *quickSortRecur(struct node *head, struct node* end)
{
	//base condition
	if (!head or head == end) return head;
	struct node *newHead = NULL, *newEnd = NULL;
	struct node *pivot = partition(head, end, &newHead, &newEnd);
	if (newHead != pivot)
	{
		struct node *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		//recur for list before pivot
		newHead = quickSortRecur(newHead, tmp);
		tmp = getTail(newHead);
		tmp->next = pivot;
	}
	pivot->next = quickSortRecur(pivot->next, newEnd);
	return newHead;
}
void quickSort(struct node **headRef) {
	*headRef = quickSortRecur(*headRef, getTail(*headRef));
}