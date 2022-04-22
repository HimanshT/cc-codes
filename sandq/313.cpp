int findMaxLen(string s) {
        int len=s.length();
        stack<int> store;
        store.push(-1);
        int result=0;
        int curr_len=0;
        int i=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            store.push(i);
            else if(s[i]==')')
            {
                if(!store.empty())
                store.pop();
                if(!store.empty())
                {
                    curr_len=i-store.top();
                    result=max(curr_len,result);
                }
                else
                {
                    store.push(i);
                }
            }
            result=max(curr_len,result);
        }
        return result;