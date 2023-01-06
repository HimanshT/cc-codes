// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

class Solution
{
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        map<int, int> umap;
        vector<int> ans;
        for (int i = 0; i < n1; i++)
        {
            if (umap[A[i]] < 1)
                umap[A[i]]++;
        }
        for (int j = 0; j < n2; j++)
        {
            if (umap[B[j]] == 1)
                umap[B[j]]++;
        }
        for (int k = 0; k < n3; k++)
        {
            if (umap[C[k]] == 2)
            {
                umap[C[k]]++;
                ans.push_back(C[k]);
            }
        }

        return ans;
    }

};