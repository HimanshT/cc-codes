// Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.

bool search(Node* root, int x) {
	if (root == NULL)
		return false;
	if (root->data == x)
		return true;
	else if (x > root->data)
		search(root->right, x);
	else if (x < root->data)
		search(root->left, x);

}