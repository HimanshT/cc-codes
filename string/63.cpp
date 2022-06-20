// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


//tle approach

bool palindrome(string test)
{
    string s1 = test;
    reverse(test.begin(), test.end());
    if (s1 == test)
        return true;
    return false;
}

string longestPalin (string S) {
    // code here
    int n = S.length();
    int maxLength = 0;
    int index = 0;
    string ans;
    for (int i = 0; i < n; i++)
    {
        string test;
        for (int j = i; j < n; j++)
        {
            test.push_back(S[j]);
            if (palindrome(test))
            {
                if (test.length() > maxLength)
                {
                    maxLength = test.length();
                    ans = test;
                }
            }
        }
    }
    return ans;
}

//better sol

string longestPalin (string S) {
    // code here
    int n = S.length();
    int matrix[n][n];
    string ans;
    if (n == 1)
        return S;
    if (n == 2)
    {
        if (S[0] == S[1])
            return S;
        else
        {
            ans.push_back(S[0]);
            return ans;
        }
    }
    //for n greater than 2
    int size = 1, first = 0, last = 0;
    for (int i = 0; i < n; i++)
        matrix[i][i] = 1;
    //filling for len = 2;
    int start = 0, end = start + 1;
    while (end < n)
    {
        if (S[start] == S[end])
        {
            matrix[start][end] = 1;
            if (end - start + 1 > size)
            {
                size = end - start + 1;
                first = start, last = end;
            }
        }
        else
            matrix[start][end] = 0;
        start++, end++;
    }
    //filling for len>2
    for (int dis = 2; dis < n; dis++)
    {

        end = start + dis;
        while (end < n)
        {
            if (S[start] == S[end] && matrix[start + 1][end - 1] == 1)
            {
                matrix[start][end] = 1;
                if (end - start + 1 > size)
                {
                    size = end - start + 1;
                    first = start, last = end;
                }
            }
            else
                matrix[start][end] = 0;
            start++, end++;
        }
    }

    for (int i = first; i <= last; i++)
        ans.push_back(S[i]);

    return ans;
}