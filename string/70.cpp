// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers.
// If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order.
// You are given an list of numbers arr[ ] of size N.

vector<int> nextPermutation(int N, vector<int> arr) {
	// step1: find the last increasing subarray and get the index of element just below max
	//find the element just greater than index element and swap
	//sort the array from index+1 to last
	int index1 = -1, index2;
	for (int i = N - 1; i > 0; i--)
	{
		if (arr[i] > arr[i - 1])
		{
			index1 = i - 1;
			break;
		}
	}
	//if the array was decreasing
	if (index1 == -1)
	{
		sort(arr.begin(), arr.end());
		return arr;
	}
	// finding the second index
	index2 = index1 + 1;
	for (int i = index1 + 1; i < N; i++)
	{
		if (arr[i] > arr[index1] && arr[i] <= arr[index2])
			index2 = i;
	}
	//swap
	swap(arr[index1], arr[index2]);
	//sort
	vector<int> temp;
	for (int i = index1 + 1; i < N; i++)
		temp.push_back(arr[i]);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++)
	{
		arr[index1 + 1] = temp[i];
		index1++;
	}
	return arr;
}