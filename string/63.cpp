// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


//tle approach

 bool palindrome(string test)
    {
        string s1=test;
        reverse(test.begin(),test.end());
        if(s1==test)
        return true;
        return false;
    }
    
    string longestPalin (string S) {
        // code here
        int n=S.length();
        int maxLength=0;
        int index=0;
        string ans;
        for(int i=0;i<n;i++)
        {
            string test;
            for(int j=i;j<n;j++)
            {
                test.push_back(S[j]);
                if(palindrome(test))
                {
                    if(test.length()>maxLength)
                    {
                        maxLength=test.length();
                        ans=test;
                    }
                }
            }
        }
        return ans;
    }