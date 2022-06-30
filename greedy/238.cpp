// N meetings in one room

static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
	vector<pair<int, int>> v1;
	for (int i = 0; i < n; i++)
		v1.push_back(make_pair(start[i], end[i]));
	sort(v1.begin(), v1.end(), cmp);
	int ans = 1;
	int curr = 0;
	for (int i = 1; i < n; i++) {
		if (v1[i].first > v1[curr].second)
		{
			curr = i;
			ans++;
		}
	}
	return ans;
}