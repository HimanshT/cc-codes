// Lowest Common Ancestor in a BST

Node* LCA(Node *root, int n1, int n2)
{
	if (root->data == n1 || root->data == n2)
		return root;
	if (root->right == NULL && root->left == NULL)
		return NULL;
	Node* left = NULL; Node* right = NULL;
	if (root->left)
		left = LCA(root->left, n1, n2);
	if (root->right)
		right = LCA(root->right, n1, n2);
	if (left && right)
		return root;
	return left == NULL ? right : left;
}

//optimised approach

Node* LCA(Node *root, int n1, int n2)
{
	//Your code here
	if (root == NULL)
		return NULL;

	Node* curr = root;

	while (curr != NULL)
	{
		if (curr->data > n1 && curr->data > n2)
			curr = curr->left;
		else if (curr->data < n1 && curr->data < n2)
			curr = curr->right;
		else
		{
			break;
		}
	}
	return curr;
}