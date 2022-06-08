// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.

Node* build(int in[], int i1, int i2, queue<int> &q)
{
	if (i1 > i2)
		return NULL;
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (i1 == i2)
	{
		temp->data = in[i1];
		temp->right = NULL;
		temp->left = NULL;
		q.pop();
		return temp;
	}
	else
	{
		temp->data = q.front();
		int index = i1;
		for (int i = i1; i <= i2; i++)
		{
			if (in[i] == q.front())
			{
				index = i;
				break;
			}
		}
		q.pop();
		temp->left = build(in, i1, index - 1, q);
		temp->right = build(in, index + 1, i2, q);
		return temp;
	}
}
Node* buildTree(int in[], int pre[], int n)
{
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(pre[i]);
	struct Node* head = build(in, 0, n - 1, q);
	return head;
}