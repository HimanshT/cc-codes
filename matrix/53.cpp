// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

#include<bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{
	unordered_map<int,int> umap;
	for(int col=0;col<N;col++)
		umap[mat[0][col]]=1;
	for(int row=1;row<M;row++)
	{
		for(int col=0;col<N;col++)
		{
			int key=mat[row][col];
			if(umap.find(key)!=umap.end())
			{
				umap[key]=row+1;
			}
		}
	}

	unordered_map<int,int>::iterator itr;
	for(itr=umap.begin();itr!=umap.end();itr++)
	{
		if(itr->second==M)
			cout<<itr->first<<endl;
	}
}

int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}