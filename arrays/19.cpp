// Given an array of intervals where intervals[i] = [starti, endi],
//merge all overlapping intervals, and return an array of the non-overlapping
//intervals that cover all the intervals in the input.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> sol;
		sort(intervals.begin(), intervals.end());
		int n = intervals.size();
		sol.push_back(intervals[0]);
		int idx = 0;
		for (int i = 1; i < n; i++)
		{
			if (intervals[i][0] >= sol[idx][0] and intervals[i][0] <= sol[idx][1])
			{
				sol[idx][1] = max(sol[idx][1], intervals[i][1]);
			} else {
				sol.push_back(intervals[i]);
				idx++;
			}
		}
		return sol;
	}
};