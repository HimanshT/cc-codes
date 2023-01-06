// Given an array of size n and a number k, find all elements that appear more than n/k times

// approach is sort using nLogn and then traversing;
// we need time complexity O(kn);
// hashing approach--->easy
// just count how many times it appears and then solve it

//what we are actually doing is that we need to form pairs of k elements,so we take array of k-1 elements and when a new elements comes
//we subtract all k-1 elements by 1 ,so that they all form a set of k distince elements.At last the remaining would be the one extra
//after pairing
//you can visualsize by considering n/2 case.if it appears more than n/2 times,after pairing n/2 times,1 of its occurenence will be still
//remaining

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MIN, count1 = 0, count2 = 0;
        int n = nums.size();
        for (int i : nums)
        {
            if (i == candidate1) count1++;
            else if (i == candidate2) count2++;
            else if (count1 == 0) {
                candidate1 = i;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = i;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        if (count(nums.begin(), nums.end(), candidate1) > n / 3) ans.push_back(candidate1);
        if (count(nums.begin(), nums.end(), candidate2) > n / 3) ans.push_back(candidate2);
        return ans;
    }
};



