// Job Sequencing Problem

static bool compare(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}

int slotPresent(int index, vector<int> slot)
{
	int i = index;
	while (i >= 0)
	{
		if (slot[i] == 0)
			return i;
		i--;
	}
	return 0;
}

vector<int> JobScheduling(Job arr[], int n)
{
	vector<pair<int, int>> v;
	int maxDead = 0;
	for (int i = 0; i < n; i++)
	{
		maxDead = max(maxDead, arr[i].dead);
		v.push_back(make_pair(arr[i].dead, arr[i].profit));
	}
	sort(v.begin(), v.end(), compare);
	//code to sol
	vector<int> slot(maxDead + 1, 0);
	vector<int> ans;
	int jobs = 1; int profit = v[0].second;
	slot[v[0].first] = 1;
	for (int i = 1; i < n; i++)
	{
		if (slotPresent(v[i].first, slot))
		{
			int index = slotPresent(v[i].first, slot);
			slot[index] = 1;
			jobs++;
			profit += v[i].second;
		}
	}
	ans.push_back(jobs); ans.push_back(profit);
	return ans;
}