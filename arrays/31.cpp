// In daily share trading, a buyer buys shares in the morning and sells them on the same day.
//  If the trader is allowed to make at most 2 transactions in a day,
//  whereas the second transaction can only start after the first one is
//  complete (Buy->sell->Buy->sell). Given stock prices throughout the day,
//  find out the maximum profit that a share trader could have made.
#include <bits/stdc++.h>
using namespace std;
// approach if many transactions are allowed
// void findProfit(int *arr, int n)
// {
//     vector<int> diff;
//     int min = 100000;
//     int maxDiff = 0, preDiff = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < min)
//         {
//             diff.push_back(maxDiff);
//             min = arr[i];
//             maxDiff = 0;
//             preDiff = 0;
//             continue;
//         }
//         int currDiff = arr[i] - min;
//         maxDiff = max(maxDiff, currDiff);
//         if (currDiff < preDiff)
//         {
//             diff.push_back(maxDiff);
//             min = arr[i];
//             currDiff = 0, maxDiff = 0;
//         }
//         preDiff = currDiff;
//     }
//     diff.push_back(maxDiff);
//     int m = diff.size();
//     sort(diff.begin(), diff.end());
//     if (m == 1)
//         cout << diff[0] << endl;
//     else
//         cout << diff[m - 1] + diff[m - 2] << endl;
// }

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findProfit(arr, n);
    return 0;
}

// appraoch for two arrays
// first find for one transaction.then get i,make subarray from there and get another transaction;
// and add both of them;