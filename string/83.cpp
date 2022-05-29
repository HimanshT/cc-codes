// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

int compare(string str, int *arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != (str[i] - 48))
			count++;
	}
	return count;
}

int minFlips (string S)
{
	// your code here
	int n = S.length();
	int arr1[n], arr2[n];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			arr1[i] = 0;
			arr2[i] = 1;
		}
		else
		{
			arr1[i] = 1;
			arr2[i] = 0;
		}
	}

	return min(compare(S, arr1, n), compare(S, arr2, n));
}

//the other method without wasting memory would be to consider it can either start with 1 and zero
//so consider one case where it starts with one and other case where it starts with zero.
//case 1: starts with zero--->flip 0-1-0 and check the change
//case 2: one-> flip 1-0-1 and change