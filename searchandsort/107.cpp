// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=(int *)malloc(sizeof(int)*3);
        int hash[n+1];
        for(int i=0;i<=n;i++)
        hash[i]=0;
        for(int i=0;i<n;i++)
        hash[arr[i]]++;
        for(int i=1;i<=n;i++)
        {
            if(hash[i]==2)
            ans[0]=i;
            if(hash[i]==0)
            ans[1]=i;
        }
        return ans;
    }