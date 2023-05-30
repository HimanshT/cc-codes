// Largest Rectangular Area in a Histogram using Stack

//In this question the basic concept to solve this question is to find minimum value that current building in the left and right side,
//In this case you can get the area  5 7 6 8 9 0 ,so if for 6 the area would be upto 9 in right from 7 in left.
//to do this we can you use two loops and complexity will be n*n;
//this can be easily done with the help of stack in On complexity,
//we need to find the area considering min element when the top is greater than pushing element because,we now know,the minimum values from both
//sides of the element.

class Solution
{
public:
	//Function to find largest rectangular area possible in a given histogram.
	long long getMaxArea(long long arr[], int n)
	{
		stack<long long> st;
		long long ans = INT_MIN;
		int i = 0;
		while (i < n)
		{
			if (st.empty())
				st.push(i++);
			else if (arr[st.top()] <= arr[i])
				st.push(i++);
			else
			{
				int idx = st.top(); st.pop();
				long long area = arr[idx] * (st.empty() ? i : i - st.top() - 1);
				ans = max(ans, area);
			}
		}

		while (!st.empty())
		{
			int idx = st.top(); st.pop();
			long long area = arr[idx] * (st.empty() ? i : i - st.top() - 1);
			ans = max(ans, area);
		}
		return ans;
	}
};
