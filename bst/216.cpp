// Minimum element in BST

int minValue(Node* root) {
	// Code here
	if (root == NULL)
		return -1;
	Node* ptr = root;
	int ans = ptr->data;
	while (ptr->left)
	{
		ptr = ptr->left;
		ans = ptr->data;
	}
	return ans;
}