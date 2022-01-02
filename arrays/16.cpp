// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int value;
        for (int i = 0; i < (nums.size() - 1); i++)
        {
            if (nums.at(i) == nums.at(i + 1))
            {
                value = nums.at(i);
            }
        }
        return value;
    }
};