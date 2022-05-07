// Rotate a matrix by 90 degree in clockwise direction without using any extra space

#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> matrix,int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({1,2,3});matrix.push_back({4,5,6});matrix.push_back({7,8,9});
    int row=3,col=3;
    //transpose the complete matrix
    for(int i=0;i<row;i++)
    {
        for(int j=i;j<col;j++)
            swap(matrix[i][j],matrix[j][i]);
    }
    
    //rotate the cols with equal distance
    int left=0,right=col-1;
    while(left<right)
    {
    	for(int i=0;i<row;i++)
    	{
    		swap(matrix[i][left],matrix[i][right]);
    	}
    	left++,right--;
    }
    display(matrix,row,col);
	return 0;
}