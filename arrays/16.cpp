// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            int cnt = 0;
            for (auto &x : nums)
            {
                if (x <= mid)
                    cnt++;
            }
            if (cnt > mid)
            {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};

//can be also solved using linked list cycle concept
// updating index of numbers by flipping them


// To recap, we need to find the smallest number such that the count of numbers less than or equal to it is greater than the number itself.

// Apply binary search and start with the entire range of numbers [1,n][1,n][1,n].

// Note: Binary search will be applied to the numbers in the range [1,n] (inclusive) regardless of the contents of the array. So even if a number does not exist in the array, we will still evaluate it. For example, if the array is [1,2,4,2,2,5][1,2,4,2,2,5][1,2,4,2,2,5], the algorithm will first evaluate the number 3 even though that number does not exist in the array.
// Find the mid-point (curcurcur).

// For curcurcur, count how many numbers in the input array are less than or equal to it.

// If that number strictly exceeds curcurcur, then store that as the answer and continue to look for a smaller number that satisfies the condition by narrowing the window to the left [low,cur−1][low, cur - 1][low,cur−1].
// Otherwise, narrow down the window to the right [cur+1,high][cur + 1, high][cur+1,high].
// Repeat step 3 until we've exhausted the search range (i.e. until lowlowlow > highhighhigh) and return the lowest value that met the aforementioned condition.