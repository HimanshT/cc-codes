// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//The only diff bw calculating top and bottom view is that,
//In case of top view do not update the map for already calculated values
//whereas in bottom view update the values which are already caculated

vector <int> bottomView(Node *root) {
	// Your Code Here
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