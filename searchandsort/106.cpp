// Given a set of points as and a line as ax+by+c = 0. We need to find a point on given line for which sum of distances from given set of points is minimum. 

#include <bits/stdc++.h>
using namespace std;
#define long long ll;

double result(double arr[][2],double n,double a,double b,double c)
{
	double sumx=0;
	for(int i=0;i<n;i++)
		sumx += arr[i][0];
	double sumy=0;
	for(int i=0;i<n;i++)
		sumy+= arr[i][1];
	double x = (sumx - ((c*a*n)/b) - (a/b)*sumy/(n*(1+(pow(a,2)/pow(b,2)))));
		return x;
}

double value(double x1,double y1,double x,double y)
{
	return sqrt(pow((x1-x),2) + pow((y1-y),x));
}

double distance(double arr[][2],double row,double col,double x,double y)
{
	double ans=0;
	for(int i=0;i<row;i++)
		ans = ans + value(arr[i][0],arr[i][1],x,y);
	return ans;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		double a,b,c; //ax+by+c=0;
		a=1,b=-1,c=-3;
		double arr[][2]={{-3,2},{-1,0},{-1,2},{1,2},{3,4}};
		double x,y;
		double n=5;
		x=result(arr,n,a,b,c);
		y=0-(a*x + c)/b;
		cout<<distance(arr,n,2,x,y)<<endl;
	}
	return 0;
}
