// Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa maintaining the order of appearance.

class Solution {
public:

    void rearrange(int arr[], int n) {
        // code here
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }
        int ptr1 = 0, ptr2 = 0;
        int x = min(pos.size(), neg.size());
        for (int i = 0; i < 2 * x; i += 2)
        {
            arr[i] = pos[ptr1];
            ptr1++;
        }
        for (int j = 1; j < 2 * x; j += 2)
        {
            arr[j] = neg[ptr2];
            ptr2++;
        }
        int ptr3 = 2 * x;
        while (ptr1 < pos.size())
        {
            arr[ptr3] = pos[ptr1];
            ptr3++, ptr1++;
        }
        while (ptr2 < neg.size())
        {
            arr[ptr3] = neg[ptr2];
            ptr3++, ptr2++;
        }
    }
};
