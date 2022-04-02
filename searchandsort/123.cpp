// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int num=n+m;
        int arr[num];
        int ptr1=0,ptr2=0;
        for(int i=0;i<num;i++)
        {
            if(ptr1<n && ptr2<m)
            {
                if(arr1[ptr1]<=arr2[ptr2])
                {
                    arr[i]=arr1[ptr1];
                    ptr1++;
                }
                else
                {
                    arr[i]=arr2[ptr2];
                    ptr2++;
                }
            }
            else if(ptr1>=n)
            {
                arr[i]=arr2[ptr2];
                ptr2++;
            }
            else
            {
                arr[i]=arr1[ptr1];
                ptr1++;
            }
        }
        return arr[k-1];
        
    }

   //using searching and sorting

    