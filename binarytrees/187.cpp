// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

vector<int> topView(Node *root)
{
	//Your code here
	map<int, Node*> mp;
	queue<pair<int, Node*>> q;
	q.push(make_pair(0, root));
	while (!q.empty())
	{
		for (int i = 0; i < q.size(); i++)
		{
			int l = q.front().first;
			Node *curr = q.front().second;
			q.pop();
			//checking in the map
			if (!mp.count(l))
				mp[l] = curr;
			if (curr->left)
				q.push({(l - 1), curr->left});
			if (curr->right)
				q.push({(l + 1), curr->right});
		}
	}

	vector<int> ans;
	for (auto it : mp)
		ans.push_back((it.second)->data);
	return ans;
}