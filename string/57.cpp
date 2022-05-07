// Given a string S, check if it is palindrome or not.

int isPalindrome(string S)
	{
	    int len=S.length();
	    int i=0,j=len-1;
	    while(i<=j)
	    {
	        if(S[i]!=S[j])
	        return 0;
	        i++,j--;
	    }
	    return 1;
	}