// Find pivot element in a sorted and rotated array

#include <bits/stdc++.h>
using namespace std;

// int binarySearch(int *arr,int low,int high,int lb,int ub)
// {
// 	int mid=(high+low)/2;
// 	if(arr[mid]==lb)
// 	{
// 		if(arr[mid]==ub)
// 			return mid;
// 		else if(arr[mid]>=arr[mid+1])
// 			return mid;
// 	}
// 	else if(arr[mid]==ub)
// 	{
// 		if(arr[mid]>=arr[mid-1])
// 			return mid;
// 	}
// 	else
// 	{
// 		if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1])
// 			return mid;
// 		else if(arr[mid]>arr[high])
// 			return binarySearch(arr,mid+1,high,lb,ub);
// 		else if(arr[mid]<arr[high])
// 			return binarySearch(arr,low,mid-1,lb,ub);
// 	}
// 	return -1;
// }
//better approach

int binarySearch(int *arr,int low,int high)
{
	if(low<=high)
	{
		int mid=(high+low)/2;
		if(arr[mid]>arr[mid+1])
			return (mid+1);
		else if(arr[mid]>arr[low])
			return binarySearch(arr,mid+1,high);
		else
			return binarySearch(arr,low,mid-1);
	}
	return -1;
}

int main()
{
	int arr[]={123,789,896,2315,0,52,78,96}; //0,52,78,96,|123,789,896,2315
	if(arr[0]<arr[7])
		cout<<"0";
	else
	cout<<binarySearch(arr,0,7);
}



//first approach --- O(n) ---find the  largest element will be pivot element;
//second approach --- log(n)--using binary search
// The number of times the array is rotated would be (IndexOfPivotReturned + 1).