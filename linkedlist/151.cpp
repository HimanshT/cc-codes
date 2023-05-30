// merge sort

class Solution {
public:
	//Function to sort the given linked list using Merge Sort.
	Node *merge(Node *left, Node *right)
	{
		if (left == NULL) return right;
		if (right == NULL) return left;
		Node *ans = new Node(-1);
		Node *temp = ans;

		while (left != NULL and right != NULL) {
			if (left->data < right->data) {
				temp->next = left;
				temp = left;
				left = left->next;
			} else {
				temp->next = right;
				temp = right;
				right = right->next;
			}
		}

		while (left != NULL) {
			temp->next = left;
			temp = left;
			left = left->next;
		}

		while (right != NULL)
		{
			temp->next = right;
			temp = right;
			right = right->next;
		}

		ans = ans->next;
		return ans;
	}
	Node *findMid(Node* head)
	{
		Node *fast, *slow;
		slow = head, fast = head->next;
		while (fast != NULL and fast->next != NULL)
		{
			slow = slow->next, fast = fast->next->next;
		}
		return slow;
	}
	Node* mergeSort(Node* head) {
		// your code here
		if (head == NULL or head->next == NULL) return head;
		Node *mid = findMid(head);
		Node *left = head; Node *right = mid->next;
		mid->next = NULL;

		left = mergeSort(left);
		right = mergeSort(right);

		return merge(left, right);
	}
};