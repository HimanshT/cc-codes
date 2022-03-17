// here is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// // Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

class Solution {
public:
    
    int binarySearch(vector<int>& nums,int low,int high,int target)
    {
        if(low<=high)
        {
            int mid=(high+low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                return binarySearch(nums,low,mid-1,target);
            return binarySearch(nums,mid+1,high,target);
        }
        return -1;
    }
    
    int findIndex(vector<int>&nums,int n)
    {
       for(int j=n-1;j>0;j--)
       {
           if(nums[j-1]>nums[j])
               return j;
       }
        return 0;
    }
    
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=findIndex(nums,n);
        if(binarySearch(nums,0,index-1,target)!= -1)
            return binarySearch(nums,0,index-1,target);
        else 
            return binarySearch(nums,index,n-1,target);
    }
};