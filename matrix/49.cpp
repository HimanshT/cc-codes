// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.
//it is the histogram approach where we modiy the arrays to create a histogram out of it and then use that histogram
//code similar on each row to find the answer
class Solution {
public:
	int maxArea(int M[MAX][MAX], int n, int m) {
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (M[i][j] == 0)
					continue;
				else
					M[i][j] += M[i - 1][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int maxarea = 0;
			stack<int> st;
			int ptr = 0;
			while (ptr < m)
			{
				if (st.empty())
					st.push(ptr++);
				else if (M[i][st.top()] <= M[i][ptr])
					st.push(ptr++);
				else
				{
					int idx = st.top(); st.pop();
					int area = M[i][idx] * (st.empty() ? ptr : ptr - st.top() - 1);
					maxarea = max(area, maxarea);
				}
			}

			while (!st.empty())
			{
				int idx = st.top(); st.pop();
				int area = M[i][idx] * (st.empty() ? ptr : ptr - st.top() - 1);
				maxarea = max(area, maxarea);
			}
			ans = max(ans, maxarea);
		}

		return ans;
	}
};