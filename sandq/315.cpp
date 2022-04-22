// Stack using two queues 

void QueueStack :: push(int x)
{
     if(q1.empty())
     q1.emplace(x);
     else
     {
         while(!q1.empty())
         {
             q2.emplace(q1.front());
             q1.pop();
         }
         q1.emplace(x);
         while(!q2.empty())
         {
             q1.emplace(q2.front());
             q2.pop();
         }
     }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
 if(q1.empty())
 return -1;
 else
 {
     int ans=q1.front();
     q1.pop();
     return ans;
 }
}