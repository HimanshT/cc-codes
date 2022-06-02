// Given a Binary Tree, convert it into its mirror.

void mirror(Node* node) {
	// code here
	if (node == NULL)
		return;
	Node *ptr;
	ptr = node->right;
	node->right = node->left;
	node->left = ptr;
	mirror(node->left);
	mirror(node->right);
}