// here is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// // Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        int rot = low;
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int actualmid = (mid + rot) % n;
            if (nums[actualmid] == target) return actualmid;
            else if (target > nums[actualmid]) l = mid + 1;
            else h = mid - 1;
        }
        return -1;
    }
};