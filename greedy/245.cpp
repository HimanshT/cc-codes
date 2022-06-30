// Minimum Platforms

int findPlatform(int arr[], int dep[], int n)
{
	vector<pair<int, int>> v1; //arr[i]=0,dep[1];
	for (int i = 0; i < n; i++)
		v1.push_back(make_pair(arr[i], dep[i]));
	sort(v1.begin(), v1.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	int pf = 0;
	for (int i = 0; i < n; i++)
	{
		if (pq.empty())
		{
			pq.push(v1[i].second);
			//pf=max(pf,pq.size());
			if (pq.size() > pf)
				pf = pq.size();
		}
		else
		{
			while (pq.top() < v1[i].first && !pq.empty())
				pq.pop();
			pq.push(v1[i].second);
			//pf=max(pf,pq.size());
			if (pq.size() > pf)
				pf = pq.size();
		}
	}
	return pf;
}