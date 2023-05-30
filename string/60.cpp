// Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

#include<bits/stdc++.h>
using namespace std;

bool rotation(string s3, string s2)
{
	return (s3.find(s2) != string::npos); //code to check the valid substring
}

int main()
{
	string s1 = "ABACD"; //check if s1 is a rotation of s2
	string s2 = "CDABA";
	string s3 = s1 + s1;
	cout << rotation(s3, s2);
	return 0;
}
