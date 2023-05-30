// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

int minFlips (string S)
{
	// your code here
	int ans1 = 0, ans2 = 0;
	//if i take 0 at even and 1 at odd
	for (int i = 0; i < S.length(); i++)
	{
		if (i % 2 == 0 and S[i] == '1') ans1++;
		if (i % 2 != 0 and S[i] == '0') ans1++;
	}
	for (int i = 0; i < S.length(); i++)
	{
		if (i % 2 == 0 and S[i] == '0') ans2++;
		if (i % 2 != 0 and S[i] == '1') ans2++;
	}
	return min(ans1, ans2);
}

