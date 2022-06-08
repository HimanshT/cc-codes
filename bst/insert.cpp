// fn to insert a value in bst
//im points

//It always takes place in leaf node && root is only modified when root==NULL;

void sol(Node* root, int Key)
{
	if (root->data == Key)
		return;
	if (Key > root->data)
	{
		if (root->right)
			sol(root->right, Key);
		else
		{
			Node* ans = new Node(Key);
			root->right = ans;
			return;
		}
	}
	if (Key < root->data)
	{
		if (root->left)
			sol(root->left, Key);
		else
		{
			Node* ans = new Node(Key);
			root->left = ans;
			return;
		}
	}

}
Node* insert(Node* root, int Key) {
	if (root == NULL)
	{
		Node* ans = new Node(Key);
		root = ans;
	}
	else
		sol(root, Key);
	return root;
}