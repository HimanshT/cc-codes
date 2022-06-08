// Predecessor and Successor

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

	pre = NULL;
	Node* curr = root;
	while (curr)
	{
		if (curr->key >= key)
			curr = curr->left;
		else
		{
			pre = curr;
			curr = curr->right;
		}
	}
	//suc

	suc = NULL;
	Node* temp = root;
	while (temp)
	{
		if (temp->key <= key)
			temp = temp->right;
		else
		{
			suc = temp;
			temp = temp->left;
		}
	}

}