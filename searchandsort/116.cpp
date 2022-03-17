// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here       
        int zero[2001]={0};
        int zeroes=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zeroes++;
                zero[nums[i]]=1;
            }
        }
        if(zeroes>=2)
        {
            vector<long long int>products(n,0);
            return products;
        }
        else if(zeroes==1)
        {
            vector<long long int>products;
            long long product=1;
            int zeroIndex=0;
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    zeroIndex=i;
                    continue;
                }
                else
                product = product * nums[i];
            }
            
            for(int j=0;j<n;j++)
            {
                if(j==zeroIndex)
                products.push_back(product);
                else
                products.push_back(0);
            }
            return products;
        }
        else{
            vector<long long int>products;
            long long product=1;
            for(int i=0;i<n;i++)
            {
                product = product * nums[i];
            }
             for(int j=0;j<n;j++)
            {
                long long value=product/nums[j];
                products.push_back(value);
            }
            return products;
        }
    
        
    }

//     Create two extra space, i.e. two extra arrays to store the product of all the array elements from start, up to that index and another array to store the product of all the array elements from the end of the array to that index. 
// To get the product excluding that index, multiply the prefix product up to index i-1 with the suffix product up to index i+1.

//best approach

// Create an array product and initialize its value to 1 and a variable temp = 1.
// Traverse the array from start to end.
// For every index i update product[i] as product[i] = temp and temp = temp * array[i], i.e store the product upto i-1 index from the start of array.
// initialize temp = 1 and traverse the array from last index to start.
// For every index i update product[i] as product[i] = product[i] * temp and temp = temp * array[i], i.e multiply with the product upto i+1 index from the end of array.
// Print the product array