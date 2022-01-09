// Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 0)
            positive.push_back(arr[i]);
        else
            negative.push_back(arr[i]);
    }
    int pos = positive.size();
    int neg = negative.size();
    if (pos > neg)
    {
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (p1 < pos && p2 < neg)
            {
                if (i % 2 == 0)
                {
                    arr[i] = negative[p2];
                    p2++;
                }
                else
                {
                    arr[i] = positive[p1];
                    p1++;
                }
            }
            else
            {
                arr[i] = positive[p1];
                p1++;
            }
        }
    }
    else if (pos <= neg)
    {
        int p1 = 0, p2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (p1 < pos && p2 < neg)
            {
                if (i % 2 == 0)
                {
                    arr[i] = positive[p1];
                    p1++;
                }
                else
                {
                    arr[i] = negative[p2];
                    p2++;
                }
            }
            else
            {
                arr[i] = negative[p2];
                p2++;
            }
        }
    }

    for (int t = 0; t < n; t++)
        cout << arr[t] << " ";
    return 0;
}