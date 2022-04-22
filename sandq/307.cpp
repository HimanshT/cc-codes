// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

int evaluatePostfix(string S)
    {
        stack<int> s;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]!='+' && S[i]!='-' && S[i]!='*' && S[i]!='/')
            s.push((S[i]-'0'));
            else
            {
                int value1=s.top();
                s.pop();
                int value2=s.top();
                s.pop();
                int result;
                if(S[i]=='+')
                result = value2 + value1;
                else if(S[i]=='-')
                result = value2-value1;
                else if(S[i]=='*')
                result = value2*value1;
                else if(S[i]=='/')
                result = value2/value1;
                s.push(result);
            }
        }
        return s.top();
    }