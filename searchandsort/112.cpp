// Stickler the thief wants to loot money from a society having n houses in a single line.
// He is a weird person and follows a certain rule when looting the houses.
//  According to the rule, he will never loot two consecutive houses.
//  At the same time, he wants to maximize the amount he loots.
//  The thief knows which house has what amount of money but is unable
//  to come up with an optimal looting strategy.
//  He asks for your help to find the maximum money he can get if he
//   strictly follows the rule. Each house has a[i]amount of money present in it.

class Solution
{
public:
	int FindMaxSum(int arr[], int n)
	{
		vector<int> v(n + 2, 0);
		v[0] = v[1] = 0;
		for (int i = 2; i < n + 2; i++)
		{
			v[i] = max(v[i - 1], arr[i - 2] + v[i - 2]);
		}
		return v[n + 1];
	}
};