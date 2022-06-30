// Fractional Knapsack

static bool compare(pair<int, int> &a, pair<int, int> &b)
{
	double d1 = (double)a.first / a.second;
	double d2 = (double)b.first / b.second;
	return d1 > d2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
	vector<pair<int, int>> v1;
	for (int i = 0; i < n; i++)
		v1.push_back(make_pair(arr[i].value, arr[i].weight));
	sort(v1.begin(), v1.end(), compare);
	double value = 0.0;

	for (int i = 0; i < n; i++)
	{
		if (v1[i].second <= W)
		{
			value += v1[i].first;
			W -= v1[i].second;
		}
		else {

			value = value + v1[i].first * (double(W) / v1[i].second);
			break;
		}
	}
	return value;
}