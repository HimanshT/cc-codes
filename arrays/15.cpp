// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element.
//Find the minimum number of jumps to reach the end of the array(starting from the first element).
//If an element is 0, then you cannot move through that element.
class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (arr[0] == 0 && n > 1)
            return -1;
        else if (n == 1)
            return 0;
        int jump = 0;
        for (int i = 0; i < n;)
        {
            int j = i + arr[i];
            if (j >= n - 1)
            {
                jump++;
                return jump;
            }
            int max_index = 0;
            int pos = 0;
            for (int k = (i + 1); k <= j; k++)
            {
                if (arr[k] != 0)
                {
                    int curr_index;
                    curr_index = k + arr[k];
                    if (curr_index > max_index)
                    {
                        max_index = curr_index;
                        pos = k;
                    }
                }
            }
            if (max_index == 0)
                return -1;
            i = pos;
            jump++;
        }
    }
};