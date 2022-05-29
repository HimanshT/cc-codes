// Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one.

// You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.
int dp[505][2005];
int sol(int i, int rem, vector<int>&arr, int &k)
{   int dp[505][2005];
    int sol(int i, int rem, vector<int>&arr, int &k)
    {
        if (i == arr.size())
            return 0;
        if (dp[i][rem] != -1)
            return dp[i][rem];
        int ans;
        if (arr[i] > rem)
        {
            ans = (rem + 1) * (rem + 1) + sol(i + 1, k - arr[i] - 1, arr, k);
        }
        else {
            int choice1 = (rem + 1) * (rem + 1) + sol(i + 1, k - arr[i] - 1, arr, k);
            int choice2 = sol(i + 1, rem - arr[i] - 1, arr, k);
            ans = min(choice1, choice2);
        }
        dp[i][rem] = ans;
        return dp[i][rem];
    }

    int solveWordWrap(vector<int>arr, int k)
    {
        // Code here
        memset(dp, -1, sizeof(dp));
        return sol(0, k, arr, k);
    }

    /*

    In this we have to think like this
    a a _ _ _ _ --> if we fill this empty placs = k-arr[i]-1
    For next word two choices,either I fill in 38 or in new line
    if 38 itself--> remaining spaces= rem-arr[i]-1
    if new line---> remaining spaces in new line=k-arr[i]-1;
    Initially there were two cases.
                                 if(arr[i]>rem)
                                 In this case go to new line
                                 if(arr[i]<rem)
                                 |
                                 |
                                 |
                                 (1)Fill in the same line
                                 (2)Go to new line

    */