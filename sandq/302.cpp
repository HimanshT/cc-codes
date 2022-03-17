// You are given a string S, the task is to reverse the string using stack.

char* reverse(char *S, int len)
{
    //code here
    char *str=(char *)malloc(sizeof(char)*(len+1));
    int top=-1;
    for(int i=0;i<len;i++)
    {
        top++;
        str[top]=S[i];
    }
    
    int j=0;
    while(top!=-1)
    {
        S[j]=str[top];
        top--;j++;
    }
    return S;
}