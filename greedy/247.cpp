// Shop in Candy Store

vector<int> candyStore(int candies[], int N, int K)
{
	sort(candies, candies + N);
	int ptr1 = 0; int ptr2 = N;
	int mini = 0;
	while (ptr1 < ptr2)
	{
		mini += candies[ptr1];
		ptr2 = ptr2 - K;
		ptr1++;
	}

	int maxi = 0;
	ptr1 = -1, ptr2 = N - 1;
	while (ptr1 < ptr2)
	{
		maxi += candies[ptr2];
		ptr2--;
		ptr1 += K;
	}
	vector<int> sol; sol.push_back(mini); sol.push_back(maxi);
	return sol;
}