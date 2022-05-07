// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.


void reverseString(vector<char>& s) {
        int len=s.size();
        int i=0,j=len-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++,j--;
        }
    }