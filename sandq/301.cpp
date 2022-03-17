// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        char arr[n+1];int top=-1;
        for(int i=0;i<n;i++)
        {
            if(x[i]=='[' || x[i]=='{' || x[i]=='(')
            {
                top++;
                arr[top]=x[i];
            }
            else if(top==-1)
            return false;
            else 
            {
                if(x[i]==']')
                {
                    if(arr[top]=='[')
                    top--;
                    else
                    return false;
                }
                else if(x[i]=='}')
                {
                    if(arr[top]=='{')
                    top--;
                    else
                    return false;
                }
                else if(x[i]==')')
                {
                    if(arr[top]=='(')
                    top--;
                    else
                    return false;
                }
            }
        }
        if(top==-1)
        return true;
        else
        return false;
    }