// Merge k Sorted Arrays

struct MinHeapNode
{
	int element;
	int i;//index of the array from which the element is taken
	int j;//index of the next element to be picked;
};

class MinHeap
{
	MinHeapNode *harr;
	int heap_size;
public:
	MinHeap(MinHeapNode a[], int size); //create a min heap of given value
	void MinHeapify(int );
	int left(int i) {return (2 * i + 1);}
	int right(int i) {return (2 * i + 2);}
	MinHeapNode getMin() {return harr[0];}
	void replaceMin(MinHeapNode x) {harr[0] = x; MinHeapify(0);}
};

MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a;
	int i = (heap_size / 2) - 1;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}

//swap fn

void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[smallest].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

class Solution
{
public:
	//Function to merge k sorted arrays.
	vector<int> mergeKArrays(vector<vector<int>> arr, int k)
	{
		vector<int> output;
		int n = arr.size();
		MinHeapNode *harr = new MinHeapNode[k];
		for (int i = 0; i < k; i++)
		{
			harr[i].element = arr[i][0];
			harr[i].i = i;
			harr[i].j = 1;
		}
		//create min_heap;
		MinHeap hp(harr, k);
		for (int count = 0; count < (k * k); count++)
		{
			MinHeapNode root = hp.getMin();
			output.push_back(root.element);
			if (root.j < n)
			{
				root.element = arr[root.i][root.j];
				root.j += 1;
			}
			else
				root.element = INT_MAX;
			hp.replaceMin(root);
		}
		return output;
	}
};



// Merge k Sorted Arrays

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
	vector<int> ans;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			ans.push_back(arr[i][j]);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

//better solution
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
	priority_queue<int> pq;
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			pq.push(arr[i][j]);
	vector<int> ans;
	while (!pq.empty()) {
		ans.push_back(pq.top()); pq.pop();
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}