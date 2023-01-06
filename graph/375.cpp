// Total Number Of Spanning Trees In A Graph -- Completely connected Npow(N-2)
//issue is when it is not complete graph

class Solution {
public:
	int findDeterminant(vector<vector<int>>&Matrix) {
		// Variable to store the determinant value
		int det = 0;
		if (Matrix.size() == 1)
		{
			return Matrix[0][0];
		}

		else if (Matrix.size() == 2)
		{
			det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
			return det;
		}

		else
		{

			for (int p = 0; p < Matrix[0].size(); p++)
			{
				vector<vector<int>> tempMatrix;
				for (int i = 1; i < Matrix.size(); i++)
				{
					vector<int> row;
					for (int j = 0; j < Matrix[i].size(); j++)
					{
						if (j != p)
						{
							row.push_back(Matrix[i][j]);
						}

					}

					if (row.size() > 0)
					{
						tempMatrix.push_back(row);
					}

				}

				det = det + Matrix[0][p] * pow(-1, p) * findDeterminant(tempMatrix);

			}

			return det;
		}

	}
	int countSpanningTrees(vector<vector<int>>&graph, int m, int n) {
		//create a matrix
		vector<vector<int>> matrix(m, vector<int>(m, 0));
		for (int i = 0; i < graph.size(); i++)
		{
			matrix[graph[i][0]][graph[i][1]] = 1;
			matrix[graph[i][1]][graph[i][0]] = 1;
		}
		//make all diagonal elements equal to indegree
		for (int i = 0; i < m; i++)
		{
			int count = 0;
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 1)
					count++;
			}
			matrix[i][i] = count;
		}
		//   //make all non-diagonal 1 to -1
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == j)
					continue;
				else if (matrix[i][j] == 1)
					matrix[i][j] = -1;
			}
		}
		//find the cofactor of any index basically (0,0);
		vector<vector<int>> submatrix(m - 1, vector<int>(m - 1, 0));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < m; j++)
				submatrix[i - 1][j - 1] = matrix[i][j];
		}

		return findDeterminant(submatrix);
		// return 5;
	}
};

