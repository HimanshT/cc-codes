int lomito(int *arr, int low, int high) //[2,6,1,23,18,10,15] --- [2,6,1,10,18,23,15];
{
	int pivot = arr[high];
	int count = -1;
	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] < pivot)
		{
			count++;
			swap(arr[count], arr[i]);
		}
	}
	swap(arr[count + 1], arr[high]);
	return count + 1;
}

int hoare(int *arr, int low, int high)
{
	int pivot = arr[low];
	int i = low;
	int j = high + 1;
	while (1)
	{
		do {i++;} while (arr[low] < pivot);
		do {j--;}  while (arr[high] >= pivot);
		if (i >= j)
			break;
		swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	return j;
}