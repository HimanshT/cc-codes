// Given a string 's'. The task is to find the smallest window length that contains all the characters
// of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

class Solution {
public:
	int findSubString(string str)
	{
		// Your code goes here
		//count the distinct elements in the string
		unordered_set<char> uset1, uset2;
		for (char c : str)
			uset1.insert(c);
		int x = uset1.size();
		//finding the minimum window
		unordered_map<char, int> umap;
		int ans = INT_MAX;
		int l = 0, r = 0;
		while (l <= r)
		{
			if (uset2.size() == x)
			{
				ans = min(ans, r - l);
				if (umap[str[l]] == 1)
					uset2.erase(str[l]);
				umap[str[l]]--;
				l++;
			} else {
				if (r < str.length())
				{
					uset2.insert(str[r]);
					umap[str[r]]++;
					r++;
				} else
					break;
			}
		}
		return ans;
	}
};