// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.


queue<int> rev(queue<int> q)
{
   stack<int> s1;
   while(!q.empty())
   {
       s1.push(q.front());
       q.pop();
   }
   
   while(!s1.empty())
   {
       q.push(s1.top());
       s1.pop();
   }
   
   return q;
}


//using recursion--tle

queue<int> rev(queue<int> q)
{
    if(q.empty())
    return q;
    else
    {
        int s=q.front();
        q.pop();
        q=rev(q);
        q.push(s);
        return q;
    }
}