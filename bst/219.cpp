// Populate Inorder Successor for all nodes

void inorder(Node* root, vector<Node*> &v1)
{
	if (root == NULL)
		return;
	inorder(root->left, v1);
	v1.push_back(root);
	inorder(root->right, v1);
}

void populateNext(Node *root)
{
	vector<Node*> v1;
	inorder(root, v1);
	int ptr1 = 0, ptr2 = 1;
	while (ptr2 < v1.size())
	{
		v1[ptr1]->next = v1[ptr2];
		ptr1++, ptr2++;
	}

}

//a better approach to it is morris traversal,since morris traversal is based on this concept
//only