// Merge two BST 's

void inorder(Node* root, vector<int>&v)
{
	if (root == NULL)
		return;
	inorder(root->left, v);
	v.push_back(root->data);
	inorder(root->right, v);
}

vector<int> merge(Node *root1, Node *root2)
{
	vector<int> v1;
	vector<int> v2;
	inorder(root1, v1);
	inorder(root2, v2);
	int m = v1.size();
	int n = v2.size();
	vector<int> ans(m + n, 0);
	//merge the two arrays
	int ptr1 = 0, ptr2 = 0;
	for (int i = 0; i < (m + n); i++)
	{
		if (ptr1 < m && ptr2 < n)
		{
			if (v1[ptr1] < v2[ptr2])
			{
				ans[i] = v1[ptr1];
				ptr1++;
			}
			else
			{
				ans[i] = v2[ptr2];
				ptr2++;
			}
		}
		else if (ptr1 >= m)
		{
			ans[i] = v2[ptr2];
			ptr2++;
		}
		else
		{
			ans[i] = v1[ptr1];
			ptr1++;
		}
	}
	return ans;
}