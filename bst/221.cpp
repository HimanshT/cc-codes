// Construct Binary Search Tree from Preorder Traversal

int j = 0;
TreeNode* createTree(vector<int>& inorder, int i1, int i2, vector<int>& preorder)
{
	if (i1 > i2) return NULL;
	TreeNode* temp = new TreeNode(preorder[j]);
	int index = i1;
	for (int i = i1; i <= i2; i++)
	{
		if (inorder[i] == preorder[j])
		{
			index = i;
			break;
		}
	}
	j++;
	temp->left = createTree(inorder, i1, index - 1, preorder);
	temp->right = createTree(inorder, index + 1, i2, preorder);
	return temp;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
	vector<int> inorder = preorder;
	sort(inorder.begin(), inorder.end());
	TreeNode* head = createTree(inorder, 0, inorder.size() - 1, preorder);
	return head;
}