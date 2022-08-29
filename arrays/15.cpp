// Given an array of N integers arr[] where each element represents the max number
// of steps that can be made forward from that element.
//Find the minimum number of jumps to reach the end of the array(starting from the first element).
//If an element is 0, then you cannot move through that element.
class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;
        //code
        //iterate through all the indexes
        int ans = 0;
        for (int i = 0; i < n;)
        {
            int maxReach = i + arr[i];
            if (maxReach >= n - 1)
            {
                return ans + 1;
            }
            int idx = 0;
            int currReach = 0;
            for (int j = i + 1; j <= maxReach; j++)
            {
                if (arr[j] != 0)
                {
                    int reach = j + arr[j];
                    if (reach > currReach)
                    {
                        idx = j; currReach = reach;
                    }
                }
            }
            if (currReach == 0)
                return -1;
            i = idx; ans++;
        }
        return ans;
    }
};