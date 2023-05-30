// Given binary string str of length N.
//The task is to find the maximum count of consecutive substrings str can be divided into such that all the substrings are balanced i.e. they have an equal number of 0s and 1s. If it is not possible to split str satisfying the conditions then return -1.

class Solution {
public:
	int maxSubStr(string str) {
		//Write your code here
		int c0 = 0, c1 = 0;
		int ans = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '0') c0++;
			else c1++;
			if (c0 == c1 and c0 != 0)
			{
				ans++, c0 = 0, c1 = 0;
			}
		}
		if (c0 > 0 or c1 > 0) {

			return -1;
		}
		return ans;
	}
};