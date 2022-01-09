// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 1)
            return 0;
        int profit = 0;
        int min = prices[0];
        for (int i = 0; i < n; i++)
        {
            int curr_profit = prices[i] - min;
            if (curr_profit > profit)
                profit = curr_profit;
            if (prices[i] < min)
                min = prices[i];
        }
        return profit;
    }
};
