// Given an array of integers, sort the array (in descending order) according to count of set bits in binary representation of array elements. 

int findBits(int n)
    {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
    
    static bool cmp(const pair<int,int> a,const pair<int,int> b)
    {
        return (a.second>b.second);
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        
        vector<pair<int,int>> v1;
        for(int i=0;i<n;i++)
        {
            int x = findBits(arr[i]);
            v1.push_back(make_pair(arr[i],x));
        }
        
       stable_sort(v1.begin(),v1.end(),cmp);
        //if you need to apply stable sort
        //put the second pair to the one on whose respect it is to be sorted
        
        for(int i=0;i<n;i++)
        arr[i]=v1[i].first;
        
    }