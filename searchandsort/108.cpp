// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.
//boyer-moore majority algorithm

int majorityElement(int a[], int size)
    {
        
        // your code here
        int vote=0,candidate=-1;
        for(int i=0;i<size;i++)
        {
            if(vote==0)
            {
                candidate=a[i];
                vote=1;
            }
            else
            {
                if(a[i]==candidate)
                vote++;
                else
                vote--;
            }
        }
        
        int count=0;
        for(int i=0;i<size;i++)
        if(a[i]==candidate)
        count++;
        
        if(count>size/2)
        return candidate;
        else
        return -1;
        
    }