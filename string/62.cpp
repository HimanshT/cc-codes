// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

 string countAndSay(int n) {
        string ans="";
        if(n==1)
        {
            ans=ans+to_string(1);
            return ans;
        }
        string prev=countAndSay(n-1);
        int len=prev.length();
        char base=prev[0];
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(prev[i]==base)
                count++;
            else
            {
                ans+=to_string(count);
                ans.push_back(base);
                base=prev[i];
                count=1;
            }
        }
        ans+=to_string(count);
                ans.push_back(base);
        return ans;
    }