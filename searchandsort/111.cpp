// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> v1;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=k-arr[i]-arr[j];
                //now find the sum from the remaining array
                int ptr1=j+1,ptr2=n-1;
                while(ptr1<ptr2)
                {
                    vector<int> quad;
                    if(arr[ptr1]+arr[ptr2]==sum)
                    {
                        quad.push_back(arr[i]);
                        quad.push_back(arr[j]);
                        quad.push_back(arr[ptr1]);
                        quad.push_back(arr[ptr2]);
                        v1.push_back(quad);
                        ptr1++;
                    }
                    else if(arr[ptr1]+arr[ptr2]<sum)
                    ptr1++;
                    else
                    ptr2--;
                }
            }
        }
        //remove duplicate entries from multidimensional vector
        sort(v1.begin(),v1.end());
        v1.erase(unique(v1.begin(),v1.end()),v1.end());
        return v1;
    }