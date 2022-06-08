// Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

int sum(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lsum = sum(node->left);
		int rsum = sum(node->right);
		if (node->left == NULL && node->right == NULL)
		{
			int value = node->data;
			node->data = 0;
			return value;
		}
		else
		{
			int value = node->data;
			node->data = lsum + rsum;
			return (node->data + value);
		}
	}
}

void toSumTree(Node *node)
{
	sum(node);
}