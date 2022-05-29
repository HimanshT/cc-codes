// Rabin - Karp algo

#include<bits/stdc++.h>
using namespace std;
#define d 256

void search(string pat, string txt, int q)
{
	int M = pat.length();
	int N = txt.length();
	int i, j;
	int p = 0; //hash value of pattern
	int t = 0; //hash value of text
	int h = 1; //

	//The value of h is pow(d,M-1)%q;
	for (int i = 1; i <= M - 1; i++)
		h = (h * d) % q;

	//calculating the hash value of pattern and text
	for (int i = 0; i < M; i++)
	{
		p = (p * d + pat[i]) % q;
		t = (t * d + txt[i]) % q;
	}

	//sliding the pattern on txt one by one
	for (int i = 0; i <= N - M; ++i) // N-M because this is the max distance upto you can look for
		//a certain length of pattern
	{
		if (p == t)
		{
			bool flag = true;
			for (j = 0; j < M; j++) //only length of pattern we have to look
			{
				if (txt[i + j] != pat[j])
				{
					flag = false;
					break;
				}
				if (flag)
					cout << i << " ";
			}
			if (j == M)
				cout << "pattern found at index " << i << "\n";
		}

		//changing the hash value for next pattern
		if (i < N - M) //bcz if i = N-M then your loop should be over
		{
			t = ((t - txt[i] * h) * d + txt[i + M]) % q;

			//since this t can be neg
			if (t < 0)
				t = t + q;
		}

	}

}


int main()
{
	string txt = "GEEKS FOR GEEKS";
	string pat = "GEEK";

	// A prime number
	int q = 101;

	// Function Call
	search(pat, txt, q);
	return 0;
}