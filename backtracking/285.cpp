// Find shortest safe route in a path with landmines

//Approach

// 1.Similar to rat in a maze problem
// 2.first of all find out all the 0 places
// 3. mark all the adjacent's of 0 as 0;
// 4. Go for rat in a maze,where rat can move top,right,bottom

#include<bits/stdc++.h>
using namespace std;
int R = 12;
int C = 10;

void fn(int mat[R][C])
{
	vector<pair<int, int>> v1;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; i < C; j++)
		{
			if (mat[i][j] == 0)
				v1.push_back({i, j});
		}
	}

	for (auto it : v1) //i+1,i-1,j+1,j-1
	{
		if (it.first - 1 >= 0)
			mat[it.first - 1][it.second] = 0;
		if (it.first + 1 < R)
			mat[it.first + 1][it.second] = 0;
		if (it.second - 1 >= 0)
			mat[it.first][it.second - 1] = 0;
		if (it.second + 1 > C)
			mat[it.first][it.second + 1] = 0;
	}
}


int main()
{
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};
	// find shortest path
	fn(mat);
	// bool ans = findShortestPath(mat);
	for (int i = 0; i < R; ++i)
	{
		for (int i = 0; i < C; ++i)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}