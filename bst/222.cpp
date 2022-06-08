// Binary Tree to BST

int i = 0;
void setValues(Node *root, vector<int> &v1)
{
	if (root == NULL)
		return;
	setValues(root->left, v1);
	root->data = v1[i]; i++;
	setValues(root->right, v1);
}

void inorder(Node *root, vector<int> &v1)
{
	if (root == NULL)
		return;
	inorder(root->left, v1);
	v1.push_back(root->data);
	inorder(root->right, v1);
}

Node *binaryTreeToBST (Node *root)
{
	vector<int> v1;
	inorder(root, v1);
	sort(v1.begin(), v1.end());
	setValues(root, v1);
	return root;
}