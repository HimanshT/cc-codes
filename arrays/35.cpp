// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

public:
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    sort(a.begin(), a.end());
    long long minDiff = pow(10, 9);
    for (long long i = 0; i <= n - m; i++)
    {
        long long first_index, first_value;
        long long second_index, second_value;
        first_index = i;
        second_index = i + m - 1;
        long long diff = a[second_index] - a[first_index];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;