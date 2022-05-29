// Given a sentence in the form of a string, convert it into its equivalent mobile numeric keypad sequence.


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ans(string str)
{
    string value = "";
    vector<string> v1 = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6",
                         "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"
                        };
    for (int i = 0; i < str.length(); i++)
    {
        string value1 = v1[str[i] - 65];
        value += value1;
    }
    cout << value;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string str;
        cin >> str;
        ans(str);
    }
    return 0;
}