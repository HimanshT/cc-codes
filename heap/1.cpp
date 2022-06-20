#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	set<int> s1;
	int a = 3, b = 5;
	int k = 1;
	while ((a * k) < 1000)
	{
		s1.insert(a * k);
		k++;
	}
	k = 1;
	while ((b * k) < 1000)
	{
		s1.insert(b * k);
		k++;
	}

	int sum = 0;
	for (auto it : s1)
		sum += it;
	cout << sum;
	return 0;
}