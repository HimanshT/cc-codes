// Given an integer K and a queue of integers, 
//we need to reverse the order of the first K elements of the queue,
// leaving the other elements in the same relative order.

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s1;queue<int> q2;
    int i=1;
    while(i<=k)
    {
        s1.push(q.front());
        q.pop();
        i++;
    }
    
    while(!q.empty())
    {
        q2.push(q.front());
        q.pop();
    }
    
    while(!s1.empty())
    {
        q.push(s1.top());
        s1.pop();
    }
    
    while(!q2.empty())
    {
        q.push(q2.front());
        q2.pop();
    }
    
    return q;
}

/*Create an empty stack.
One by one dequeue first K items from given queue and push the dequeued items to stack.
Enqueue the contents of stack at the back of the queue
Dequeue (size-k) elements from the front and enqueue them one by one to the same queue.*/