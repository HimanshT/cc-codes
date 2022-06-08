
// Median of BST
//based on morris traversal . didn't got correct ans;

int countNodes(struct Node* root)
{
	struct Node *current, *pre;
	int count = 0;
	if (root == NULL)
		return count;
	current = root;
	while (current != NULL)
	{
		if (current->left == NULL)
		{
			count++;
			current = current->right;
		}
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;

			while (pre->right != NULL &&
			        pre->right != current)
				pre = pre->right;

			/* Make current as right child of its
			   inorder predecessor */
			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;//we were making mistake here
			}

			/* Revert the changes made in if part to
			   restore the original tree i.e., fix
			   the right child of predecessor */
			else
			{
				pre->right = NULL;

				// Increment count if the current
				// node is to be visited
				count++;
				current = current->right;
			}
		}
	}
	return count;
}

float findMedian(struct Node *root)
{
	if (root == NULL)
		return 0;
	int count = countNodes(root);
	int currCount = 0;
	struct Node *current = root, *pre, *prev;

	while (current != NULL)
	{
		if (current->left == NULL)
		{
			// count current node
			currCount++;

			// check if current node is the median
			// Odd case
			if (count % 2 != 0 && currCount == (count + 1) / 2)
				return (float)prev->data;

			// Even case
			else if (count % 2 == 0 && currCount == (count / 2) + 1)
				return ((float)(prev->data + current->data)) / 2.0;

			// Update prev for even no. of nodes
			prev = current;

			//Move to the right
			current = current->right;
		}
		else
		{

			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			if (pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}

			else
			{
				pre->right = NULL;

				prev = pre;

				currCount++;

				if (count % 2 != 0 && currCount == (count + 1) / 2 )
					return (float)current->data;

				else if (count % 2 == 0 && currCount == (count / 2) + 1)
					return (float)(prev->data + current->data) / 2.0;
				prev = current;
				current = current->right;

			}
		}
	}