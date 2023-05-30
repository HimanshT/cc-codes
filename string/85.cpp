// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets.
// A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings.
// We can make an unbalanced string balanced by swapping adjacent characters.
// Calculate the minimum number of swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.

class Solution {
public:
	int minimumNumberOfSwaps(string S) {
		// code here
		int open = 0, close = 0, ans = 0, fault = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] == '[')
			{
				open++;
				if (fault > 0)
				{
					ans += fault;
					fault--;
				}
			} else {
				close++;
				fault = close - open;
			}
		}
		return ans;
	}
};