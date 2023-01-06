// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal
class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int ans = 0; unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            ans += umap[k - arr[i]];
            umap[arr[i]]++;
        }
        return ans;
    }
};