//aggressive cows

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sol(int *arr,int n,int cows)
{
    sort(arr,arr+n);
    int low=1,high=arr[n-1];
    int ans=0;
    while(low<=high)
    {
        int mid=(high+low)/2;
        int placed_cows=1;
        int prev=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]-prev>=mid)
            {
                placed_cows++;
                prev=arr[i];
                if(placed_cows==cows)
                    break;
            }
        }
        if(placed_cows==cows)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    	int n,cows;
        cin>>n>>cows;
    	int arr[n];
    	for(int i=0;i<n;i++) cin>>arr[i];
    	//code
        cout<<sol(arr,n,cows);	
    }
	return 0;
}