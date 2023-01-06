// You are given a string s consisting only of lowercase English letters.

// In one move, you can select any two adjacent characters of s and swap them.

// Return the minimum number of moves needed to make s a palindrome.

// Note that the input will be generated such that s can always be converted to a palindrome.



class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		int move = 0;
		int left = 0, right = s.length() - 1;
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++, right--;
			} else {
				int ptr = right;
				while (s[ptr] != s[left])
					ptr--;
				if (left == ptr)
				{
					swap(s[ptr], s[ptr + 1]);
					move++;
					continue;
				} else
				{
					while (ptr + 1 <= right)
					{
						swap(s[ptr], s[ptr + 1]);
						move++;
						ptr++;
					}
				}
			}
		}
		return move;
	}
};