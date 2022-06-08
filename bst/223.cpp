// Normal BST to Balanced BST

void fn(Node* root, vector<Node*>&v)
{
	if (root == NULL)
		return;
	fn(root->left, v);
	v.push_back(root);
	fn(root->right, v);
}

Node* buildTree(vector<Node*>&v, int low, int high)
{
	if (low > high)  return NULL;
	int mid = (low + high) / 2;
	Node* root = v[mid];
	root->left = buildTree(v, low, mid - 1);
	root->right = buildTree(v, mid + 1, high);
	return root;
}

Node* buildBalancedTree(Node* root)
{
	vector<Node*> v;
	fn(root, v);
	int n = v.size();
	return buildTree(v, 0, n - 1);
}