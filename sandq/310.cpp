// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

void SortedStack :: sort()
{
   //Your code here
   int n = s.size();
   vector<int> v1;
   for(int i=0;i<n;i++)
   {
       v1.push_back(s.top());
       s.pop();
   }
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<(n-1);j++)
       {
           if(v1[j+1]<v1[j])
           swap(v1[j+1],v1[j]);
       }
   }
   
   for(int i=0;i<n;i++)
   s.push(v1[i]);
}

//the other concept is using linked list and therefore storing the stack values in a variable temp and after the stack is empty 
// just comparing and putting the values before and after each other
// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty.
// When the stack becomes empty, insert all held items one by one in sorted order. Here sorted order is important.