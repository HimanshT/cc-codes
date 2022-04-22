long long getMaxArea(long long arr[], int n)
    {
        stack<long long> s;
        long long max_area=0;
        long long i=0;
        while(i<n)
        {
            if(s.empty() or arr[s.top()]<=arr[i])
            s.push(i++);
            else
            {
                long long tp=s.top();
                s.pop();
                long long area = arr[tp]*(s.empty()?i:i-s.top()-1);
                max_area = max(max_area,area);
            }
        }
        
        while(!s.empty())
        {
            long long tp=s.top();
            s.pop();
            long long area=arr[tp]*(s.empty()?i:i-s.top()-1);
            max_area=max(max_area,area);
        }
        return max_area;
    }