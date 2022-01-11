// Given an array of size n and a number k, find all elements that appear more than n/k times

// approach is sort using nLogn and then traversing;
// we need time complexity O(kn);
// hashing approach--->easy
// just count how many times it appears and then solve it
#include <bits/stdc++.h>
using namespace std;

int findCount(int *arr, int n, int k, int count)
{
    int ans = 0;
}

int main()
{
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = 8, k = 4;
    int count = n / k;
    int ans = findCount(arr, n, k, count);
    cout << ans;
    return 0;
}