// Check if a string is a valid shuffle of two other strings

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

bool result(string s1,string s2,string s3)
{
	string combined=s1+s2;
	if(combined.length()!=s3.length())
		return false;
	sort(combined.begin(),combined.end());
	sort(s3.begin(),s3.end());
	// cout<<combined<<" "<<s3<<endl;
	if(combined==s3)
		return true;
	else
		return false;

}

int main()
{
    string str1="XY";
    string str2="12";
    string str3="1XY2";
    cout<<result(str1,str2,str3);
	return 0;
}