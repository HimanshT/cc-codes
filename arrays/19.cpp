// Given an array of intervals where intervals[i] = [starti, endi],
//merge all overlapping intervals, and return an array of the non-overlapping
//intervals that cover all the intervals in the input.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		ans.push_back({intervals[0][0], intervals[0][1]});
		int idx = 0;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] <= ans[idx][1])
			{
				ans[idx][0] = min(ans[idx][0], intervals[i][0]);
				ans[idx][1] = max(ans[idx][1], intervals[i][1]);
			} else
			{
				ans.push_back({intervals[i][0], intervals[i][1]});
				idx++;
			}
		}
		return ans;
	}
};